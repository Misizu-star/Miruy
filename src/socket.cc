#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include "hook.h"
#include "fd_manager.h"
#include "socket.h"

namespace miruy {

    Socket::ptr Socket::CreateTCP(Address::ptr address)
    {
        return Socket::ptr(new Socket(address->getFamily(), SOCK_STREAM, 0));
    }

    Socket::ptr Socket::CreateUDP(Address::ptr address)
    {
        return Socket::ptr(new Socket(address->getFamily(), SOCK_DGRAM, 0));
    }

    Socket::ptr Socket::CreateTCPSocket()
    {
        return Socket::ptr(new Socket(AF_INET, SOCK_STREAM, 0));
    }

    Socket::ptr Socket::CreateUDPSocket()
    {
        return Socket::ptr(new Socket(AF_INET, SOCK_DGRAM, 0));
    }

    Socket::ptr Socket::CreateTCPSocket6()
    {
        return Socket::ptr(new Socket(AF_INET6, SOCK_STREAM, 0));
    }

    Socket::ptr Socket::CreateUDPSocket6()
    {
        return Socket::ptr(new Socket(AF_INET6, SOCK_DGRAM, 0));
    }

    Socket::ptr Socket::CreateUnixTCPSocket()
    {
        return Socket::ptr(new Socket(AF_UNIX, SOCK_STREAM, 0));
    }

    Socket::ptr Socket::CreateUnixUDPSocket()
    {
        return Socket::ptr(new Socket(AF_UNIX, SOCK_DGRAM, 0));
    }

    Socket::Socket(int family, int type, int protocol)
        : m_family(family), m_type(type), m_protocol(protocol)
    {
        m_sock = ::socket(m_family, m_type, m_protocol);
        if (m_sock != -1)
            Socket::init(m_sock, m_type == SOCK_STREAM);
    }

