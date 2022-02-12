#include <sstream>
#include <cstring>
#include <arpa/inet.h>
#include <netdb.h>
#include <set>
#include "address.h"

#define MASKMODE(x) ~((1 << 32 - (x)) - 1)

namespace miruy {

    /* Address */
    int Address::getFamily() const { return getAddr()->sa_family; }

    Address::ptr Address::Create(const char* host, uint16_t port)
    {
        addrinfo* results;
        addrinfo info;
        memset(&info, 0, sizeof(info));
        info.ai_family = AF_UNSPEC;
        info.ai_flags = 0;
        int error = getaddrinfo(host, std::to_string(port).data(), &info, &results);
        if (error)
            return UnknowAddress::ptr(new UnknowAddress);

        Address::ptr ret;
        switch (results->ai_addr->sa_family) {
            case AF_INET: ret.reset(new IPv4Address(*(sockaddr_in*)results->ai_addr)); break;
            case AF_INET6: ret.reset(new IPv6Address(*(sockaddr_in6*)results->ai_addr)); break;
            default: ret.reset(new UnknowAddress(results->ai_addr->sa_family));
        }
        freeaddrinfo(results);
        return ret;
    }

    bool Address::Lookup(std::vector<Address::ptr>& result,
                         const std::string& host,
                         int family,
                         int type,
                         int protocol)
    {
        addrinfo info, *results, *next;
        memset(&info, 0, sizeof(info));
        info.ai_family = family;
        info.ai_socktype = type;
        info.ai_protocol = protocol;

        std::string node;
        const char* port = nullptr;
        if (!host.empty() && host[0] == '[') {
            const char* endipv6 = (const char*)memchr(host.c_str(), ']', host.size() - 1);
            if (endipv6) {
                if (*(endipv6 + 1) == ':' && *(endipv6 + 2))
                    port = endipv6 + 2;
                node = host.substr(1, endipv6 - host.c_str() - 1);
            }
        }

        if (node.empty()) {
            node = host;
            const char* end = (const char*)memchr(host.c_str(), ':', host.size());
            if (end && memchr(host.c_str(), '.', host.size())) {
                port = end + 1;
                node = host.substr(0, end - host.c_str());
            }
        }

        if (getaddrinfo(node.c_str(), port, &info, &results))
            return false;
        next = results;
        std::set<Address::ptr> ips;
        while (next) {
            if (next->ai_addr->sa_family == AF_INET)
                ips.insert(IPv4Address::ptr(new IPv4Address(*(sockaddr_in*)next->ai_addr)));
            else if (next->ai_addr->sa_family == AF_INET6)
                ips.insert(IPv6Address::ptr(new IPv6Address(*(sockaddr_in6*)next->ai_addr)));
            next = next->ai_next;
        }
        for (auto& i : ips) {
            result.push_back(std::move(i));
        }
        freeaddrinfo(results);
        return true;
    }

    Address::ptr Address::LookupAny(const std::string& host, int family, int type, int protocol)
    {
        std::vector<Address::ptr> results;
        Lookup(results, host, family, type, protocol);
        if (!results.empty())
            return results[0];
        return Address::ptr(new UnknowAddress);
    }

    static bool operator<(const Address::ptr& lhs, const Address::ptr& rhs)
    {
        return (*lhs) < (*rhs);
    }

    bool Address::operator<(const Address& rhs) const
    {
        socklen_t minLen = std::min(getAddrLen(), rhs.getAddrLen());
        int ret = memcmp(getAddr(), rhs.getAddr(), minLen);
        if (ret < 0)
            return true;
        if (ret > 0)
            return false;
        return getAddrLen() < rhs.getAddrLen();
    }

    bool Address::operator==(const Address& rhs) const
    {
        return getAddrLen() == rhs.getAddrLen() &&
               memcmp(getAddr(), rhs.getAddr(), getAddrLen() == 0);
    }

    bool Address::operator!=(const Address& rhs) const { return !(*this == rhs); }

    /* UnixAddress */
    UnixAddress::UnixAddress(const sockaddr_un& addr) { m_addr = addr; }

    UnixAddress::UnixAddress(const std::string& path)
    {
        memset(&m_addr, 0, sizeof(m_addr));
        m_addr.sun_family = AF_LOCAL;
        m_len = path.size() + 1;

        if (path.empty() && path[0] == '\0')
            --m_len;
        if (m_len > sizeof(m_addr.sun_path)) {
            throw std::logic_error("the path too long");
        }
        memcpy(m_addr.sun_path, path.data(), m_len);
        m_len += offsetof(sockaddr_un, sun_path);
    }

    sockaddr* UnixAddress::getAddr() { return (sockaddr*)&m_addr; }

    const sockaddr* UnixAddress::getAddr() const { return (sockaddr*)&m_addr; }

    socklen_t UnixAddress::getAddrLen() const { return m_len; }

    void UnixAddress::setAddrLen(socklen_t len) { m_len = len; }

