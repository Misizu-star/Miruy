#include <fnmatch.h>
#include "http/http_servlet.h"

namespace miruy {
namespace http {

    FunServlet::FunServlet(Servlet::fun cb) : Servlet("FunServlet"), m_cb(cb) {}

    void FunServlet::handle(Request::ptr req, Response::ptr rsp, Session::ptr session)
    {
        if (m_cb)
            m_cb(req, rsp, session);
    }

    Dispatch::Dispatch() : Servlet("DispatchServlet") { m_def_slt.reset(new NotFountServlet); }

    void Dispatch::addServlet(const std::string& uri, Servlet::ptr slt)
    {
        RWMutexType::WriteLock lock(m_mutex);
        // 精确匹配
        if (uri.find_first_of('*') == std::string::npos) {
            m_precise[uri] = slt;
            return;
        }

        // 通配符匹配
        for (auto it = m_match.begin(); it != m_match.end(); ++it) {
            if (it->first == uri) {
                m_match.erase(it);
                break;
            }
        }
        m_match.push_back(std::make_pair(uri, slt));
    }

    void Dispatch::addServlet(const std::string& uri, Servlet::fun cb)
    {
        addServlet(uri, Servlet::ptr(new FunServlet(cb)));
    }

    void Dispatch::delServlet(const std::string& uri)
    {
        RWMutexType::WriteLock lock(m_mutex);
        if (uri.find_first_of('*') == std::string::npos) {
            m_precise.erase(uri);
            return;
        }

        for (auto it = m_match.begin(); it != m_match.end(); ++it) {
            if (it->first == uri) {
                m_match.erase(it);
                break;
            }
        }
    }

    Servlet::ptr Dispatch::getServlet(const std::string& uri) const
    {
        RWMutexType::ReadLock lock(m_mutex);
        auto it = m_precise.find(uri);
        if (it != m_precise.end())
            return it->second;

        for (auto itor = m_match.rbegin(); itor != m_match.rend(); ++itor) {
            if (fnmatch(itor->first.data(), uri.data(), 0) == 0)
                return itor->second;
        }
        return m_def_slt;
    }

    void Dispatch::handle(Request::ptr req, Response::ptr rsp, Session::ptr session)
    {
        auto slt = getServlet(req->getPath());
        slt->handle(req, rsp, session);
    }

    NotFountServlet::NotFountServlet() : Servlet("NotFountServlet") {}

    void NotFountServlet::handle(Request::ptr req, Response::ptr rsp, Session::ptr session)
    {
        static const std::string& RSP_BODY =
            "<!DOCTYPE html>"
            "<html lang='en'>"
            "<head><meta charset='UTF-8'><title>404 not fount</title><style>h1 "
            "{margin-top:4%;text-align:center;font-size:300%;}</style></head>"
            "<body><h1>404 not found</h1><hr/></body></html>";

        rsp->setHeader("Content-Type", "text/html");
        rsp->setHeader("Server", "miruy/1.0.0");
        rsp->setStatus(Status::NOT_FOUND);
        rsp->setBody(RSP_BODY);
    }

}  // namespace http
}  // namespace miruy