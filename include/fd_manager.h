#ifndef __FD_MANAGER_H__
#define __FD_MANAGER_H__

#include <memory>
#include <vector>
#include "mutex.h"
#include "iomanager.h"
#include "singleton.h"

namespace miruy {

    class FdCtx : public std::enable_shared_from_this<FdCtx>
    {
    public:
        using ptr = std::shared_ptr<FdCtx>;
        FdCtx(int fd);
        ~FdCtx() = default;

        bool init();
        bool close();
        bool isInit() const { return m_isInit; }
        bool isSocket() const { return m_isSocket; }
        bool isNonblock() const { return m_Nonblock; }
        bool isClosed() const { return m_isClose; }

        void setNonblock(bool flag);
        void setTimeout(int type, uint64_t timeout);
        uint64_t getTimeout(int type);

    private:
        bool m_isInit{false};
        bool m_isSocket{false};
        bool m_Nonblock{false};
        bool m_isClose{false};
        int m_fd;
        uint64_t m_recvTimeout = 30;
        uint64_t m_sendTimeout = 30;
    };

    class FdManager
    {
    public:
        using ptr = std::shared_ptr<FdManager>;
        using RWMutexType = RWMutex;
        FdManager();

        FdCtx::ptr getfd(int fd, bool auto_create = false);
        void delfd(int fd);

    private:
        RWMutexType m_mutex;
        std::vector<FdCtx::ptr> m_fds;
    };

    using FdMgr = SingletonPtr<FdManager>;

}  // namespace miruy

#endif
