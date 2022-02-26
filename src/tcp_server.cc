#include "tcp_server.h"
#include "config.h"
#include "log.h"
#include "util.h"

namespace miruy {

static ConfigVar<uint64_t>::ptr g_tcp_server_read_timeout =
    Config::Lookup<uint64_t>("timeout.tcp_server.read", 60 * 1000, "tcp_server read timeout");

TcpServer::TcpServer(uint32_t work_ths, IOManager* iom, const std::string& work_name)
    : m_accept(iom), m_name("miruy/1.0.0"), m_readTimeout(g_tcp_server_read_timeout->getValue())
{
    ASSERT(iom != nullptr);
    if (work_ths != 0)
        m_work = new IOManager(work_ths, work_name);
    else
        m_work = m_accept;
}

TcpServer::~TcpServer()
{
    for (auto& i : m_socks)
        i->close();
    if (m_accept != m_work)
        delete m_work;
    m_socks.clear();
    LOG_INFO(LOGGER("system")) << "TcpServer closed";
}

bool TcpServer::bind(Address::ptr addr)
{
    Socket::ptr sock = Socket::CreateTCP(addr);
    if (!sock->bind(addr)) {
        LOG_ERROR(LOGGER("system")) << "bind fail, sock: " << sock->toString();
        return false;
    }
    if (!sock->listen()) {
        LOG_ERROR(LOGGER("system")) << "listen fail, sock: " << sock->toString();
        return false;
    }
    m_socks.push_back(std::move(sock));
    return true;
}

bool TcpServer::bind(const std::vector<Address::ptr>& addrs, std::vector<Address::ptr>& fail_addrs)
{
    size_t count = m_socks.size();
    for (auto& addr : addrs) {
        Socket::ptr sock = Socket::CreateTCP(addr);
        if (!sock->bind(addr)) {
            fail_addrs.push_back(addr);
            LOG_ERROR(LOGGER("system")) << "bind fail, sock: " << sock->toString();
            continue;
        }
        if (!sock->listen()) {
            fail_addrs.push_back(addr);
            LOG_ERROR(LOGGER("system")) << "listen fail, sock: " << sock->toString();
            continue;
        }
        m_socks.push_back(std::move(sock));
    }
    return m_socks.size() != count;
}

void TcpServer::start()
{
    if (m_accept->stopped()) {
        LOG_ERROR(LOGGER("system")) << "Server start fail: the iomanager has stopped";
        return;
    }
    if (m_running)
        return;
    m_running = true;
    for (auto& sock : m_socks) {
        sock->setRecvTimeout(m_readTimeout);
        m_accept->schedule(std::bind(&TcpServer::startAccept, shared_from_this(), sock));
    }
}

void TcpServer::startAccept(Socket::ptr sock)
{
    while (m_running) {
        Socket::ptr client = sock->accept();
        if (client) {
            client->setRecvTimeout(m_readTimeout);
            client->getRemoteAddress();
            m_work->schedule(std::bind(&TcpServer::handleClient, shared_from_this(), client));
        }
    }
}

void TcpServer::stop()
{
    m_running = false;
    auto self = shared_from_this();
    m_accept->schedule([self]() {
        for (auto& sock : self->m_socks) {
            self->m_accept->cancelAll(sock->getFd());
            sock->close();
        }
        self->m_socks.clear();
    });
}

void TcpServer::handleClient(Socket::ptr client)
{
    // LOG_INFO(LOGGER("system")) << client->toString();
}

}  // namespace miruy