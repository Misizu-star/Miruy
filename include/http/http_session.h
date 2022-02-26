#ifndef __MIRUY_HTTP_SESSION_H__
#define __MIRUY_HTTP_SESSION_H__

#include "socket_stream.h"
#include "http/http_parser.h"

namespace miruy {
namespace http {

    class Session : public SocketStream
    {
    public:
        using ptr = std::shared_ptr<Session>;
        Session(Socket::ptr sock, bool owner = true);

        Request::ptr recvRequest();
        int sendResponse(Response::ptr rsp);
    };

}  // namespace http
}  // namespace miruy

#endif