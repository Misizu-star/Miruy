#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include "fd_manager.h"
#include "hook.h"

namespace miruy {

Fd::Fd(int fd) : m_fd(fd)
{
    struct stat fd_stat;
    if (-1 == fstat(m_fd, &fd_stat))
        throw std::logic_error("the fd does not exist or cloed");

    m_isInit = true;
    m_isSocket = S_ISSOCK(fd_stat.st_mode);
    int flag = fcntl_f(m_fd, F_GETFL, 0);
    m_Nonblock = flag & O_NONBLOCK;
    if (is_hook_enable() && m_isSocket && !m_Nonblock) {
        fcntl_f(m_fd, F_SETFL, flag | O_NONBLOCK);
        m_Nonblock = true;
    }
}

void Fd::setNonblock(bool flag)
{
    int f = fcntl_f(m_fd, F_GETFL, 0);
    if (flag && !m_Nonblock) {
        fcntl_f(m_fd, F_SETFL, f | O_NONBLOCK);
        return;
    }
    if (!flag && m_Nonblock) {
        fcntl_f(m_fd, F_SETFL, f & ~O_NONBLOCK);
        return;
    }
}

void Fd::setTimeout(int type, uint64_t timeout)
{
    if (type == SO_RCVTIMEO)
        m_recvTimeout = timeout;
    else if (type == SO_SNDTIMEO)
        m_sendTimeout = timeout;
}

uint64_t Fd::getTimeout(int type) const
{
    if (type == SO_RCVTIMEO)
        return m_recvTimeout;
    if (type == SO_SNDTIMEO)
        return m_sendTimeout;
    return -1;
}

bool Fd::close()
{
    return !close_f(m_fd);
}

bool Fd::ISNonBlock(int fd)
{
    int f = fcntl_f(fd, F_GETFL, 0);
    return !!(f & O_NONBLOCK);
}

void Fd::SetNonBlock(int fd, bool flag)
{
    int f = fcntl_f(fd, F_GETFL, 0);
    if (flag && !(f & O_NONBLOCK))
        fcntl_f(fd, F_SETFL, f | O_NONBLOCK);
    else if (!flag && (f & O_NONBLOCK))
        fcntl_f(fd, F_SETFL, f & ~O_NONBLOCK);
}

FdManager::FdManager()
{
    m_fds.resize(64);
}

Fd::ptr FdManager::getfd(int fd, bool auto_create)
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
    m_fds[fd] = Fd::ptr(new Fd(fd));
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