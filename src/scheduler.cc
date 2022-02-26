#include "scheduler.h"
#include "hook.h"
#include "log.h"
#include "util.h"

namespace miruy {

static thread_local Scheduler* t_scheduler = nullptr;

Scheduler* Scheduler::GetThis()
{
    return t_scheduler;
}

Scheduler::Scheduler(uint32_t ths_count, const std::string& name)
    : m_name(name), m_threadCount(ths_count)
{
    if (m_name.empty())
        m_name = Thread::GetName();
}

Scheduler::~Scheduler()
{
    ASSERT(!m_running);
    if (GetThis() == this) {
        t_scheduler = nullptr;
    }
}

void Scheduler::start()
{
    MutexType::Lock lock(m_mutex);
    if (m_running)
        return;

    m_running = true;
    ASSERT(m_threads.empty());

    m_threads.resize(m_threadCount);
    for (size_t i = 0; i < m_threadCount; ++i) {
        m_threads[i].reset(
            new Thread(std::bind(&Scheduler::run, this), m_name + "-" + std::to_string(i + 1)));
        m_tids.push_back(m_threads[i]->getId());
    }
}

void Scheduler::stop()
{
    if (stopped())
        return;

    m_running = false;
    for (size_t i = 0; i < m_threadCount; ++i)
        tickle();

    std::vector<Thread::ptr> ths;
    {
        MutexType::Lock lock(m_mutex);
        ths.swap(m_threads);
    }

    for (auto& i : ths)
        i->join();
    m_threadCount = 0;
}

bool Scheduler::hasIdelThread() const
{
    return m_idleThreadCount > 0;
}

void Scheduler::run()
{
    set_hook_enable(true);
    t_scheduler = this;
    Fiber::ptr idle_fiber(new Fiber(std::bind(&Scheduler::idle, this)));
    Fiber::ptr cb_fiber;
    FiberAndFunc ff;

    while (true) {
        ff.reset();
        bool tickle_me = false;
        bool is_active = false;
        {
            MutexType::Lock lock(m_mutex);
            if (!m_tasks.empty()) {
                auto it = m_tasks.begin();
                while (it != m_tasks.end()) {
                    ASSERT(it->fiber || it->cb);
                    if (it->fiber && it->fiber->getState() == State::EXEC) {
                        ++it;
                        continue;
                    }

                    ff = *it;
                    m_tasks.erase(it);
                    ++m_activeThreadCount;
                    is_active = true;
                    break;
                }
                tickle_me = it != m_tasks.end();
            }
        }

        if (tickle_me) {
            tickle();
        }

        if (ff.fiber &&
            (ff.fiber->getState() != State::TERM && ff.fiber->getState() != State::EXCPT)) {
            ff.fiber->swapIn();
            --m_activeThreadCount;
            if (ff.fiber->getState() == State::READY)
                schedule(ff.fiber);
        } else if (ff.cb) {
            if (cb_fiber)
                cb_fiber->reset(ff.cb);
            else
                cb_fiber.reset(new Fiber(ff.cb));

            cb_fiber->swapIn();
            --m_activeThreadCount;

            switch (cb_fiber->getState()) {
                case State::READY: {
                    schedule(cb_fiber);
                    cb_fiber.reset();
                    break;
                }
                case State::TERM:
                case State::EXCPT: {
                    cb_fiber->reset(nullptr);
                    break;
                }
                default: cb_fiber.reset();
            }
        } else {
            if (is_active) {
                --m_activeThreadCount;
                continue;
            }

            if (idle_fiber->getState() == State::TERM) {
                // LOG_INFO(LOGGER("system")) << "idel fiber " << idle_fiber->getId() << " termed";
                break;
            }
            ++m_idleThreadCount;
            idle_fiber->swapIn();
            --m_idleThreadCount;
        }
    }

}

bool Scheduler::stopped()
{
    MutexType::Lock lock(m_mutex);
    return !m_running && m_tasks.empty() && m_activeThreadCount == 0;
}

void Scheduler::tickle()
{
    // LOG_INFO(LOGGER("system")) << "tickle";
}
void Scheduler::idle()
{
    while (!stopped()) {
        Fiber::YieldToHold();
    }
}

}  // namespace miruy