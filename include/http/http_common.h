#ifndef __MIRUY_HTTP_COMMON_H__
#define __MIRUY_HTTP_COMMON_H__

/* Status Codes */
#define MIRUY_HTTP_STATUS_MAP(XX)                                                                  \
    XX(100, CONTINUE, Continue)                                                                    \
    XX(101, SWITCHING_PROTOCOLS, Switching Protocols)                                              \
    XX(102, PROCESSING, Processing)                                                                \
    XX(200, OK, OK)                                                                                \
    XX(201, CREATED, Created)                                                                      \
    XX(202, ACCEPTED, Accepted)                                                                    \
    XX(203, NON_AUTHORITATIVE_INFORMATION, Non - Authoritative Information)                        \
    XX(204, NO_CONTENT, No Content)                                                                \
    XX(205, RESET_CONTENT, Reset Content)                                                          \
    XX(206, PARTIAL_CONTENT, Partial Content)                                                      \
    XX(207, MULTI_STATUS, Multi - Status)                                                          \
    XX(208, ALREADY_REPORTED, Already Reported)                                                    \
    XX(226, IM_USED, IM Used)                                                                      \
    XX(300, MULTIPLE_CHOICES, Multiple Choices)                                                    \
    XX(301, MOVED_PERMANENTLY, Moved Permanently)                                                  \
    XX(302, FOUND, Found)                                                                          \
    XX(303, SEE_OTHER, See Other)                                                                  \
    XX(304, NOT_MODIFIED, Not Modified)                                                            \
    XX(305, USE_PROXY, Use Proxy)                                                                  \
    XX(307, TEMPORARY_REDIRECT, Temporary Redirect)                                                \
    XX(308, PERMANENT_REDIRECT, Permanent Redirect)                                                \
    XX(400, BAD_REQUEST, Bad Request)                                                              \
    XX(401, UNAUTHORIZED, Unauthorized)                                                            \
    XX(402, PAYMENT_REQUIRED, Payment Required)                                                    \
    XX(403, FORBIDDEN, Forbidden)                                                                  \
    XX(404, NOT_FOUND, Not Found)                                                                  \
    XX(405, METHOD_NOT_ALLOWED, Method Not Allowed)                                                \
    XX(406, NOT_ACCEPTABLE, Not Acceptable)                                                        \
    XX(407, PROXY_AUTHENTICATION_REQUIRED, Proxy Authentication Required)                          \
    XX(408, REQUEST_TIMEOUT, Request Timeout)                                                      \
    XX(409, CONFLICT, Conflict)                                                                    \
    XX(410, GONE, Gone)                                                                            \
    XX(411, LENGTH_REQUIRED, Length Required)                                                      \
    XX(412, PRECONDITION_FAILED, Precondition Failed)                                              \
    XX(413, PAYLOAD_TOO_LARGE, Payload Too Large)                                                  \
    XX(414, URI_TOO_LONG, URI Too Long)                                                            \
    XX(415, UNSUPPORTED_MEDIA_TYPE, Unsupported Media Type)                                        \
    XX(416, RANGE_NOT_SATISFIABLE, Range Not Satisfiable)                                          \
    XX(417, EXPECTATION_FAILED, Expectation Failed)                                                \
    XX(421, MISDIRECTED_REQUEST, Misdirected Request)                                              \
    XX(422, UNPROCESSABLE_ENTITY, Unprocessable Entity)                                            \
    XX(423, LOCKED, Locked)                                                                        \
    XX(424, FAILED_DEPENDENCY, Failed Dependency)                                                  \
    XX(426, UPGRADE_REQUIRED, Upgrade Required)                                                    \
    XX(428, PRECONDITION_REQUIRED, Precondition Required)                                          \
    XX(429, TOO_MANY_REQUESTS, Too Many Requests)                                                  \
    XX(431, REQUEST_HEADER_FIELDS_TOO_LARGE, Request Header Fields Too Large)                      \
    XX(451, UNAVAILABLE_FOR_LEGAL_REASONS, Unavailable For Legal Reasons)                          \
    XX(500, INTERNAL_SERVER_ERROR, Internal Server Error)                                          \
    XX(501, NOT_IMPLEMENTED, Not Implemented)                                                      \
    XX(502, BAD_GATEWAY, Bad Gateway)                                                              \
    XX(503, SERVICE_UNAVAILABLE, Service Unavailable)                                              \
    XX(504, GATEWAY_TIMEOUT, Gateway Timeout)                                                      \
    XX(505, HTTP_VERSION_NOT_SUPPORTED, HTTP Version Not Supported)                                \
    XX(506, VARIANT_ALSO_NEGOTIATES, Variant Also Negotiates)                                      \
    XX(507, INSUFFICIENT_STORAGE, Insufficient Storage)                                            \
    XX(508, LOOP_DETECTED, Loop Detected)                                                          \
    XX(510, NOT_EXTENDED, Not Extended)                                                            \
    XX(511, NETWORK_AUTHENTICATION_REQUIRED, Network Authentication Required)

