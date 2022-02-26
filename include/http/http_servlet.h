#ifndef __MIRUY_HTTP_SERVLET_H__
#define __MIRUY_HTTP_SERVLET_H__

#include <memory>
#include <string>
#include <functional>
#include <vector>
#include <unordered_map>
#include "http/http_parser.h"
#include "http/http_session.h"
#include "mutex.h"

namespace miruy {
namespace http {

    class Servlet
    {
    public:
        using ptr = std::shared_ptr<Servlet>;
        using fun = std::function<void(Request::ptr, Response::ptr, Session::ptr)>;
        Servlet(const std::string& name) : m_name(name) {}
        virtual ~Servlet() = default;

        virtual void handle(Request::ptr req, Response::ptr rsp, Session::ptr session) = 0;

        const std::string& getName() const { return m_name; }

    protected:
        std::string m_name;
    };

    class FunServlet : public Servlet
    {
    public:
        using ptr = std::shared_ptr<FunServlet>;
        FunServlet(Servlet::fun cb);

        virtual void handle(Request::ptr req, Response::ptr rsp, Session::ptr session) override;

    private:
        Servlet::fun m_cb;
    };

    class Dispatch : public Servlet
    {
    public:
        using ptr = std::shared_ptr<Dispatch>;
        using RWMutexType = RWMutex;
        Dispatch();

        void addServlet(const std::string& uri, Servlet::ptr slt);
        void addServlet(const std::string& uri, Servlet::fun cb);
        void delServlet(const std::string& uri);

        Servlet::ptr getDefaultServlet() const { return m_def_slt; }
        void setDefaultServlet(Servlet::ptr slt) { m_def_slt = slt; }
        Servlet::ptr getServlet(const std::string& uri) const;

        virtual void handle(Request::ptr req, Response::ptr rsp, Session::ptr session) override;

    private:
        mutable RWMutexType m_mutex;
        Servlet::ptr m_def_slt;
        std::unordered_map<std::string, Servlet::ptr> m_precise;
        std::vector<std::pair<std::string, Servlet::ptr>> m_match;
    };

    class NotFountServlet : public Servlet
    {
    public:
        using ptr = std::shared_ptr<NotFountServlet>;
        NotFountServlet();

        virtual void handle(http::Request::ptr requestion,
                            http::Response::ptr response,
                            http::Session::ptr session) override;
    };

}  // namespace http
}  // namespace miruy

#endif