    void Socket::init(int sock, bool is_stream)
    {
        FdCtx::ptr fd_ctx = FdMgr::getInstance()->getfd(sock);
        if (fd_ctx && fd_ctx->isSocket() && !fd_ctx->isClosed()) {
            int val = 1;
            setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
            if (is_stream)
                setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &val, sizeof(val));
        }
    }

    void Socket::reset(int sock, int family, int type, int protocol)
    {
        m_sock = sock;
        m_family = family;
        m_type = type;
        m_protocol = protocol;
    }

    bool Socket::isVaild() const { return m_sock != -1; }

    bool Socket::getOption(int level, int option, void* result, size_t* len) const
    {
        return !getsockopt(m_sock, level, option, result, (socklen_t*)len);
    }

    bool Socket::setOption(int level, int option, const void* result, size_t len) const
    {
        return !setsockopt(m_sock, level, option, result, (socklen_t)len);
    }

    uint64_t Socket::getSendTimeout() const
    {
        FdCtx::ptr fd_ctx = FdMgr::getInstance()->getfd(m_sock);
        return fd_ctx ? fd_ctx->getTimeout(SO_SNDTIMEO) : 0;
    }

    uint64_t Socket::getRecvTimeout() const
    {
        FdCtx::ptr fd_ctx = FdMgr::getInstance()->getfd(m_sock);
        return fd_ctx ? fd_ctx->getTimeout(SO_RCVTIMEO) : 0;
    }

    bool Socket::setSendTimeout(uint64_t timeout_ms)
    {
        struct timeval tv
        {
            time_t(timeout_ms / 1000), suseconds_t(timeout_ms % 1000000)
        };
        return setOption(SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
    }

    bool Socket::setRecvTimeout(uint64_t timeout_ms)
    {
        struct timeval tv
        {
            time_t(timeout_ms / 1000), suseconds_t(timeout_ms % 1000000)
        };
        return setOption(SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
    }

    Address::ptr Socket::getRemoteAddress() const
    {
        if (m_remote)
            return m_remote;
        Address::ptr ret;
        switch (m_family) {
            case AF_INET: ret.reset(new IPv4Address(nullptr)); break;
            case AF_INET6: ret.reset(new IPv6Address(nullptr)); break;
            case AF_UNIX: ret.reset(new UnixAddress); break;
            default: ret.reset(new UnknowAddress(m_family));
        }
        socklen_t addrlen = ret->getAddrLen();
        if (getpeername(m_sock, ret->getAddr(), &addrlen))
            ret.reset(new UnknowAddress(m_family));
        if (m_family == AF_UNIX) {
            UnixAddress::ptr addr = std::dynamic_pointer_cast<UnixAddress>(ret);
            addr->setAddrLen(addrlen);
        }
        m_remote = ret;
        return m_remote;
    }

    Address::ptr Socket::getLocalAddress() const
    {
        if (m_local)
            return m_local;
        Address::ptr ret;
        switch (m_family) {
            case AF_INET: ret.reset(new IPv4Address(nullptr)); break;
            case AF_INET6: ret.reset(new IPv6Address(nullptr)); break;
            case AF_UNIX: ret.reset(new UnixAddress); break;
            default: ret.reset(new UnknowAddress(m_family));
        }
        socklen_t addrlen = ret->getAddrLen();
        if (getsockname(m_sock, ret->getAddr(), &addrlen))
            ret.reset(new UnknowAddress(m_family));
        if (m_family == AF_UNIX) {
            UnixAddress::ptr addr = std::dynamic_pointer_cast<UnixAddress>(ret);
            addr->setAddrLen(addrlen);
        }
        m_local = ret;
        return m_local;
    }

    Socket::ptr Socket::accept() const
    {
        Socket::ptr sock(new Socket);
        int newsock = ::accept(m_sock, nullptr, nullptr);
        if (newsock == -1)
            return nullptr;
        sock->reset(newsock, m_family, m_type, m_protocol);
        sock->init(newsock, m_type == SOCK_STREAM);
        sock->m_isConnected = true;
        return sock;
    }

    bool Socket::bind(const Address::ptr addr) const
    {
        if (!isVaild())
            return false;
        if (addr->getFamily() != m_family)
            return false;
        if (::bind(m_sock, addr->getAddr(), addr->getAddrLen()))
            return false;
        getLocalAddress();
        return true;
    }

    bool Socket::connect(const Address::ptr addr, uint32_t timeout_ms)
    {
        if (!isVaild())
            return false;
        if (addr->getFamily() != m_family)
            return false;

        if (timeout_ms == 0) {
            if (::connect(m_sock, addr->getAddr(), addr->getAddrLen()))
                return false;
        } else {
            if (::connect_with_timeout(m_sock, addr->getAddr(), addr->getAddrLen(), timeout_ms))
                return false;
        }
        m_isConnected = true;
        getLocalAddress();
        getRemoteAddress();
        return true;
    }

    bool Socket::listen(int backlog)
    {
        if (!isVaild())
            return false;
        if (::listen(m_sock, backlog))
            return false;
        return true;
    }

    bool Socket::close()
    {
        if (!m_isConnected && m_sock == -1)
            return true;
        m_isConnected = false;
        if (m_sock == -1)
            return true;
        int ret = ::close(m_sock);
        m_sock = -1;
        return !ret;
    }

    int Socket::send(const void* buff, size_t len, int flag)
    {
        if (!isConnected())
            return -1;
        return ::send(m_sock, buff, len, flag);
    }

    int Socket::send(const iovec* buffs, size_t len, int flag)
    {
        if (!isConnected())
            return -1;
        msghdr msg;
        memset(&msg, 0, sizeof(msg));
        msg.msg_iov = (iovec*)buffs;
        msg.msg_iovlen = len;
        return ::sendmsg(m_sock, &msg, flag);
    }

    int Socket::sendTo(const void* buff, size_t len, const Address::ptr to, int flag)
    {
        if (!isConnected())
            return -1;
        return ::sendto(m_sock, buff, len, flag, to->getAddr(), to->getAddrLen());
    }

    int Socket::sendTo(const iovec* buffs, size_t len, const Address::ptr to, int flag)
    {
        if (!isConnected())
            return -1;
        msghdr msg;
        memset(&msg, 0, sizeof(msg));
        msg.msg_iov = (iovec*)buffs;
        msg.msg_iovlen = len;
        msg.msg_name = (void*)to->getAddr();
        msg.msg_namelen = to->getAddrLen();
        return ::sendmsg(m_sock, &msg, flag);
    }

    int Socket::recv(void* buff, size_t len, int flag)
    {
        if (!isConnected())
            return -1;
        return ::recv(m_sock, buff, len, flag);
    }

    int Socket::recv(iovec* buffs, size_t len, int flag)
    {
        if (!isConnected())
            return -1;
        msghdr msg;
        memset(&msg, 0, sizeof(msg));
        msg.msg_iov = (iovec*)buffs;
        msg.msg_iovlen = len;
        return ::recvmsg(m_sock, &msg, flag);
    }

    int Socket::recvFrom(void* buff, size_t len, Address::ptr from, int flag)
    {
        if (!isConnected())
            return -1;
        socklen_t addrlen = from->getAddrLen();
        return ::recvfrom(m_sock, buff, len, flag, from->getAddr(), &addrlen);
    }

    int Socket::recvFrom(iovec* buffs, size_t len, Address::ptr from, int flag)
    {
        if (!isConnected())
            return -1;
        msghdr msg;
        memset(&msg, 0, sizeof(msg));
        msg.msg_iov = (iovec*)buffs;
        msg.msg_iovlen = len;
        msg.msg_name = (void*)from->getAddr();
        msg.msg_namelen = from->getAddrLen();
        return ::recvmsg(m_sock, &msg, flag);
    }

    std::string Socket::toString() const
    {
        std::stringstream ss;
        ss << std::boolalpha << "[Socket sock=" << m_sock << " is_connected=" << m_isConnected
           << " family=" << m_family << " type=" << m_type << " protocol=" << m_protocol;
        if (m_local)
            ss << " local_address=" << m_local->toString();
        if (m_remote)
            ss << " remote_address=" << m_remote->toString();
        ss << "]";
        return ss.str();
    }

}  // namespace miruy