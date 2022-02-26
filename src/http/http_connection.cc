#include "http/http_connection.h"
#include "log.h"

namespace miruy {
namespace http {

    ReqResult::ptr Connection::DoGet(const std::string& uri,
                                     uint64_t timeout,
                                     const Request::MapType& headers,
                                     const std::string& body)
    {
        return DoRequest(Method::GET, uri, timeout, headers, body);
    }

    ReqResult::ptr Connection::DoGet(Uri::ptr uri,
                                     uint64_t timeout,
                                     const Request::MapType& headers,
                                     const std::string& body)
    {
        return DoRequest(Method::GET, uri, timeout, headers, body);
    }

    ReqResult::ptr Connection::DoPost(const std::string& uri,
                                      uint64_t timeout,
                                      const Request::MapType& headers,
                                      const std::string& body)
    {
        return DoRequest(Method::POST, uri, timeout, headers, body);
    }

    ReqResult::ptr Connection::DoPost(Uri::ptr uri,
                                      uint64_t timeout,
                                      const Request::MapType& headers,
                                      const std::string& body)
    {
        return DoRequest(Method::POST, uri, timeout, headers, body);
    }

    ReqResult::ptr Connection::DoRequest(Method method,
                                         const std::string& uri,
                                         uint64_t timeout,
                                         const Request::MapType& headers,
                                         const std::string& body)
    {
        Uri::ptr req_uri = Uri::Create(uri);
        if (!req_uri)
            return ReqResult::ptr(new ReqResult(-1, nullptr, "bad uri"));
        return DoRequest(method, req_uri, timeout, headers, body);
    }

    ReqResult::ptr Connection::DoRequest(Method method,
                                         Uri::ptr uri,
                                         uint64_t timeout,
                                         const Request::MapType& headers,
                                         const std::string& body)
    {
        if (!uri)
            return ReqResult::ptr(new ReqResult(-1, nullptr, "bad uri"));
        Request::ptr req(new Request);
        req->setMethod(method);
        req->setPath(uri->getPath());
        req->setQuery(uri->getQuery());
        req->setFragment(uri->getFrag());
        for (auto& it : headers)
            req->setHeader(it.first, it.second);

        auto it = headers.find("host");
        if (it == headers.end())
            req->setHeader("Host", uri->getAddress()->toString());

        std::string tmp = GetMapValue<Request::MapType, std::string>(headers, "Connection");
        req->setClose(tmp == "keep-alive");

        if (!body.empty())
            req->setBody(body);

        return DoRequest(req, uri, timeout);
    }

    ReqResult::ptr Connection::DoRequest(Request::ptr req, Uri::ptr uri, uint64_t timeout)
    {
        if (uri == nullptr)
            return std::make_shared<ReqResult>(-1, nullptr, "bad uri");
        // host解析
        auto addr = uri->getAddress();
        if (!addr)
            return std::make_shared<ReqResult>(-2, nullptr, "bad host");

        Socket::ptr sock = Socket::CreateTCP(addr);
        sock->setRecvTimeout(timeout);
        // 连接服务端
        if (!sock->connect(addr)) {
            return std::make_shared<ReqResult>(-3, nullptr, "connnect timeout");
        }

        Connection::ptr conn(new Connection(sock));
        // 发送请求
        int ret = conn->sendRequest(req);
        if (ret == 0)
            return std::make_shared<ReqResult>(-4, nullptr, "send request closed by peer");
        if (ret < 0)
            return std::make_shared<ReqResult>(-5, nullptr, "send request error");

        // 接受响应
        auto rsp = conn->recvRsponse();
        if (!rsp) {
            return std::make_shared<ReqResult>(-6, nullptr, "recv response timeout");
        }
        return std::make_shared<ReqResult>(0, rsp, "OK");
    }

    Connection::Connection(Socket::ptr sock, bool owner) : SocketStream(sock, owner) {}

