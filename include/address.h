#ifndef __MIRUY_ADDRESS_H__
#define __MIRUY_ADDRESS_H__

#include <memory>
#include <string>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <vector>

namespace miruy {

class Address
{
public:
    using ptr = std::shared_ptr<Address>;
    virtual ~Address() = default;

    static Address::ptr Create(const char* host, uint16_t port = 0);

    static bool Lookup(std::vector<Address::ptr>& result,
                       const std::string& host,
                       int family = AF_UNSPEC,
                       int type = 0,
                       int protocol = 0);

    static Address::ptr
    LookupAny(const std::string& host, int family = AF_UNSPEC, int type = 0, int protocol = 0);

    int getFamily() const;
    virtual std::string getIP() const { return ""; };
    virtual uint16_t getPort() const { return 0; };
    virtual void setPort(uint16_t port){};

    virtual sockaddr* getAddr() = 0;
    virtual const sockaddr* getAddr() const = 0;
    virtual socklen_t getAddrLen() const = 0;
    virtual std::string toString() const = 0;

    bool operator<(const Address& rhs) const;
    bool operator==(const Address& rhs) const;
    bool operator!=(const Address& rhs) const;
};

/* Unix/Local address */
class UnixAddress : public Address
{
public:
    using ptr = std::shared_ptr<UnixAddress>;
    UnixAddress(const sockaddr_un& addr);
    UnixAddress(const std::string& path = "");

    sockaddr* getAddr() override { return (sockaddr*)&m_addr; }
    const sockaddr* getAddr() const override { return (sockaddr*)&m_addr; }
    socklen_t getAddrLen() const override { return m_len; }
    std::string toString() const override;

    void setAddrLen(socklen_t len) { m_len = len; }

private:
    sockaddr_un m_addr;
    socklen_t m_len;
};

/* IPv4 */
class IPv4Address : public Address
{
public:
    using ptr = std::shared_ptr<IPv4Address>;
    IPv4Address(const sockaddr_in& addr);
    IPv4Address(const char* address, uint16_t port = 0);

    sockaddr* getAddr() override { return (sockaddr*)&m_addr; }
    const sockaddr* getAddr() const override { return (sockaddr*)&m_addr; }
    socklen_t getAddrLen() const override { return sizeof(sockaddr_in); }
    std::string toString() const override;

    std::string getIP() const override;
    uint16_t getPort() const override;
    void setPort(uint16_t port) override;
    IPv4Address::ptr broadcastAddress(uint8_t mask_bits) const;
    IPv4Address::ptr networkAddress(uint8_t mask_bits) const;
    IPv4Address::ptr subnetMask(uint8_t mask_bits) const;

private:
    sockaddr_in m_addr;
};

/* IPv6 */
class IPv6Address : public Address
{
public:
    using ptr = std::shared_ptr<IPv6Address>;
    IPv6Address(const sockaddr_in6& addr);
    IPv6Address(const char* address, uint16_t port = 0);

    sockaddr* getAddr() override { return (sockaddr*)&m_addr; }
    const sockaddr* getAddr() const override { return (sockaddr*)&m_addr; }
    socklen_t getAddrLen() const override { return sizeof(sockaddr_in6); }
    std::string toString() const override;

    std::string getIP() const override;
    uint16_t getPort() const override;
    void setPort(uint16_t port) override;

private:
    sockaddr_in6 m_addr;
};

class UnknowAddress : public Address
{
public:
    using ptr = std::shared_ptr<UnknowAddress>;
    UnknowAddress(uint16_t family = 0);

    sockaddr* getAddr() override { return &m_addr; }
    const sockaddr* getAddr() const override { return &m_addr; }
    socklen_t getAddrLen() const override { return sizeof(sockaddr); }
    std::string toString() const override;

private:
    sockaddr m_addr;
};

}  // namespace miruy

#endif