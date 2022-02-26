#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <dlfcn.h>
#include <stdarg.h>
#include "hook.h"
#include "iomanager.h"
#include "fd_manager.h"
#include "config.h"
#include "log.h"

namespace miruy {

static thread_local bool t_hook_enable = false;

bool is_hook_enable()
{
    return t_hook_enable && IOManager::GetThis();
}

void set_hook_enable(bool flag)
{
    t_hook_enable = flag;
}

}  // namespace miruy

#define HOOK_FUN(XX)                                                                               \
    XX(sleep);                                                                                     \
    XX(socket);                                                                                    \
    XX(connect);                                                                                   \
    XX(accept);                                                                                    \
    XX(read);                                                                                      \
    XX(readv);                                                                                     \
    XX(recv);                                                                                      \
    XX(recvfrom);                                                                                  \
    XX(recvmsg);                                                                                   \
    XX(write);                                                                                     \
    XX(writev);                                                                                    \
    XX(send);                                                                                      \
    XX(sendto);                                                                                    \
    XX(sendmsg);                                                                                   \
    XX(close);                                                                                     \
    XX(fcntl);                                                                                     \
    XX(ioctl);                                                                                     \
    XX(getsockopt);                                                                                \
    XX(setsockopt);

void hook_init()
{
#define XX(name) name##_f = (name##_fun)dlsym(RTLD_NEXT, #name)
    HOOK_FUN(XX);
#undef XX
}

static uint32_t s_connect_timeout;
static miruy::ConfigVar<uint64_t>::ptr g_connect_timeout =
    miruy::Config::Lookup<uint64_t>("timeout.connect", 5000, "socket connect timeout");

struct _HookIniter {
    _HookIniter()
    {
        hook_init();
        s_connect_timeout = g_connect_timeout->getValue();
        g_connect_timeout->addListener(
            [](const uint32_t& old_val, const uint32_t& new_val) { s_connect_timeout = new_val; });
    }
};

static struct _HookIniter hook_initer;

template <typename OSFun, typename... Args>
static ssize_t
do_io(int fd, OSFun fun, const char* hook_fun_name, miruy::IOEvent event, int type, Args&&... args)
{
    if (!miruy::is_hook_enable())
        return fun(fd, std::forward<Args>(args)...);

    miruy::Fd::ptr fd_ctx = miruy::FdMgr::getInstance()->getfd(fd);
    if (!fd_ctx)
        return fun(fd, std::forward<Args>(args)...);

    if (fd_ctx->isClosed()) {
        errno = EBADF;
        return -1;
    }

    if (!fd_ctx->isSocket() || !fd_ctx->isNonblock())
        return fun(fd, std::forward<Args>(args)...);

    uint64_t timeout = fd_ctx->getTimeout(type);

again:
    ssize_t ret = fun(fd, std::forward<Args>(args)...);
    while (ret == -1 && errno == EINTR) {
        ret = fun(fd, std::forward<Args>(args)...);
    }

    if (ret == -1 && errno == EAGAIN) {
        miruy::IOManager* iom = miruy::IOManager::GetThis();
        miruy::Timer::ptr timer = iom->addTimer(timeout, [fd, iom, event]() {
            iom->cancelEvent(fd, event);
            // LOG_INFO(LOGGER("system")) << "time out";
        });

        if (iom->addEvent(fd, event)) {
            miruy::Fiber::YieldToHold();
            goto again;
        } else {
            if (timer)
                timer->cancel();
            return -1;
        }
    }

    return ret;
}

