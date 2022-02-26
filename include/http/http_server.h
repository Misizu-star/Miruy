#ifndef __MIRUY_HTTP_SERVER_H__
#define __MIRUY_HTTP_SERVER_H__

#include "tcp_server.h"
#include "http/http_servlet.h"

namespace miruy {
namespace http {

    class Server : public TcpServer
    {
    public:
        using ptr = std::shared_ptr<Server>;
        Server(bool keepalive = false,
               uint32_t work_ths = 0,
               IOManager* iom = IOManager::GetThis(),
               const std::string& work_name = "work");

        Dispatch::ptr getDispatch() const { return m_dispatch; }
        void setDispatch(Dispatch::ptr dispatch) { m_dispatch = dispatch; }

    protected:
        virtual void handleClient(Socket::ptr client);

    private:
        bool m_keepalive;
        Dispatch::ptr m_dispatch;
    };

}  // namespace http
}  // namespace miruy

#endif