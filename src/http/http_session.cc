#include "http/http_session.h"

namespace miruy {
namespace http {

    Session::Session(Socket::ptr sock, bool owner) : SocketStream(sock, owner) {}

    Request::ptr Session::recvRequest()
    {
        RequestParser::ptr parser(new RequestParser);
        const uint64_t buff_size = RequestParser::GetBufferSize();
        const uint64_t max_body_size = RequestParser::GetMaxBodySize();
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
        if (length >= max_body_size)
            return nullptr;
        if (length == 0)
            return parser->getData();

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

    int Session::sendResponse(Response::ptr rsp)
    {
        std::string data = rsp->toString();
        int ret = writeFixSize(&data[0], data.size());
        return ret;
    }

}  // namespace http
}  // namespace miruy