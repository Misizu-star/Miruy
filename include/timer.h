#ifndef __MIRUY_TIMER_H__
#define __MIRUY_TIMER_H__

#include <memory>
#include <functional>
#include <vector>
#include <set>
#include "mutex.h"

namespace miruy {

    class TimerManager;
    class Timer : public std::enable_shared_from_this<Timer>
    {
        friend class TimerManager;

    public:
        using ptr = std::shared_ptr<Timer>;

        bool cancel();
        bool refresh();
        bool reset(uint64_t ms, bool from_now = false);

    private:
        Timer(uint64_t ms, std::function<void()> cb, bool loop, TimerManager* manager);
        Timer(uint64_t next);
        struct Comparator
        {
            bool operator()(const Timer::ptr lhs, const Timer::ptr rhs);
        };

    private:
        bool m_loop;
        uint64_t m_ms;
        uint64_t m_next;
        std::function<void()> m_cb;
        TimerManager* m_manager{nullptr};
    };

    class TimerManager
    {
        friend class Timer;

    public:
        using RWMutexType = RWMutex;
        TimerManager();
        virtual ~TimerManager();

        Timer::ptr addTimer(time_t ms, std::function<void()> cb, bool loop = false);
        Timer::ptr addConditionTimer(time_t ms,
                                     std::function<void()> cb,
                                     std::weak_ptr<void> weak_cond,
                                     bool loop = false);
        uint64_t getNextTimer();
        void listTimeoutCb(std::vector<std::function<void()>>& cbs);
        bool hasTimer() const;

    protected:
        virtual void onTimerInsertAtFront() = 0;

    private:
        void addTimer(Timer::ptr timer, RWMutexType::WriteLock& lock);

    private:
        mutable RWMutexType m_mutex;
        bool m_tickled{false};
        // uint64_t m_preTime{0};
        std::set<Timer::ptr, Timer::Comparator> m_timers;
    };

}  // namespace miruy

#endif