#ifndef __MIRUY_IOMANAGR_H__
#define __MIRUY_IOMANAGR_H__

#include "scheduler.h"
#include "timer.h"

namespace miruy {

enum class IOEvent : uint32_t {
    NONE = 0x0,   // 无事件
    READ = 0x1,   // 读事件
    WRITE = 0x4,  // 写事件
};

class IOManager : public Scheduler, public TimerManager
{
public:
    using ptr = std::shared_ptr<IOManager>;
    using RWMutexType = RWMutex;
    IOManager(uint32_t ths_count = 1, const std::string& name = "");
    ~IOManager();

    bool addEvent(int fd, IOEvent event, std::function<void()> cb = nullptr);
    bool delEvent(int fd, IOEvent event);
    bool cancelEvent(int fd, IOEvent event);
    bool cancelAll(int fd);
    bool stopped() override;

    static IOManager* GetThis();

protected:
    void tickle() override;
    bool stopping(uint64_t& timeout);
    void idle() override;
    void onTimerInsertAtFront() override;

private:
    struct FdContext {
        using MutexType = Mutex;
        struct EventContext {
            Scheduler* scheduler = nullptr;
            Fiber::ptr fiber = nullptr;
            std::function<void()> cb;
        };

        // 重置 EventContext
        static void ResetContext(EventContext& ctx);

        // 根据 IOEvent 获取 EventContext
        EventContext& getContext(IOEvent event);

        // 触发执行指定事件的回调函数
        void triggerEvent(IOEvent event);

        int fd = 0;
        EventContext read;
        EventContext write;
        uint32_t events = 0x0;
        MutexType mutex;
    };

private:
    int m_epfd;
    int m_pipe[2];

    RWMutexType m_mutex;
    std::atomic<size_t> m_eventCount{ 0 };
    std::vector<FdContext*> m_fdContexts;
};

}  // namespace miruy

#endif