extern "C" {
#define XX(name) name##_fun name##_f;
HOOK_FUN(XX);
#undef XX

unsigned int sleep(unsigned int seconds)
{
    if (!miruy::is_hook_enable())
        return sleep_f(seconds);

    miruy::Fiber::ptr fiber = miruy::Fiber::GetThis();
    miruy::IOManager* iom = miruy::IOManager::GetThis();
    iom->addTimer(seconds * 1000, [iom, &fiber]() { iom->schedule(fiber); });
    miruy::Fiber::YieldToHold();
    return 0;
}

int msleep(useconds_t msec)
{
    if (!miruy::is_hook_enable())
        return usleep(msec * 1000);
    miruy::Fiber::ptr fiber = miruy::Fiber::GetThis();
    miruy::IOManager* iom = miruy::IOManager::GetThis();
    iom->addTimer(msec, [iom, fiber]() { iom->schedule(fiber); });
    miruy::Fiber::YieldToHold();
    return 0;
}

int socket(int domain, int type, int protocol)
{
    int fd = socket_f(domain, type, protocol);
    if (fd != -1)
        miruy::FdMgr::getInstance()->getfd(fd, true);
    return fd;
}

int connect_with_timeout(int sockfd, const struct sockaddr* addr, socklen_t addrlen, time_t timeout)
{
    if (!miruy::is_hook_enable())
        return connect_f(sockfd, addr, addrlen);
    miruy::Fd::ptr fd_ctx = miruy::FdMgr::getInstance()->getfd(sockfd);
    if (!fd_ctx || fd_ctx->isClosed()) {
        errno = EBADF;
        return -1;
    }

    if (!fd_ctx->isSocket())
        return connect_f(sockfd, addr, addrlen);

    if (!fd_ctx->isNonblock())
        return connect_f(sockfd, addr, addrlen);

    int ret = connect_f(sockfd, addr, addrlen);
    if (ret != -1 || errno != EINPROGRESS)
        return ret;

    bool has_timeout = false;
    miruy::IOManager* iom = miruy::IOManager::GetThis();
    miruy::Timer::ptr timer = iom->addTimer(timeout, [sockfd, iom, &has_timeout]() {
        has_timeout = true;
        iom->cancelAll(sockfd);
    });

    if (iom->addEvent(sockfd, miruy::IOEvent::WRITE)) {
        miruy::Fiber::YieldToHold();
        timer->cancel();
        if (has_timeout)
            return -1;
    } else {
        timer->cancel();
        LOG_ERROR(LOGGER("system")) << "connect addEvent(" << sockfd << ", Write) error";
    }

    int error = 0;
    socklen_t len = sizeof(int);
    if (-1 == getsockopt_f(sockfd, SOL_SOCKET, SO_ERROR, &error, &len))
        return -1;

    if (error) {
        errno = error;
        return -1;
    }
    return 0;
}

int connect(int sockfd, const struct sockaddr* addr, socklen_t addrlen)
{
    return connect_with_timeout(sockfd, addr, addrlen, s_connect_timeout);
}

int accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen)
{
    int fd =
        (int)do_io(sockfd, accept_f, "accept", miruy::IOEvent::READ, SO_RCVTIMEO, addr, addrlen);
    if (fd >= 0) {
        miruy::FdMgr::getInstance()->getfd(fd, true);
    }
    return fd;
}

// read
ssize_t read(int fd, void* buf, size_t count)
{
    return do_io(fd, read_f, "read", miruy::IOEvent::READ, SO_RCVTIMEO, buf, count);
}

ssize_t readv(int fd, const struct iovec* iov, int iovcnt)
{
    return do_io(fd, readv_f, "readv", miruy::IOEvent::READ, SO_RCVTIMEO, iov, iovcnt);
}

ssize_t recv(int sockfd, void* buf, size_t len, int flags)
{
    return do_io(sockfd, recv_f, "recv", miruy::IOEvent::READ, SO_RCVTIMEO, buf, len, flags);
}

ssize_t recvfrom(int sockfd,
                 void* buf,
                 size_t len,
                 int flags,
                 struct sockaddr* src_addr,
                 socklen_t* addrlen)
{
    return do_io(sockfd, recvfrom_f, "recvfrom", miruy::IOEvent::READ, SO_RCVTIMEO, buf, len, flags,
                 src_addr, addrlen);
}

ssize_t recvmsg(int sockfd, struct msghdr* msg, int flags)
{
    return do_io(sockfd, recvmsg_f, "recvmsg", miruy::IOEvent::READ, SO_RCVTIMEO, msg, flags);
}

// write
ssize_t write(int fd, const void* buf, size_t count)
{
    return do_io(fd, write_f, "write", miruy::IOEvent::WRITE, SO_SNDTIMEO, buf, count);
}

ssize_t writev(int fd, const struct iovec* iov, int iovcntq)
{
    return do_io(fd, writev_f, "writev", miruy::IOEvent::WRITE, SO_SNDTIMEO, iov, iovcntq);
}

ssize_t send(int sockfd, const void* buf, size_t len, int flags)
{
    return do_io(sockfd, send_f, "send", miruy::IOEvent::WRITE, SO_SNDTIMEO, buf, len, flags);
}

