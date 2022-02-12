#ifndef __MIRUY_IOMANAGR_H__
#define __MIRUY_IOMANAGR_H__

#include "scheduler.h"
#include "timer.h"

namespace miruy {

    enum class Event : uint32_t {
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

        bool addEvent(int fd, Event event, std::function<void()> cb = nullptr);
        bool delEvent(int fd, Event event);
        bool cancelEvent(int fd, Event event);
        bool cancelAll(int fd);

        static IOManager* GetThis();

    protected:
        void tickle() override;
        bool stopping(uint64_t& timeout);
        bool stopping() override;
        void idle() override;
        void onTimerInsertAtFront() override;
        void contextResize(size_t size);

    private:
        struct FdContext
        {
            using MutexType = Mutex;
            struct EventContext
            {
                Scheduler* scheduler = nullptr;
                Fiber::ptr fiber;
                std::function<void()> cb;
            };

            EventContext& getContext(Event event);
            void resetContext(EventContext& ctx);
            void triggerEvent(Event event);

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
        std::atomic<size_t> m_eventCount{0};
        std::vector<FdContext*> m_fdContexts;
    };

}  // namespace miruy

#endif