    std::string UnixAddress::toString() const
    {
        std::stringstream ss;
        if (m_len > offsetof(sockaddr_un, sun_path) && m_addr.sun_path[0] == '\0') {
            ss << "\\0"
               << std::string(m_addr.sun_path + 1, m_len - offsetof(sockaddr_un, sun_path) - 1);
        } else {
            ss << m_addr.sun_path;
        }
        return ss.str();
    }

    /* IPv4 */
    IPv4Address::IPv4Address(const sockaddr_in& addr) { m_addr = addr; }

    IPv4Address::IPv4Address(const char* address, uint16_t port)
    {
        memset(&m_addr, 0, sizeof(m_addr));
        m_addr.sin_family = AF_INET;
        m_addr.sin_port = htons(port);
        if (!address || inet_pton(AF_INET, address, &m_addr.sin_addr.s_addr) <= 0)
            m_addr.sin_addr.s_addr = INADDR_ANY;
    }

    sockaddr* IPv4Address::getAddr() { return (sockaddr*)&m_addr; }

    const sockaddr* IPv4Address::getAddr() const { return (sockaddr*)&m_addr; }

    socklen_t IPv4Address::getAddrLen() const { return sizeof(m_addr); }

    std::string IPv4Address::toString() const
    {
        std::stringstream ss;
        uint32_t addr = ntohl(m_addr.sin_addr.s_addr);
        ss << (addr >> 24) << "." << ((addr >> 16) & 0xff) << "." << ((addr >> 8) & 0xff) << "."
           << (addr & 0xff);
        ss << ":" << ntohs(m_addr.sin_port);
        return ss.str();
    }

    uint16_t IPv4Address::getPort() const { return ntohs(m_addr.sin_port); }

    void IPv4Address::setPort(uint16_t port) { m_addr.sin_port = htons(port); }

    IPv4Address::ptr IPv4Address::broadcastAddress(uint8_t mask_bits) const
    {
        if (mask_bits > 32)
            return nullptr;
        sockaddr_in addr(m_addr);
        addr.sin_addr.s_addr |= htonl(~MASKMODE(mask_bits));
        return IPv4Address::ptr(new IPv4Address(std::move(addr)));
    }

    IPv4Address::ptr IPv4Address::networkAddress(uint8_t mask_bits) const
    {
        if (mask_bits > 32)
            return nullptr;
        sockaddr_in addr(m_addr);
        addr.sin_addr.s_addr &= htonl(MASKMODE(mask_bits));
        return IPv4Address::ptr(new IPv4Address(std::move(addr)));
    }

    IPv4Address::ptr IPv4Address::subnetMask(uint8_t mask_bits) const
    {
        if (mask_bits > 32)
            return nullptr;
        sockaddr_in addr(m_addr);
        addr.sin_port = 0;
        addr.sin_addr.s_addr = htonl(MASKMODE(mask_bits));
        return IPv4Address::ptr(new IPv4Address(std::move(addr)));
    }

    /* ipv6 */
    IPv6Address::IPv6Address(const sockaddr_in6& addr) { m_addr = addr; }

    IPv6Address::IPv6Address(const char* address, uint16_t port)
    {
        memset(&m_addr, 0, sizeof(m_addr));
        m_addr.sin6_family = AF_INET6;
        m_addr.sin6_port = htons(port);
        if (!address || inet_pton(AF_INET6, address, &m_addr.sin6_addr) <= 0)
            m_addr.sin6_addr = {0};
    }

    sockaddr* IPv6Address::getAddr() { return (sockaddr*)&m_addr; }

    const sockaddr* IPv6Address::getAddr() const { return (sockaddr*)&m_addr; }

    socklen_t IPv6Address::getAddrLen() const { return sizeof(m_addr); }

    std::string IPv6Address::toString() const
    {
        std::stringstream ss;
        uint16_t* addr = (uint16_t*)m_addr.sin6_addr.s6_addr;
        bool used_zero = false;
        ss << "[";
        for (int i = 0; i < 8; ++i) {
            if (addr[i] == 0 && !used_zero)
                continue;
            if (i && addr[i - 1] == 0 && !used_zero) {
                ss << ":";
                used_zero = true;
            }
            if (i) {
                ss << ":";
            }
            ss << std::hex << ntohs(addr[i]) << std::dec;
        }
        if (!used_zero && addr[7] == 0)
            ss << "::";
        ss << "]:" << ntohs(m_addr.sin6_port);
        return ss.str();
    }

    uint16_t IPv6Address::getPort() const { return (uint32_t)ntohs(m_addr.sin6_port); }

    void IPv6Address::setPort(uint16_t port) { m_addr.sin6_port = htons(port); }

    /* Unknow */
    UnknowAddress::UnknowAddress(uint16_t family)
    {
        memset(&m_addr, 0, sizeof(m_addr));
        m_addr.sa_family = family;
    }

    sockaddr* UnknowAddress::getAddr() { return &m_addr; }

    const sockaddr* UnknowAddress::getAddr() const { return &m_addr; }

    socklen_t UnknowAddress::getAddrLen() const { return sizeof(m_addr); }

    std::string UnknowAddress::toString() const
    {
        std::stringstream ss;
        ss << "[UnknowAddress family=" << m_addr.sa_family << "]";
        return ss.str();
    }

}  // namespace miruy