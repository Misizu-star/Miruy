#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include "fd_manager.h"
#include "hook.h"

namespace miruy {

    FdCtx::FdCtx(int fd) : m_fd(fd) { init(); }

    bool FdCtx::init()
    {
        if (m_isInit)
            return true;

        struct stat fd_stat;
        if (-1 == fstat(m_fd, &fd_stat))
            return false;

        m_isInit = true;
        int flag = fcntl_f(m_fd, F_GETFL, 0);
        m_Nonblock = !!(flag & O_NONBLOCK);
        m_isSocket = S_ISSOCK(fd_stat.st_mode);
        if (m_isSocket) {
            if (!m_Nonblock) {
                fcntl_f(m_fd, F_SETFL, flag | O_NONBLOCK);
            }
            m_Nonblock = true;
        }
        return true;
    }

    void FdCtx::setNonblock(bool block)
    {
        int flag = fcntl_f(m_fd, F_GETFL, 0);
        if (block && !m_Nonblock) {
            fcntl_f(m_fd, F_SETFL, flag | O_NONBLOCK);
            return;
        }
        if (!block && m_Nonblock) {
            fcntl_f(m_fd, F_SETFL, flag & ~O_NONBLOCK);
            return;
        }
    }

    void FdCtx::setTimeout(int type, uint64_t timeout)
    {
        if (type == SO_RCVTIMEO)
            m_recvTimeout = timeout;
        else if (type == SO_SNDTIMEO)
            m_sendTimeout = timeout;
    }

    uint64_t FdCtx::getTimeout(int type)
    {
        if (type == SO_RCVTIMEO)
            return m_recvTimeout;
        if (type == SO_SNDTIMEO)
            return m_sendTimeout;
        return -1;
    }

    bool FdCtx::close() { return !close_f(m_fd); }

    FdManager::FdManager() { m_fds.resize(64); }

    FdCtx::ptr FdManager::getfd(int fd, bool auto_create)
    {
        RWMutexType::ReadLock lock(m_mutex);
        if (fd >= m_fds.size() && !auto_create)
            return nullptr;
        if (fd < m_fds.size() && m_fds[fd])
            return m_fds[fd];
        lock.unlock();

        RWMutexType::WriteLock lock2(m_mutex);
        if (fd >= m_fds.size())
            m_fds.resize(fd >> 1 + fd);
        m_fds[fd] = FdCtx::ptr(new FdCtx(fd));
        return m_fds[fd];
    }

    void FdManager::delfd(int fd)
    {
        RWMutexType::WriteLock lock(m_mutex);
        if (fd >= m_fds.size())
            return;
        m_fds[fd].reset();
    }

}  // namespace miruy