#include "http/http_server.h"
#include "http/http_session.h"
#include "log.h"

namespace miruy {
namespace http {

    Server::Server(bool keepalive, uint32_t work_ths, IOManager* iom, const std::string& work_name)
        : TcpServer(work_ths, iom, work_name), m_keepalive(keepalive)
    {
        m_dispatch.reset(new Dispatch);
    }

    void Server::handleClient(Socket::ptr client)
    {
        http::Session::ptr session(new http::Session(client));
        Request::ptr req;
        do {
            req = session->recvRequest();
            if (!req) {
                if (errno == 11)
                    LOG_INFO(LOGGER("system"))
                        << "total fiber: " << Fiber::TotalFibers() << " client:["
                        << client->getRemoteAddress()->toString() << "] closed";
                else
                    LOG_WARN(LOGGER("system")) << "recv http request fail, "
                                               << " errstr: " << strerror(errno) << "client: ["
                                               << client->getRemoteAddress()->toString() << "]";
                break;
            }
            Response::ptr rsp(new Response(req->getVersion(), req->isClose() || m_keepalive));
            m_dispatch->handle(req, rsp, session);
            session->sendResponse(rsp);
        } while (m_keepalive);

        session->close();
    }

}  // namespace http
}  // namespace miruy