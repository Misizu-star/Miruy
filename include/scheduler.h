#ifndef __MIRUY_SCHEDULER_H__
#define __MIRUY_SCHEDULER_H__

#include <memory>
#include <vector>
#include <list>
#include <functional>
#include "thread.h"
#include "fiber.h"
#include "mutex.h"

namespace miruy {

class Scheduler
{
public:
    using ptr = std::shared_ptr<Scheduler>;
    using MutexType = Mutex;
    Scheduler(uint32_t ths_count = 1, const std::string& name = "");
    virtual ~Scheduler();

    void setName(const std::string& name) { m_name = name; }
    const std::string& getName() const { return m_name; }

    void start();
    void stop();
    bool hasIdelThread() const;
    virtual bool stopped();

    static Scheduler* GetThis();
    static Fiber* GetMainFiber();

    template <class Task>
    void schedule(Task t)
    {
        bool need_tickle = false;
        {
            MutexType::Lock lock(m_mutex);
            need_tickle = scheduleNonLock(t);
        }
        if (need_tickle)
            tickle();
    }

    template <class Itor>
    void schedule(Itor begin, Itor end)
    {
        bool need_tickle = false;
        {
            MutexType::Lock lock(m_mutex);
            while (begin != end) {
                need_tickle = scheduleNonLock(&*begin) || need_tickle;
                ++begin;
            }
        }
        if (need_tickle)
            tickle();
    }

private:
    template <typename Task>
    bool scheduleNonLock(Task task)
    {
        bool need_tickle = m_tasks.empty();
        FiberAndFunc ff(task);
        if (ff.fiber || ff.cb) {
            m_tasks.push_back(std::move(ff));
        }
        return need_tickle;
    }

protected:
    void run();
    virtual void tickle();
    virtual void idle();

private:
    struct FiberAndFunc {
        Fiber::ptr fiber;
        std::function<void()> cb;

        FiberAndFunc() : fiber(nullptr), cb(nullptr) {}
        FiberAndFunc(Fiber::ptr f) : fiber(f), cb(nullptr) {}
        FiberAndFunc(Fiber::ptr* f) : cb(nullptr) { fiber.swap(*f); }
        FiberAndFunc(std::function<void()> f) : fiber(nullptr), cb(f) {}
        FiberAndFunc(std::function<void()>* f) : fiber(nullptr) { cb.swap(*f); }

        void reset()
        {
            fiber = nullptr;
            cb = nullptr;
        }
    };

private:
    MutexType m_mutex;                   // 互斥信号量
    std::string m_name;                  // 调度器名称
    std::vector<Thread::ptr> m_threads;  // 线程池
    std::list<FiberAndFunc> m_tasks;     // 等待执行任务队列

protected:
    std::vector<uint32_t> m_tids;     // 线程池id数组
    size_t m_threadCount{ 0 };        // 总线程数
    size_t m_activeThreadCount{ 0 };  // 活跃线程数
    size_t m_idleThreadCount{ 0 };    // 空闲线程数
    bool m_running{ false };          // 运行状态
    // bool m_autoStop{ false };         // 自动停止
};

}  // namespace miruy

#endif