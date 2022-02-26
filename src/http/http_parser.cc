#include <cstring>
#include "http/http_parser.h"
#include "config.h"

namespace miruy {
namespace http {

    static ConfigVar<uint64_t>::ptr g_http_request_buffer_size =
        Config::Lookup<uint64_t>("http.request.buffer_size", 4 * 1024, "http request buffer size");

    static ConfigVar<uint64_t>::ptr g_http_request_max_body_size =
        Config::Lookup<uint64_t>("http.request.max_body_size",
                                 64 * 1024 * 1024,
                                 "http request max body size");

    static ConfigVar<uint64_t>::ptr g_http_response_buffer_size =
        Config::Lookup<uint64_t>("http.response.buffer_size",
                                 4 * 1024,
                                 "http response buffer size");

    static ConfigVar<uint64_t>::ptr g_http_response_max_body_size =
        Config::Lookup<uint64_t>("http.response.max_body_size",
                                 64 * 1024 * 1024,
                                 "http response max body size");

    static uint64_t s_request_buffer_size = 0;
    static uint64_t s_request_max_body_size = 0;
    static uint64_t s_response_buffer_size = 0;
    static uint64_t s_response_max_body_size = 0;

    namespace {
        struct _RequestSizeIniter {
            _RequestSizeIniter()
            {
                s_request_buffer_size = g_http_request_buffer_size->getValue();
                s_request_max_body_size = g_http_request_max_body_size->getValue();
                s_response_buffer_size = g_http_response_buffer_size->getValue();
                s_response_max_body_size = g_http_response_max_body_size->getValue();

                g_http_request_buffer_size->addListener(
                    [](const uint64_t& ov, const uint64_t& nv) { s_request_buffer_size = nv; });

                g_http_request_max_body_size->addListener(
                    [](const uint64_t& ov, const uint64_t& nv) { s_request_max_body_size = nv; });

                g_http_response_buffer_size->addListener(
                    [](const uint64_t& ov, const uint64_t& nv) { s_request_buffer_size = nv; });

                g_http_response_max_body_size->addListener(
                    [](const uint64_t& ov, const uint64_t& nv) { s_request_max_body_size = nv; });
            }
        };

        static _RequestSizeIniter _init;
    }  // namespace

    uint64_t RequestParser::GetBufferSize() { return s_request_buffer_size; }

    uint64_t RequestParser::GetMaxBodySize() { return s_request_max_body_size; }

    uint64_t ResponseParser::GetBufferSize() { return s_response_buffer_size; }

    uint64_t ResponseParser::GetMaxBodySize() { return s_response_max_body_size; }

    static void
    on_req_field(void* data, const char* field, size_t flen, const char* value, size_t vlen)
    {
        http::RequestParser* parser = static_cast<http::RequestParser*>(data);
        if (flen == 0)
            parser->setError(0x0300);
        else
            parser->getData()->setHeader(std::string(field, flen), std::string(value, vlen));
    }

    static void on_req_method(void* data, const char* at, size_t length)
    {
        http::RequestParser* parser = static_cast<http::RequestParser*>(data);
        http::Method m = CharsToHttpMethod(at);
        if (http::Method::INVALID == m)
            parser->setError(0x0100);
        else
            parser->getData()->setMethod(m);
    }

    static void on_req_uri(void* data, const char* at, size_t length) {}

    static void on_req_fragment(void* data, const char* at, size_t length)
    {
        http::RequestParser* parser = static_cast<http::RequestParser*>(data);
        parser->getData()->setFragment(std::string(at, length));
    }

    static void on_req_path(void* data, const char* at, size_t length)
    {
        http::RequestParser* parser = static_cast<http::RequestParser*>(data);
        parser->getData()->setPath(std::string(at, length));
    }

    static void on_req_query(void* data, const char* at, size_t length)
    {
        http::RequestParser* parser = static_cast<http::RequestParser*>(data);
        parser->getData()->setQuery(std::string(at, length));
    }

    static void on_req_version(void* data, const char* at, size_t length)
    {
        http::RequestParser* parser = static_cast<http::RequestParser*>(data);
        uint8_t ver = 0x0;
        if (strncmp(at, "HTTP/1.1", length) == 0)
            ver = 0x11;
        else if (strncmp(at, "HTTP/1.0", length) == 0)
            ver = 0x10;
        else {
            parser->setError(0x0200);
            return;
        }
        parser->getData()->setVersion(ver);
    }

    static void on_req_done(void* data, const char* at, size_t length) {}

