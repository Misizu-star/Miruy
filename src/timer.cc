#include "timer.h"
#include "util.h"

namespace miruy {

    bool Timer::Comparator::operator()(const Timer::ptr lhs, const Timer::ptr rhs)
    {
        if (!lhs && !rhs)
            return false;
        if (!lhs)
            return true;
        if (!rhs)
            return false;
        if (lhs->m_next < rhs->m_next)
            return true;
        if (rhs->m_next < lhs->m_next)
            return false;
        return lhs.get() < rhs.get();
    }

    Timer::Timer(uint64_t ms, std::function<void()> cb, bool loop, TimerManager* manager)
        : m_ms(ms), m_cb(cb), m_loop(loop), m_manager(manager)
    {
        m_next = GetCurrentMS() + m_ms;
    }

    Timer::Timer(uint64_t next) : m_next(next) {}

    bool Timer::cancel()
    {
        TimerManager::RWMutexType::WriteLock lock(m_manager->m_mutex);
        if (!m_cb)
            return false;

        m_cb = nullptr;
        auto it = m_manager->m_timers.find(shared_from_this());
        m_manager->m_timers.erase(it);
        return true;
    }

    bool Timer::refresh()
    {
        TimerManager::RWMutexType::WriteLock lock(m_manager->m_mutex);
        if (!m_cb)
            return false;

        Timer::ptr self = shared_from_this();
        auto it = m_manager->m_timers.find(self);
        if (it == m_manager->m_timers.end())
            return false;

        m_manager->m_timers.erase(it);
        m_next = GetCurrentMS() + m_ms;
        m_manager->m_timers.insert(self);
        return true;
    }

    bool Timer::reset(uint64_t ms, bool from_now)
    {
        if (ms == m_ms && !from_now)
            return false;

        TimerManager::RWMutexType::WriteLock lock(m_manager->m_mutex);
        if (!m_cb)
            return false;

        Timer::ptr self = shared_from_this();
        auto it = m_manager->m_timers.find(self);
        if (it == m_manager->m_timers.end())
            return false;

        m_manager->m_timers.erase(it);
        m_next = from_now ? (GetCurrentMS() + ms) : (m_next - m_ms + ms);
        m_ms = ms;
        m_manager->addTimer(self, lock);
        return true;
    }

    TimerManager::TimerManager() {}

    TimerManager::~TimerManager() {}

    Timer::ptr TimerManager::addTimer(time_t ms, std::function<void()> cb, bool loop)
    {
        Timer::ptr timer(new Timer(ms, cb, loop, this));
        RWMutexType::WriteLock lock(m_mutex);
        addTimer(timer, lock);
        return timer;
    }

    static void OnTimer(std::weak_ptr<void> weak_cond, std::function<void()> cb)
    {
        std::shared_ptr<void> tmp = weak_cond.lock();
        if (tmp)
            cb();
    }

    Timer::ptr TimerManager::addConditionTimer(time_t ms,
                                               std::function<void()> cb,
                                               std::weak_ptr<void> weak_cond,
                                               bool loop)
    {
        return addTimer(ms, std::bind(&OnTimer, weak_cond, cb), loop);
    }

    uint64_t TimerManager::getNextTimer()
    {
        RWMutexType::ReadLock lock(m_mutex);
        m_tickled = false;
        if (m_timers.empty())
            return ~0ull;
        const Timer::ptr& timer = *m_timers.begin();
        uint64_t now = GetCurrentMS();
        return now >= timer->m_next ? 0 : timer->m_next - now;
    }

    void TimerManager::listTimeoutCb(std::vector<std::function<void()>>& cbs)
    {
        cbs.clear();
        uint64_t now = GetCurrentMS();
        std::vector<Timer::ptr> timeout;
        {
            RWMutexType::ReadLock lock(m_mutex);
            if (m_timers.empty())
                return;
        }
        RWMutexType::WriteLock lock(m_mutex);
        // bool rollover = detectClock(now);
        // if (!rollover && (*m_timers.begin())->m_next > now)
        //     return;

        Timer::ptr now_timer(new Timer(now));
        auto it = m_timers.lower_bound(now_timer);
        while (it != m_timers.end() && (*it)->m_next == now) {
            ++it;
        }
        timeout.insert(timeout.begin(), m_timers.begin(), it);
        m_timers.erase(m_timers.begin(), it);

        cbs.resize(timeout.size());
        for (auto& timer : timeout) {
            cbs.push_back(timer->m_cb);
            if (timer->m_loop) {
                timer->m_next = now + timer->m_ms;
                m_timers.insert(timer);
            } else {
                timer->m_cb = nullptr;
            }
        }
    }

    bool TimerManager::hasTimer() const
    {
        RWMutexType::ReadLock lock(m_mutex);
        return !m_timers.empty();
    }

    void TimerManager::addTimer(Timer::ptr timer, RWMutexType::WriteLock& lock)
    {
        auto it = m_timers.insert(timer).first;
        bool at_front = (it == m_timers.begin()) && !m_tickled;
        m_tickled = at_front ? true : m_tickled;
        lock.unlock();
        if (at_front)
            onTimerInsertAtFront();
    }

    // bool TimerManager::detectClock(uint64_t now_ms)
    // {
    //     bool rollover = false;
    //     if (now_ms < m_preTime && now_ms < m_preTime - 60 * 60 * 1000)
    //         rollover = true;
    //     m_preTime = now_ms;
    //     return rollover;
    // }

}  // namespace miruy