#include <atomic>
#include <stdexcept>
#include <stack>
#include "fiber.h"
#include "log.h"
#include "config.h"
#include "util.h"

namespace miruy {

static std::atomic<uint64_t> s_fiber_id{ 0 };
static std::atomic<uint64_t> s_fiber_count{ 0 };

static thread_local Fiber* t_fiber = nullptr;
static thread_local std::shared_ptr<std::stack<std::pair<ucontext_t*, Fiber*>>> t_ctx_stack;
static thread_local ucontext_t t_main_ctx;

static uint64_t t_fiber_stack_size{ 0 };

static ConfigVar<uint64_t>::ptr g_fiber_stack_size =
    Config::Lookup<uint64_t>("fiber.stack_size", 1024 * 1024, "fiber stack size");

struct _FiberStackSizeIniter {
    _FiberStackSizeIniter()
    {
        t_fiber_stack_size = g_fiber_stack_size->getValue();
        g_fiber_stack_size->addListener(
            [](const uint64_t& ov, const uint64_t& nv) { t_fiber_stack_size = nv; });
    }
};

static _FiberStackSizeIniter _fssi;

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

Fiber::Fiber(std::function<void()> callback, size_t stacksize)
    : m_state(State::INIT), m_cb(callback)
{
    if (!t_ctx_stack) {
        t_ctx_stack.reset(new std::stack<std::pair<ucontext_t*, Fiber*>>);
    }

    m_stacksize = stacksize ? stacksize : t_fiber_stack_size;
    m_stack = StackAllocator::Alloc(m_stacksize);

    if (InitAndMakeContext(&m_ctx, m_stack, m_stacksize, MainFunc)) {
        StackAllocator::Dealloc(m_stack);
        LOG_ERROR(LOGGER("system")) << "Fiber::Fiber(): getcontext error";
        throw std::logic_error("getcontext error");
    }
    ++s_fiber_count;
    m_id = ++s_fiber_id;
}

Fiber::~Fiber()
{
    ASSERT(m_state == State::INIT || m_state == State::TERM || m_state == State::EXCPT);
    StackAllocator::Dealloc(m_stack);
    --s_fiber_count;
}

void Fiber::reset(std::function<void()> callback)
{
    if (!m_stack)
        return;
    ASSERT(m_state == State::INIT || m_state == State::TERM || m_state == State::EXCPT);
    m_cb.swap(callback);
    m_state = State::INIT;
    if (InitAndMakeContext(&m_ctx, m_stack, m_stacksize, MainFunc)) {
        m_state = State::EXCPT;
        LOG_ERROR(LOGGER("system")) << "Fiber::reset(): getcontext error";
        throw std::logic_error("getcontext error");
    }
}

// Fiber::ptr Fiber::holdToRead()
// {
//     m_state = m_state == State::HOLD ? State::READY : m_state;
//     return shared_from_this();
// }

void Fiber::swapIn()
{
    if (m_state == State::TERM) {
        LOG_WARN(LOGGER("system")) << "fiber id=" << m_id << " already finished";
        return;
    }

    if (m_state == State::EXCPT) {
        LOG_ERROR(LOGGER("system")) << "fiber id=" << m_id << " occurred error";
        return;
    }

    if (t_ctx_stack->empty())
        t_ctx_stack->push(std::make_pair(&t_main_ctx, nullptr));

    m_state = State::EXEC;
    t_fiber = this;
    ucontext_t* old = t_ctx_stack->top().first;
    t_ctx_stack->push(std::make_pair(&m_ctx, this));
    if (swapcontext(old, &m_ctx)) {
        m_state = State::EXCPT;
        LOG_ERROR(LOGGER("system")) << "Fiber::swapIn(): swapcontext error";
    }
}

void Fiber::swapOut()
{
    t_ctx_stack->pop();
    t_fiber = t_ctx_stack->top().second;
    if (swapcontext(&m_ctx, t_ctx_stack->top().first)) {
        m_state = State::EXCPT;
        LOG_ERROR(LOGGER("system")) << "Fiber::swapOut(): swapcontext error";
        throw std::logic_error("swapcontext error");
    }
}

Fiber::ptr Fiber::GetThis()
{
    return t_fiber ? t_fiber->shared_from_this() : nullptr;
}

void Fiber::YieldToRead()
{
    if (!t_ctx_stack || t_ctx_stack->size() <= 1) {
        LOG_WARN(LOGGER("system")) << "the context is not in fiber";
        return;
    }
    Fiber* cur = t_ctx_stack->top().second;
    if (cur) {
        cur->m_state = State::READY;
        cur->swapOut();
    }
}

void Fiber::YieldToHold()
{
    if (!t_ctx_stack || t_ctx_stack->size() <= 1) {
        LOG_WARN(LOGGER("system")) << "the context is not in fiber";
        return;
    }
    Fiber* cur = t_ctx_stack->top().second;
    if (cur) {
        cur->m_state = State::HOLD;
        cur->swapOut();
    }
}

void Fiber::MainFunc()
{
    auto cur = GetThis();
    ASSERT(cur);
    try {
        cur->m_cb();
        cur->m_cb = nullptr;
        cur->m_state = State::TERM;
    } catch (std::exception& e) {
        cur->m_state = State::EXCPT;
        LOG_ERROR(LOGGER("system")) << "Fiber::MainFunc() " << e.what();
    } catch (...) {
        cur->m_state = State::EXCPT;
        LOG_ERROR(LOGGER("system")) << "Fiber::MainFunc()";
    }
    auto tmp = cur.get();
    cur.reset();
    tmp->swapOut();
}

uint64_t Fiber::TotalFibers()
{
    return s_fiber_count;
}

uint64_t Fiber::GetId()
{
    return t_fiber ? t_fiber->getId() : 0;
}

}  // namespace miruy