    RequestParser::RequestParser() : m_error(0)
    {
        m_data.reset(new http::Request);
        http_parser_init(&m_parser);
        m_parser.http_field = on_req_field;
        m_parser.request_method = on_req_method;
        m_parser.request_uri = on_req_uri;
        m_parser.fragment = on_req_fragment;
        m_parser.request_path = on_req_path;
        m_parser.query_string = on_req_query;
        m_parser.http_version = on_req_version;
        m_parser.header_done = on_req_done;
        m_parser.data = this;
    }

    bool RequestParser::hasError() const
    {
        return m_error || http_parser_has_error(&m_parser);
        ;
    }

    bool RequestParser::isFinished() const { return http_parser_is_finished(&m_parser); }

    size_t RequestParser::getContentLen() const
    {
        return m_data->getHeader<size_t>("content-length");
    }

    size_t RequestParser::execute(char* data, size_t len)
    {
        size_t ret = http_parser_execute(&m_parser, data, len, 0);
        memmove(data, data + ret, len - ret);
        return ret;
    }

    /* ResponseParser */

    static void
    on_rsp_field(void* data, const char* field, size_t flen, const char* value, size_t vlen)
    {
        http::ResponseParser* parser = static_cast<http::ResponseParser*>(data);
        if (flen == 0)
            parser->setError(0x1300);
        else
            parser->getData()->setHeader(std::string(field, flen), std::string(value, vlen));
    }

    static void on_rsp_reason(void* data, const char* at, size_t length)
    {
        http::ResponseParser* parser = static_cast<http::ResponseParser*>(data);
        parser->getData()->setReason(std::string(at, length));
    }

    static void on_rsp_status(void* data, const char* at, size_t length)
    {
        http::ResponseParser* parser = static_cast<http::ResponseParser*>(data);
        parser->getData()->setStatus((http::Status)(atoi(at)));
    }

    static void on_rsp_chunk(void* data, const char* at, size_t length) {}

    static void on_rsp_version(void* data, const char* at, size_t length)
    {
        http::ResponseParser* parser = static_cast<http::ResponseParser*>(data);
        uint8_t ver = 0x0;
        if (strncmp("HTTP/1.1", at, length) == 0)
            ver = 0x11;
        else if (strncmp("HTTP/1.0", at, length))
            ver = 0x10;
        else {
            parser->setError(0x1200);
            return;
        }
        parser->getData()->setVersion(ver);
    }

    static void on_rsp_header(void* data, const char* at, size_t length) {}

    static void on_rsp_last_chunk(void* data, const char* at, size_t length) {}

    ResponseParser::ResponseParser() : m_error(0)
    {
        m_data.reset(new http::Response);
        httpclient_parser_init(&m_parser);
        m_parser.http_field = on_rsp_field;
        m_parser.reason_phrase = on_rsp_reason;
        m_parser.status_code = on_rsp_status;
        m_parser.chunk_size = on_rsp_chunk;
        m_parser.http_version = on_rsp_version;
        m_parser.header_done = on_rsp_header;
        m_parser.last_chunk = on_rsp_last_chunk;
        m_parser.data = this;
    }

    int ResponseParser::hasError() const
    {
        return m_error || httpclient_parser_has_error(&m_parser);
    }

    bool ResponseParser::isFinished() const { return httpclient_parser_finish(&m_parser); }

    size_t ResponseParser::getContentLen() const
    {
        return m_data->getHeader<size_t>("content-length");
    }

    size_t ResponseParser::execute(char* data, size_t len)
    {
        size_t ret = httpclient_parser_execute(&m_parser, data, len, 0);
        memmove(data, data + ret, len - ret);
        return ret;
    }

}  // namespace http

http::Method StrToHttpMethod(const std::string& str)
{
#define XX(num, name, desc)                                                                        \
    if (strcasecmp(#name, str.data()) == 0)                                                        \
        return http::Method::name;
    MIRUY_HTTP_METHOD_MAP(XX)
#undef XX
    return http::Method::INVALID;
}

http::Method CharsToHttpMethod(const char* str)
{
#define XX(num, name, desc)                                                                        \
    if (strncasecmp(#name, str, strlen(#name)) == 0)                                               \
        return http::Method::name;
    MIRUY_HTTP_METHOD_MAP(XX)
#undef XX
    return http::Method::INVALID;
}

const char* HttpMethodToStr(http::Method method)
{
    switch (method) {
#define XX(num, name, desc)                                                                        \
    case http::Method::name: return #name;
        MIRUY_HTTP_METHOD_MAP(XX)
        default: return "INVALID";
#undef XX
    }
}

const char* HttpStatusToStr(http::Status status)
{
    switch (status) {
#define XX(num, name, desc)                                                                        \
    case http::Status::name: return #desc;
        MIRUY_HTTP_STATUS_MAP(XX)
        default: return "Invalid code";
#undef XX
    }
}

}  // namespace miruy