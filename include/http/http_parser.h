#ifndef __MIRUY_HTTP_PARSER_H__
#define __MIRUY_HTTP_PARSER_H__

#include <memory>
#include <map>
#include <ostream>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include "http/http_common.h"
#include "type.h"

namespace miruy {
namespace http {

    struct IgnoreCase {
        bool operator()(const std::string& lhs, const std::string& rhs) const;
    };

    /**
     * @brief 从 map 中, 通过 key 获取得对应 value
     * @tparam M std::map, key 为 std::string
     * @tparam T 期望获取的类型
     * @param map 数据容器
     * @param key 键
     * @return 若 map 中存在该 kay, 返回对应值；否则返回 默认构造的 T
     */
    template <class M, class T>
    is_simple_type_t<T> GetMapValue(const M& map, const std::string& key)
    {
        auto it = map.find(key);
        if (it != map.end() && !it->second.empty()) {
            try {
                return boost::lexical_cast<T>(it->second);
            } catch (...) {
            }
        }
        return std::is_arithmetic<T>::value ? static_cast<T>(0) : T();
    }

    /**
     * @brief 设置 map 中 key 对应的 value
     * @tparam M std::map, key 为 std::string
     * @tparam T 设置 value 类型
     * @tparam class 过滤类型所需类, 默认为 simple_type 类型
     * @param map 数据容器
     * @param key 键
     * @param val 键对应值
     * @return 若该值具有意义, 则设置成功，返回 true; 否则返回 false
     */
    template <class M, class T, class = is_simple_type_t<T>>
    bool SetMapValue(M& map, const std::string& key, const T& val)
    {
        try {
            std::string v = boost::lexical_cast<std::string>(val);
            if (!v.empty()) {
                map[key] = std::move(v);
                return true;
            }
        } catch (...) {
        }
        return false;
    }

    class Request
    {
    public:
        using ptr = std::shared_ptr<Request>;
        using MapType = std::map<std::string, std::string, IgnoreCase>;
        Request(const std::string& path = "/", uint8_t version = 0x11, bool close = false);

        http::Method getMethod() const { return m_method; }
        uint8_t getVersion() const { return m_version; }
        bool isClose() const { return m_close; }

        const std::string& getPath() const { return m_path; }
        const std::string& getBody() const { return m_body; }
        const std::string& getQuery() const { return m_query; }
        const std::string& getFragment() const { return m_fragment; }

        const MapType& getParams() const { return m_params; }
        const MapType& getHeaders() const { return m_headers; }
        const MapType& getCookies() const { return m_cookies; }

        void setClose(bool val) { m_close = val; }
        void setMethod(http::Method m) { m_method = m; }
        void setVersion(uint8_t ver) { m_version = ver; }

        void setPath(const std::string& path) { m_path = path; }
        void setBody(const std::string& body) { m_body = body; }
        void setQuery(const std::string& val) { m_query = val; }
        void setFragment(const std::string& val) { m_fragment = val; }

        bool hasParam(const std::string& key) const;
        bool hasHeader(const std::string& key) const;
        bool hasCookie(const std::string& key) const;

        void delParam(const std::string& key);
        void delHeader(const std::string& key);
        void delCookie(const std::string& key);

        template <class T = std::string>
        T getParam(const std::string& key) const
        {
            return GetMapValue<MapType, T>(m_params, key);
        }

        template <class T = std::string>
        T getHeader(const std::string& key) const
        {
            return GetMapValue<MapType, T>(m_headers, key);
        }

        template <class T = std::string>
        T getCookie(const std::string& key) const
        {
            return GetMapValue<MapType, T>(m_cookies, key);
        }

        template <class T = std::string>
        void setParam(const std::string& key, const T& value)
        {
            SetMapValue<MapType, T>(m_params, key, value);
        }

        template <class T = std::string>
        void setHeader(const std::string& key, const T& value)
        {
            SetMapValue<MapType, T>(m_headers, key, value);
        }

        template <class T = std::string>
        void setCookie(const std::string& key, const T& value)
        {
            SetMapValue<MapType, T>(m_cookies, key, value);
        }

        void clear();
        std::ostream& dump(std::ostream& os) const;
        std::string toString() const;

    private:
        http::Method m_method;
        uint8_t m_version;
        bool m_close;

        std::string m_path;     /* 请求路径 */
        std::string m_query;    /* 查询数据 */
        std::string m_fragment; /* 信息片段 */
        std::string m_body;     /* 请求体   */

        MapType m_headers;
        MapType m_params;
        MapType m_cookies;
    };

    class Response
    {
    public:
        using ptr = std::shared_ptr<Response>;
        using MapType = std::map<std::string, std::string, IgnoreCase>;
        Response(uint8_t version = 0x11, bool close = false);

        http::Status getStatus() const { return m_status; }
        uint8_t getVersion() const { return m_version; }

        const std::string& getBody() const { return m_body; }
        const std::string& getReason() const { return m_reason; }
        const MapType& getHeaders() const { return m_headers; }

        void setStatus(http::Status code) { m_status = code; }
        void setVersion(uint8_t ver) { m_version = ver; }
        void setBody(const std::string& val) { m_body = val; }
        void setReason(const std::string& val) { m_reason = val; }

        bool isClose() const { return m_close; }
        void setClose(bool val) { m_close = val; }

        bool hasHeader(const std::string& key) const;
        void delHeader(const std::string& key);

        template <class T = std::string>
        T getHeader(const std::string& key) const
        {
            return GetMapValue<MapType, T>(m_headers, key);
        }

        template <class T = std::string>
        void setHeader(const std::string& key, const T& value)
        {
            SetMapValue<MapType, T>(m_headers, key, value);
        }

        void clear();
        std::ostream& dump(std::ostream& os) const;
        std::string toString() const;

    private:
        http::Status m_status;
        uint8_t m_version;
        bool m_close;

        std::string m_body;
        std::string m_reason;
        MapType m_headers;
    };

    class RequestParser
    {
    public:
        using ptr = std::shared_ptr<RequestParser>;
        RequestParser();

        bool hasError() const;
        bool isFinished() const;
        size_t getContentLen() const;
        void setError(int16_t err) { m_error = err; }
        http::Request::ptr getData() const { return m_data; }
        size_t execute(char* data, size_t len);

        static uint64_t GetBufferSize();
        static uint64_t GetMaxBodySize();

    private:
        http_parser m_parser;
        Request::ptr m_data;
        int m_error;
    };

    class ResponseParser
    {
    public:
        using ptr = std::shared_ptr<ResponseParser>;
        ResponseParser();

        int hasError() const;
        bool isFinished() const;

        size_t getContentLen() const;
        void setError(int err) { m_error = err; }
        http::Response::ptr getData() const { return m_data; }
        size_t execute(char* data, size_t len);

        static uint64_t GetBufferSize();
        static uint64_t GetMaxBodySize();

    private:
        httpclient_parser m_parser;
        Response::ptr m_data;
        int m_error;
    };

    /**
     * m_error: 请求/响应包 错误码
     * method error     0x0100/0x1100 (req/rsp)
     * version error    0x0200/0x1200 (req/rsp)
     * set field error  0x0300/0x1300 (req/rsp)
     */

}  // namespace http
}  // namespace miruy

#endif