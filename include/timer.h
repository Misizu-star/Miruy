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

    void cancel();                                   // 取消计时
    bool refresh();                                  // 从当前时间重新计时
    bool reset(uint64_t ms, bool from_now = false);  // 重设定时时间

private:
    Timer(uint64_t ms, std::function<void()> cb, bool loop, TimerManager* manager);
    Timer(uint64_t next);
    struct Comparator {
        bool operator()(const Timer::ptr lhs, const Timer::ptr rhs);
    };

private:
    bool m_loop;      // 是否循环计时
    uint64_t m_ms;    // 计时时间
    uint64_t m_next;  // 执行时间
    std::function<void()> m_cb;
    TimerManager* m_manager{ nullptr };
};

class TimerManager
{
    friend class Timer;

public:
    using RWMutexType = RWMutex;
    TimerManager() = default;
    virtual ~TimerManager() = default;

    Timer::ptr addTimer(time_t ms, std::function<void()> cb, bool loop = false);
    Timer::ptr addConditionTimer(time_t ms,
                                 std::function<void()> cb,
                                 std::weak_ptr<void> weak_cond,
                                 bool loop = false);
    uint64_t getNextTimeout();
    void listTimeoutCb(std::vector<std::function<void()>>& cbs);
    bool hasTimer() const;

protected:
    virtual void onTimerInsertAtFront() = 0;

private:
    bool m_tickled{ false };
    mutable RWMutexType m_mutex;
    std::set<Timer::ptr, Timer::Comparator> m_timers;
};

}  // namespace miruy

#endif