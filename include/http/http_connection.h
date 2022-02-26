#ifndef __MIRUY_HTTP_CONNECT_H__
#define __MIRUY_HTTP_CONNECT_H__

#include <list>
#include "uri.h"
#include "mutex.h"
#include "socket_stream.h"
#include "http/http_parser.h"

namespace miruy {
namespace http {

    struct ReqResult {
        using ptr = std::shared_ptr<ReqResult>;
        ReqResult(int _code, Response::ptr _rsp, const std::string& _err)
            : code(_code), rsp(_rsp), err(_err)
        {
        }

        int code; /* 成功则为 0 */
        Response::ptr rsp;
        std::string err;
    };

    class Connection : public SocketStream
    {
    public:
        using ptr = std::shared_ptr<Connection>;

        static ReqResult::ptr DoGet(const std::string& uri,
                                    uint64_t timeout,
                                    const Request::MapType& headers = {},
                                    const std::string& body = "");

        static ReqResult::ptr DoGet(Uri::ptr uri,
                                    uint64_t timeout,
                                    const Request::MapType& headers = {},
                                    const std::string& body = "");

        static ReqResult::ptr DoPost(const std::string& uri,
                                     uint64_t timeout,
                                     const Request::MapType& headers = {},
                                     const std::string& body = "");

        static ReqResult::ptr DoPost(Uri::ptr uri,
                                     uint64_t timeout,
                                     const Request::MapType& headers = {},
                                     const std::string& body = "");

        static ReqResult::ptr DoRequest(Method method,
                                        const std::string& uri,
                                        uint64_t timeout,
                                        const Request::MapType& headers = {},
                                        const std::string& body = "");

        static ReqResult::ptr DoRequest(Method method,
                                        Uri::ptr uri,
                                        uint64_t timeout,
                                        const Request::MapType& headers = {},
                                        const std::string& body = "");

        static ReqResult::ptr DoRequest(Request::ptr req, Uri::ptr uri, uint64_t timeout);

        Connection(Socket::ptr sock, bool owner = true);

        Response::ptr recvRsponse();
        int sendRequest(Request::ptr req);
    };

    class ConnectionPool
    {
    private:
        using ptr = std::shared_ptr<ConnectionPool>;
        using MutexType = Mutex;
        ConnectionPool(const std::string& host,
                       const std::string& vhost,
                       uint32_t port,
                       uint32_t max_size,
                       uint32_t max_request);

        Connection::ptr getConnection();

        ReqResult::ptr doGet(const std::string& url,
                             uint64_t timeout,
                             const Request::MapType& headers = {},
                             const std::string& body = "");

        ReqResult::ptr doPost(const std::string& url,
                              uint64_t timeout,
                              const Request::MapType& headers = {},
                              const std::string& body = "");

        ReqResult::ptr doRequest(Method method,
                                 const std::string& url,
                                 uint64_t timeout,
                                 const Request::MapType& headers = {},
                                 const std::string& body = "");

    private:
        static void ReleaseConPtr(Connection* ptr, ConnectionPool* pool);

    private:
        Socket::ptr m_sock;
        std::string m_host;
        std::string m_addr;
        uint32_t m_port;
        uint32_t m_maxSize;
        uint32_t m_maxRequest;
        MutexType m_mutex;

        std::list<Connection*> m_pool;
        std::atomic<uint32_t> m_total{ 0 };
    };

}  // namespace http
}  // namespace miruy

#endif