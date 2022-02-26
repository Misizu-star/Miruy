#ifndef __MIRUY_TCP_SERVER_H__
#define __MIRUY_TCP_SERVER_H__

#include <memory>
#include <vector>
#include "socket.h"
#include "iomanager.h"
#include "noncopy.h"

namespace miruy {

class TcpServer : public std::enable_shared_from_this<TcpServer>, NonCopy
{
public:
    using ptr = std::shared_ptr<TcpServer>;
    TcpServer(uint32_t work_ths = 0,
              IOManager* iom = IOManager::GetThis(),
              const std::string& work_name = "work");
    virtual ~TcpServer();

    virtual bool bind(Address::ptr addr);
    virtual bool bind(const std::vector<Address::ptr>& addrs,
                      std::vector<Address::ptr>& fail_addrs);
    virtual void start();
    virtual void stop();

    uint64_t getReadTimeout() const { return m_readTimeout; }
    void setReadTimeout(uint64_t timeout) { m_readTimeout = timeout; }

    const std::string& getName() const { return m_name; }
    void setName(const std::string& name) { m_name = name; }

    const std::vector<Socket::ptr>& getSockets() const { return m_socks; }

    bool isStop() const { return !m_running; }

protected:
    virtual void handleClient(Socket::ptr client);
    virtual void startAccept(Socket::ptr sock);

private:
    bool m_running{ false };
    IOManager* m_accept;
    IOManager* m_work;
    uint64_t m_readTimeout;
    std::string m_name;
    std::vector<Socket::ptr> m_socks;
};

}  // namespace miruy

#endif