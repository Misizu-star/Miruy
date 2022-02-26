#ifndef __MIRUY_SOCKET_H__
#define __MIRUY_SOCKET_H__

#include <memory>
#include "address.h"
#include "noncopy.h"

namespace miruy {

class Socket : public std::enable_shared_from_this<Socket>, NonCopy
{
public:
    using ptr = std::shared_ptr<Socket>;
    using weak_ptr = std::weak_ptr<Socket>;
    Socket(int family, int type, int protocol = 0);
    ~Socket() { this->close(); }

    static Socket::ptr CreateTCP(Address::ptr address);
    static Socket::ptr CreateUDP(Address::ptr address);
    static Socket::ptr CreateTCPSocket();
    static Socket::ptr CreateUDPSocket();
    static Socket::ptr CreateTCPSocket6();
    static Socket::ptr CreateUDPSocket6();
    static Socket::ptr CreateUnixTCPSocket();
    static Socket::ptr CreateUnixUDPSocket();

    int getFamily() const { return m_family; }
    int getType() const { return m_type; }
    int getProtocol() const { return m_protocol; }
    int getFd() const { return m_sock; }

    bool isConnected() const { return m_isConnected; }
    bool isVaild() const;

    bool getOption(int level, int option, void* result, size_t* len) const;
    bool setOption(int level, int option, const void* result, size_t len) const;

    uint64_t getSendTimeout() const;
    uint64_t getRecvTimeout() const;
    bool setSendTimeout(uint64_t timeout_ms);
    bool setRecvTimeout(uint64_t timeout_ms);

    Address::ptr getRemoteAddress() const;
    Address::ptr getLocalAddress() const;

    void setNonBlock(bool flag) const;

    Socket::ptr accept() const;
    bool bind(const Address::ptr addr) const;
    bool connect(const Address::ptr addr, uint32_t timeout_ms = 0);
    bool listen(int backlog = SOMAXCONN) const;
    void close();

    int send(const void* buff, size_t len, int flag = 0) const;
    int send(const iovec* buffs, size_t len, int flag = 0) const;
    int sendTo(const void* buff, size_t len, const Address::ptr to, int flag = 0) const;
    int sendTo(const iovec* buffs, size_t len, const Address::ptr to, int flag = 0) const;

    int recv(void* buff, size_t len, int flag = 0) const;
    int recv(iovec* buffs, size_t len, int flag = 0) const;
    int recvFrom(void* buff, size_t len, Address::ptr from, int flag = 0) const;
    int recvFrom(iovec* buffs, size_t len, Address::ptr from, int flag = 0) const;

    std::string toString() const;

private:
    Socket() = default;
    static void init(int sock, bool is_stream);
    void reset(int sock, int family, int type, int protocol);

private:
    int m_sock;
    int m_family;
    int m_type;
    int m_protocol;
    bool m_isConnected{ false };

    mutable Address::ptr m_remote;
    mutable Address::ptr m_local;
};

}  // namespace miruy

#endif