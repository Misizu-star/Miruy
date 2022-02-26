#include <sstream>
#include "http/http_parser.h"

namespace miruy {
namespace http {

    bool IgnoreCase::operator()(const std::string& lhs, const std::string& rhs) const
    {
        return strcasecmp(lhs.data(), rhs.data()) < 0;
    }

    /* Request */
    Request::Request(const std::string& path, uint8_t version, bool close)
        : m_method(http::Method::GET), m_version(version), m_close(close)
    {
        m_close = m_version == 0x10 ? true : m_close;
        m_path = path;
    }

    bool Request::hasParam(const std::string& key) const
    {
        auto it = m_params.find(key);
        return !(it == m_params.end() || it->second.empty());
    }

    bool Request::hasHeader(const std::string& key) const
    {
        auto it = m_headers.find(key);
        return !(it == m_headers.end() || it->second.empty());
    }

    bool Request::hasCookie(const std::string& key) const
    {
        auto it = m_cookies.find(key);
        return !(it == m_cookies.end() || it->second.empty());
    }

    void Request::delParam(const std::string& key) { m_params.erase(key); }

    void Request::delHeader(const std::string& key) { m_headers.erase(key); }

    void Request::delCookie(const std::string& key) { m_cookies.erase(key); }

    void Request::clear()
    {
        m_path = m_query = m_fragment = m_body = "";
        m_headers.clear();
        m_params.clear();
        m_cookies.clear();
    }

    std::ostream& Request::dump(std::ostream& os) const
    {
        os << HttpMethodToStr(m_method) << " " << m_path << (m_query.empty() ? "" : "?") << m_query;
        os << (m_fragment.empty() ? "" : "#") << m_fragment;
        os << " HTTP/" << (m_version >> 4) << "." << (m_version & 0x0f) << "\r\n";

        if (m_headers.find("connection") == m_headers.end())
            os << "Connection: " << (m_close ? "close" : "keep-alive") << "\r\n";
        for (auto& i : m_headers)
            os << i.first << ": " << i.second << "\r\n";
        if (m_headers.find("Content-length") == m_headers.end() && !m_body.empty())
            os << "Content-length: " << m_body.size() << "\r\n";
            
        os << "\r\n" << m_body;
        return os;
    }

    std::string Request::toString() const
    {
        std::stringstream ss;
        dump(ss);
        return ss.str();
    }

    /* Response */
    Response::Response(uint8_t version, bool close)
        : m_status(http::Status::OK), m_version(version), m_close(close)
    {
        m_close = m_version == 0x10 ? true : m_close;
    }

    bool Response::hasHeader(const std::string& key) const
    {
        auto it = m_headers.find(key);
        return !(it == m_headers.end() || it->second.empty());
    }

    void Response::delHeader(const std::string& key) { m_headers.erase(key); }

    void Response::clear()
    {
        m_status = http::Status::OK;
        m_headers.clear();
        m_body = m_reason = "";
    }

    std::ostream& Response::dump(std::ostream& os) const
    {
        os << "HTTP/" << (m_version >> 4) << "." << (m_version & 0x0f) << " ";
        os << (uint32_t)m_status << " " << (m_reason.empty() ? HttpStatusToStr(m_status) : m_reason)
           << "\r\n";

        if (m_headers.find("connection") != m_headers.end())
            os << "Connection: " << (m_close ? "close" : "keep-alive") << "\r\n";
        for (auto& i : m_headers)
            os << i.first << ": " << i.second << "\r\n";

        if (m_headers.find("Content-length") == m_headers.end())
            os << "Content-length: " << m_body.size() << "\r\n";
        os << "\r\n" << m_body;
        return os;
    }

    std::string Response::toString() const
    {
        std::stringstream ss;
        dump(ss);
        return ss.str();
    }

}  // namespace http
}  // namespace miruy