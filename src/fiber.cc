#include <atomic>
#include <stdexcept>
#include <stack>
#include <sstream>
#include "fiber.h"
#include "log.h"
#include "util.h"

namespace miruy {

    static std::atomic<uint64_t> s_fiber_id{0};
    static std::atomic<uint64_t> s_fiber_count{0};

    static thread_local Fiber* t_fiber = nullptr;
    static thread_local Fiber::ptr t_main_fiber = nullptr;
    static thread_local std::stack<ucontext_t> t_ctx_stack;

    int InitAndMakeContext(ucontext_t* ctx,
                           void* stack_p,
                           size_t stack_size,
                           void (*cb)(),
                           ucontext_t* ctx_ret = nullptr)
    {
        if (getcontext(ctx))
            return -1;
        ctx->uc_stack.ss_size = stack_size;
        ctx->uc_stack.ss_sp = stack_p;
        ctx->uc_link = ctx_ret;
        makecontext(ctx, cb, 0);
        return 0;
    }

    class StackAllocator
    {
    public:
        static void* Alloc(size_t size) { return malloc(size); }
        static void Dealloc(void* vp) { free(vp); }
    };

    Fiber::Fiber() : m_state(State::EXEC), m_id(s_fiber_id++)
    {
        if (getcontext(&m_ctx)) {
            LOG_ERROR(LOGGER("system"), "Fiber::Fiber(): getcontext error");
            throw std::logic_error("getcontext error");
        }
        SetThis(this);
        ++s_fiber_count;
    }

    Fiber::Fiber(std::function<void()> callback, size_t stacksize)
        : m_cb(callback), m_id(s_fiber_id++)
    {
        if (!t_fiber) {
            t_main_fiber.reset(new Fiber);
            ASSERT(t_main_fiber.get() == t_fiber);
        }

        m_stacksize = stacksize ? stacksize : MIRUY_STACK_SIZE;
        m_stack = StackAllocator::Alloc(m_stacksize);

        if (InitAndMakeContext(&m_ctx, m_stack, m_stacksize, MainFunc)) {
            StackAllocator::Dealloc(m_stack);
            LOG_ERROR(LOGGER("system"), "Fiber::Fiber(): getcontext error");
            throw std::logic_error("getcontext error");
        }
        ++s_fiber_count;
    }

    Fiber::~Fiber()
    {
        if (m_stack) {
            ASSERT(m_state == State::INIT || m_state == State::TERM ||
                   m_state == State::EXCPT);
            StackAllocator::Dealloc(m_stack);
            // LOG_INFO(LOGGER("system"), "Fiber::~Fiber() id = " +
            // std::to_string(m_id));
        } else {
            ASSERT(!m_cb);
            ASSERT(m_state == State::EXEC);
            if (this == t_fiber) {
                Fiber::SetThis(nullptr);
            }
        }
        --s_fiber_count;
    }

    void Fiber::reset(std::function<void()> callback)
    {
        if (!m_stack)
            return;
        ASSERT(m_state == State::INIT || m_state == State::TERM ||
               m_state == State::EXCPT);
        m_cb.swap(callback);
        m_state = State::INIT;
        if (InitAndMakeContext(&m_ctx, m_stack, m_stacksize, MainFunc)) {
            m_state = State::EXCPT;
            LOG_ERROR(LOGGER("system"), "Fiber::reset(): getcontext error");
            throw std::logic_error("getcontext error");
        }
    }

    Fiber::ptr Fiber::holdToRead()
    {
        m_state = m_state == State::HOLD ? State::READY : m_state;
        return shared_from_this();
    }

    void Fiber::swapIn()
    {
        if (m_state == State::TERM || m_state == State::EXCPT) {
            LOG_ERROR(LOGGER("system"), "Fiber::swapIn(): state = TERM/EXCPT")
            return;
        }
        SetThis(this);
        m_state = State::EXEC;
        if (swapcontext(&t_main_fiber->m_ctx, &m_ctx)) {
            m_state = State::EXCPT;
            LOG_ERROR(LOGGER("system"), "Fiber::swapIn(): swapcontext error");
        }
    }

    void Fiber::swapOut()
    {
        SetThis(t_main_fiber.get());
        if (swapcontext(&m_ctx, &t_main_fiber->m_ctx)) {
            m_state = State::EXCPT;
            LOG_ERROR(LOGGER("system"), "Fiber::swapOut(): swapcontext error");
            throw std::logic_error("swapcontext error");
        }
    }

    void Fiber::SetThis(Fiber* fiber) { t_fiber = fiber; }

    Fiber::ptr Fiber::GetThis()
    {
        if (!t_fiber) {
            t_main_fiber = Fiber::ptr(new Fiber);
            ASSERT(t_fiber == t_main_fiber.get());
        }
        return t_fiber->shared_from_this();
    }

    void Fiber::YieldToRead()
    {
        Fiber::ptr cur = GetThis();
        if (cur->m_stack) {
            cur->m_state = State::READY;
            cur->swapOut();
        }
    }

    void Fiber::YieldToHold()
    {
        Fiber::ptr cur = GetThis();
        if (cur->m_stack) {
            cur->m_state = State::HOLD;
            cur->swapOut();
        }
    }

    void Fiber::MainFunc()
    {
        Fiber::ptr cur = GetThis();
        try {
            cur->m_cb();
            cur->m_cb = nullptr;
            cur->m_state = State::TERM;
        } catch (std::exception& e) {
            cur->m_state = State::EXCPT;
            std::stringstream ss;
            ss << "Fiber::MainFunc() " << e.what();
            LOG_ERROR(LOGGER("system"), ss.str());
        } catch (...) {
            cur->m_state = State::EXCPT;
            LOG_ERROR(LOGGER("system"), "Fiber::MainFunc() ");
        }
        auto ptr = cur.get();
        cur.reset();
        ptr->swapOut();
    }

    uint64_t Fiber::TotalFibers() { return s_fiber_count; }

    uint64_t Fiber::GetId() { return t_fiber ? t_fiber->getId() : 0; }

}  // namespace miruy