ssize_t sendto(int sockfd,
               const void* buf,
               size_t len,
               int flags,
               const struct sockaddr* dest_addr,
               socklen_t addrlen)
{
    return do_io(sockfd, sendto_f, "sendto", miruy::IOEvent::WRITE, SO_SNDTIMEO, buf, len, flags,
                 dest_addr, addrlen);
}

ssize_t sendmsg(int sockfd, const struct msghdr* msg, int flags)
{
    return do_io(sockfd, sendmsg_f, "sendmsg", miruy::IOEvent::WRITE, SO_SNDTIMEO, msg, flags);
}

int close(int fd)
{
    miruy::Fd::ptr fd_ctx = miruy::FdMgr::getInstance()->getfd(fd);
    if (fd_ctx) {
        auto iom = miruy::IOManager::GetThis();
        if (iom) {
            iom->cancelAll(fd);
        }
        miruy::FdMgr::getInstance()->delfd(fd);
    }
    return close_f(fd);
}

// fcntl
int fcntl(int fd, int cmd, ...)
{
    va_list va;
    va_start(va, cmd);
    switch (cmd) {
        // int
        case F_SETFL: {
            int arg = va_arg(va, int);
            va_end(va);
            if (miruy::is_hook_enable()) {
                miruy::Fd::ptr fd_ctx = miruy::FdMgr::getInstance()->getfd(fd);
                if (fd_ctx && !fd_ctx->isClosed() && fd_ctx->isSocket()) {
                    fd_ctx->setNonblock((bool)(arg & O_NONBLOCK));
                }
            }
            return fcntl_f(fd, cmd, arg);
        }

        case F_DUPFD:
        case F_DUPFD_CLOEXEC:
        case F_SETFD:
        case F_SETOWN:
        case F_SETSIG:
        case F_SETLEASE:
#ifdef F_SETPIPE_SZ
        case F_SETPIPE_SZ:
#endif
        case F_NOTIFY: {
            int arg = va_arg(va, int);
            va_end(va);
            return fcntl_f(fd, cmd, arg);
        }

        // struct flock*
        case F_OFD_SETLK:
        case F_OFD_SETLKW:
        case F_OFD_GETLK: {
            struct flock* arg = va_arg(va, struct flock*);
            va_end(va);
            return fcntl_f(fd, cmd, arg);
        }

        // struct f_owner_ex* arg
        case F_GETOWN_EX:
        case F_SETOWN_EX: {
            struct f_owner_ex* arg = va_arg(va, struct f_owner_ex*);
            va_end(va);
            return fcntl_f(fd, cmd, arg);
        }

        // void & other
        case F_GETFL:
        case F_GETFD:
        case F_GETOWN:
        case F_GETSIG:
        case F_GETLEASE:
#ifdef F_GETPIPE_SZ
        case F_GETPIPE_SZ:
#endif
        default: {
            va_end(va);
            return fcntl_f(fd, cmd);
        }
    }
}

int ioctl(int fd, unsigned long request, ...)
{
    va_list va;
    va_start(va, request);
    void* arg = va_arg(va, void*);
    va_end(va);

    if (miruy::is_hook_enable() && FIONBIO == request) {
        miruy::Fd::ptr fd_ctx = miruy::FdMgr::getInstance()->getfd(fd);
        if (fd_ctx && !fd_ctx->isClosed() && fd_ctx->isSocket())
            fd_ctx->setNonblock(!!*(int*)arg);
    }
    return ioctl_f(fd, request, arg);
}

int getsockopt(int sockfd, int level, int optname, void* optval, socklen_t* optlen)
{
    return getsockopt_f(sockfd, level, optname, optval, optlen);
}

int setsockopt(int sockfd, int level, int optname, const void* optval, socklen_t optlen)
{
    if (!miruy::is_hook_enable())
        return setsockopt_f(sockfd, level, optname, optval, optlen);
    if (level == SOL_SOCKET) {
        if (optname == SO_RCVTIMEO || optname == SO_SNDTIMEO) {
            miruy::Fd::ptr fd_ctx = miruy::FdMgr::getInstance()->getfd(sockfd);
            if (fd_ctx) {
                const timeval* tv = (const timeval*)optval;
                fd_ctx->setTimeout(optname, tv->tv_sec * 1000 + tv->tv_usec / 1000);
            }
        }
    }
    return setsockopt_f(sockfd, level, optname, optval, optlen);
}
}