/* Request Methods */
#define MIRUY_HTTP_METHOD_MAP(XX)                                                                  \
    XX(0, DELETE, DELETE)                                                                          \
    XX(1, GET, GET)                                                                                \
    XX(2, HEAD, HEAD)                                                                              \
    XX(3, POST, POST)                                                                              \
    XX(4, PUT, PUT)                                                                                \
    /* pathological */                                                                             \
    XX(5, CONNECT, CONNECT)                                                                        \
    XX(6, OPTIONS, OPTIONS)                                                                        \
    XX(7, TRACE, TRACE)                                                                            \
    /* WebDAV */                                                                                   \
    XX(8, COPY, COPY)                                                                              \
    XX(9, LOCK, LOCK)                                                                              \
    XX(10, MKCOL, MKCOL)                                                                           \
    XX(11, MOVE, MOVE)                                                                             \
    XX(12, PROPFIND, PROPFIND)                                                                     \
    XX(13, PROPPATCH, PROPPATCH)                                                                   \
    XX(14, SEARCH, SEARCH)                                                                         \
    XX(15, UNLOCK, UNLOCK)                                                                         \
    XX(16, BIND, BIND)                                                                             \
    XX(17, REBIND, REBIND)                                                                         \
    XX(18, UNBIND, UNBIND)                                                                         \
    XX(19, ACL, ACL)                                                                               \
    /* subversion */                                                                               \
    XX(20, REPORT, REPORT)                                                                         \
    XX(21, MKACTIVITY, MKACTIVITY)                                                                 \
    XX(22, CHECKOUT, CHECKOUT)                                                                     \
    XX(23, MERGE, MERGE)                                                                           \
    /* upnp */                                                                                     \
    XX(24, MSEARCH, M - SEARCH)                                                                    \
    XX(25, NOTIFY, NOTIFY)                                                                         \
    XX(26, SUBSCRIBE, SUBSCRIBE)                                                                   \
    XX(27, UNSUBSCRIBE, UNSUBSCRIBE)                                                               \
    /* RFC-5789 */                                                                                 \
    XX(28, PATCH, PATCH)                                                                           \
    XX(29, PURGE, PURGE)                                                                           \
    /* CalDAV */                                                                                   \
    XX(30, MKCALENDAR, MKCALENDAR)                                                                 \
    /* RFC-2068, section 19.6.1.2 */                                                               \
    XX(31, LINK, LINK)                                                                             \
    XX(32, UNLINK, UNLINK)                                                                         \
    /* icecast */                                                                                  \
    XX(33, SOURCE, SOURCE)

#include <sys/types.h>
#include <string>

namespace miruy {
namespace http {

    enum class Status {
#define XX(code, name, desc) name = code,
        MIRUY_HTTP_STATUS_MAP(XX)
#undef XX
    };

    enum class Method {
#define XX(num, name, desc) name = num,
        MIRUY_HTTP_METHOD_MAP(XX) INVALID
#undef XX
    };

}  // namespace http

http::Method StrToHttpMethod(const std::string& str);

http::Method CharsToHttpMethod(const char* str);

const char* HttpMethodToStr(http::Method method);

const char* HttpStatusToStr(http::Status status);

}  // namespace miruy

typedef void (*element_cb)(void* data, const char* at, size_t length);
typedef void (
    *field_cb)(void* data, const char* field, size_t flen, const char* value, size_t vlen);

typedef struct http_parser {
    int cs;
    size_t body_start;
    int content_len;
    size_t nread;
    size_t mark;
    size_t field_start;
    size_t field_len;
    size_t query_start;
    int xml_sent;
    int json_sent;

    void* data;

    int uri_relaxed;
    field_cb http_field;
    element_cb request_method;
    element_cb request_uri;
    element_cb fragment;
    element_cb request_path;
    element_cb query_string;
    element_cb http_version;
    element_cb header_done;

} http_parser;

int http_parser_init(http_parser* parser);
int http_parser_finish(const http_parser* parser);
size_t http_parser_execute(http_parser* parser, const char* data, size_t len, size_t off);
int http_parser_has_error(const http_parser* parser);
int http_parser_is_finished(const http_parser* parser);

typedef struct httpclient_parser {
    int cs;
    size_t body_start;
    int content_len;
    int status;
    int chunked;
    int chunks_done;
    int close;
    size_t nread;
    size_t mark;
    size_t field_start;
    size_t field_len;

    void* data;

    field_cb http_field;
    element_cb reason_phrase;
    element_cb status_code;
    element_cb chunk_size;
    element_cb http_version;
    element_cb header_done;
    element_cb last_chunk;

} httpclient_parser;

int httpclient_parser_init(httpclient_parser* parser);
int httpclient_parser_finish(const httpclient_parser* parser);
int httpclient_parser_execute(httpclient_parser* parser, const char* data, size_t len, size_t off);
int httpclient_parser_has_error(const httpclient_parser* parser);
int httpclient_parser_is_finished(const httpclient_parser* parser);

#define http_parser_nread(parser) (parser)->nread
#define httpclient_parser_nread(parser) (parser)->nread

#endif