    Response::ptr Connection::recvRsponse()
    {
        ResponseParser::ptr parser(new ResponseParser);
        const uint64_t buff_size = ResponseParser::GetBufferSize();
        const uint64_t max_body_size = ResponseParser::GetMaxBodySize();
        std::shared_ptr<char> buff(new char[buff_size], [](char* ptr) { delete[] ptr; });
        char* data = buff.get();
        size_t offset = 0, total = 0;
        do {
            int len = read(data + offset, buff_size - offset);
            total += len;
            if (len <= 0 || total > buff_size)
                return nullptr;
            size_t n = parser->execute(data, len + offset);
            if (parser->hasError())
                return nullptr;
            offset += len - n;
        } while (!parser->isFinished());

        size_t length = parser->getContentLen();
        if (length == 0)
            return parser->getData();
        if (length >= max_body_size)
            return nullptr;

        std::string body;
        body.resize(length);
        memcpy(&body[0], data, offset);
        int64_t left = (int64_t)length - offset, len;
        while (left > 0) {
            len = left > buff_size ? buff_size : left;
            readFixSize(data, len);
            left -= len;
            memcpy(&body[offset], data, len);
            offset += len;
        }
        parser->getData()->setBody(std::move(body));
        return parser->getData();
    }

    int Connection::sendRequest(Request::ptr req)
    {
        std::string str = req->toString();
        return writeFixSize(&str[0], str.size());
    }

    ConnectionPool::ConnectionPool(const std::string& host,
                                   const std::string& vhost,
                                   uint32_t port,
                                   uint32_t max_size,
                                   uint32_t max_request)
        : m_host(host), m_port(port), m_maxSize(max_size), m_maxRequest(max_request)
    {
        Uri::ptr uri = Uri::Create(m_host);
        if (!uri) {
            LOG_ERROR(LOGGER("system")) << "host error, host: " << m_host;
            throw std::logic_error("host error");
        }

        Address::ptr addr = Address::LookupAny(uri->getHost());
        m_sock = Socket::CreateTCPSocket();
        if (!m_sock->connect(addr)) {
            LOG_ERROR(LOGGER("system")) << "connect  fail, socket:" << m_sock->toString()
                                        << " host:" << m_host << " address:" << addr->toString();
            throw std::logic_error("connect fail");
        }
        m_addr = addr->toString();
    }

    ReqResult::ptr ConnectionPool::doGet(const std::string& url,
                                         uint64_t timeout,
                                         const Request::MapType& headers,
                                         const std::string& body)
    {
        return doRequest(Method::GET, url, timeout, headers, body);
    }

    ReqResult::ptr ConnectionPool::doPost(const std::string& url,
                                          uint64_t timeout,
                                          const Request::MapType& headers,
                                          const std::string& body)
    {
        return doRequest(Method::POST, url, timeout, headers, body);
    }

    ReqResult::ptr ConnectionPool::doRequest(Method method,
                                             const std::string& url,
                                             uint64_t timeout,
                                             const Request::MapType& headers,
                                             const std::string& body)
    {
        Uri::ptr uri = Uri::Create(m_host + url);
        if (!uri)
            return ReqResult::ptr(new ReqResult(-1, nullptr, "bad url"));
        Request::ptr req(new Request);
        req->setMethod(method);
        req->setPath(uri->getPath());
        req->setQuery(uri->getQuery());
        req->setFragment(uri->getFrag());

        for (auto& it : headers)
            req->setHeader(it.first, it.second);

        auto it = headers.find("host");
        if (it == headers.end())
            req->setHeader("Host", m_addr);
        if (!body.empty())
            req->setBody(body);

        Connection::ptr conn = getConnection();
        m_sock->setRecvTimeout(timeout);

        // 发送请求
        int ret = conn->sendRequest(req);
        if (ret == 0)
            return std::make_shared<ReqResult>(-4, nullptr, "send request closed by peer");
        if (ret < 0)
            return std::make_shared<ReqResult>(-5, nullptr, "send request error");

        // 接受响应
        auto rsp = conn->recvRsponse();
        if (!rsp) {
            return std::make_shared<ReqResult>(-6, nullptr, "recv response timeout");
        }
        return std::make_shared<ReqResult>(0, rsp, "OK");
    }

}  // namespace http
}  // namespace miruy