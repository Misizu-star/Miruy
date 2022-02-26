#include <sys/epoll.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include "iomanager.h"
#include "log.h"
#include "util.h"

namespace miruy {

IOManager::FdContext::EventContext& IOManager::FdContext::getContext(IOEvent event)
{
    switch (event) {
        case IOEvent::READ: return read;
        case IOEvent::WRITE: return write;
        default: ASSERT2(false, "FdContext::getContext(): invalid IOEvent");
    }
    throw std::invalid_argument("getContext invalid IOEvent");
}

void IOManager::FdContext::ResetContext(EventContext& event_ctx)
{
    event_ctx.scheduler = nullptr;
    event_ctx.cb = nullptr;
    event_ctx.fiber.reset();
}

void IOManager::FdContext::triggerEvent(IOEvent event)
{
    events &= ~(uint32_t)event;
    EventContext& ctx = getContext(event);
    if (ctx.cb)
        ctx.scheduler->schedule(&ctx.cb);
    else if (ctx.fiber)
        ctx.scheduler->schedule(&ctx.fiber);
    ctx.scheduler = nullptr;
}

IOManager::IOManager(uint32_t ths_count, const std::string& name) : Scheduler(ths_count, name)
{
    m_epfd = ::epoll_create(5250);
    if (m_epfd <= 0) {
        LOG_ERROR(LOGGER("system")) << "create epoll fd failed";
        throw std::logic_error("epoll_create() error");
    }

    if (::pipe(m_pipe)) {
        LOG_ERROR(LOGGER("system")) << "create pipe failed";
        throw std::logic_error("pipe() error");
    }

    epoll_event event;
    memset(&event, 0, sizeof(event));
    event.events = EPOLLIN | EPOLLET;
    event.data.fd = m_pipe[0];

    if (::fcntl(m_pipe[0], F_SETFL, O_NONBLOCK)) {
        LOG_ERROR(LOGGER("system")) << "set pipe " << m_pipe[0] << " nonblock failed";
        throw std::logic_error("fcntl() error");
    }

    if (::epoll_ctl(m_epfd, EPOLL_CTL_ADD, m_pipe[0], &event)) {
        LOG_ERROR(LOGGER("system"))
            << "epoll_ctl(" << m_epfd << ", EPOLL_CTL_ADD, " << m_pipe[0] << ", &event) failed";
        throw std::logic_error("epoll_ctl() error");
    }

    m_fdContexts.resize(64);
    Scheduler::start();
}

IOManager ::~IOManager()
{
    Scheduler::stop();
    ::close(m_epfd);
    ::close(m_pipe[0]);
    ::close(m_pipe[1]);

    for (size_t i = 0; i < m_fdContexts.size(); ++i) {
        if (m_fdContexts[i]) {
            delete m_fdContexts[i];
        }
    }
}

IOManager* IOManager::GetThis()
{
    return dynamic_cast<IOManager*>(Scheduler::GetThis());
}

bool IOManager::addEvent(int fd, IOEvent event, std::function<void()> cb)
{
    FdContext* fd_ctx;
    RWMutexType::ReadLock lock(m_mutex);
    uint8_t bit = fd >= (int)m_fdContexts.size() ? 0x11 : (!m_fdContexts[fd] ? 0x01 : 0);
    if (!bit) {
        fd_ctx = m_fdContexts[fd];
        lock.unlock();
    } else {
        lock.unlock();
        RWMutexType::WriteLock wlock(m_mutex);
        if (bit == 0x11)
            m_fdContexts.resize(fd + fd >> 1);
        m_fdContexts[fd] = new FdContext;
        m_fdContexts[fd]->fd = fd;
        fd_ctx = m_fdContexts[fd];
    }

    FdContext::MutexType::Lock lock2(fd_ctx->mutex);
    FdContext::EventContext& event_ctx = fd_ctx->getContext(event);

    if (fd_ctx->events & (uint32_t)event) {
        if (!cb && event_ctx.fiber || cb && !event_ctx.fiber) {
            event_ctx.scheduler = Scheduler::GetThis();
            if (cb)
                event_ctx.cb = std::move(cb);
            else
                event_ctx.fiber = Fiber::GetThis();
            return true;
        }
        LOG_ERROR(LOGGER("system")) << "addEvent(): event has existed";
        return false;
    }

    int op = fd_ctx->events ? EPOLL_CTL_MOD : EPOLL_CTL_ADD;
    epoll_event epevent;
    memset(&epevent, 0, sizeof(epevent));
    epevent.events = EPOLLET | fd_ctx->events | (uint32_t)event;
    epevent.data.ptr = fd_ctx;
    if (::epoll_ctl(m_epfd, op, fd, &epevent)) {
        LOG_ERROR(LOGGER("system")) << "epoll_ctl(" << m_epfd << ", " << op << ", " << fd << ", "
                                    << epevent.events << "): " << strerror(errno);
        return false;
    }

    ++m_eventCount;
    fd_ctx->events |= (uint32_t)event;

    event_ctx.scheduler = Scheduler::GetThis();
    if (cb)
        event_ctx.cb = std::move(cb);
    else
        event_ctx.fiber = Fiber::GetThis();
    return true;
}

bool IOManager::delEvent(int fd, IOEvent event)
{
    RWMutexType::ReadLock lock(m_mutex);
    if (fd >= (int)m_fdContexts.size() || !m_fdContexts[fd])
        return false;
    FdContext* fd_ctx = m_fdContexts[fd];
    lock.unlock();

    FdContext::MutexType::Lock lock2(fd_ctx->mutex);
    if (!(fd_ctx->events & (uint32_t)event))
        return false;

    uint32_t new_events = fd_ctx->events & ~(uint32_t)event;
    int op = new_events ? EPOLL_CTL_MOD : EPOLL_CTL_DEL;
    epoll_event epevent;
    memset(&epevent, 0, sizeof(epevent));
    epevent.events = EPOLLET | new_events;
    epevent.data.ptr = fd_ctx;
    if (::epoll_ctl(m_epfd, op, fd, &epevent)) {
        LOG_ERROR(LOGGER("system")) << "epoll_ctl(" << m_epfd << ", " << op << ", " << fd << ", "
                                    << new_events << "): " << strerror(errno);
        return false;
    }

    --m_eventCount;
    fd_ctx->events = new_events;
    FdContext::ResetContext(fd_ctx->getContext(event));
    return true;
}

bool IOManager::cancelEvent(int fd, IOEvent event)
{
    RWMutexType::ReadLock lock(m_mutex);
    if (fd >= (int)m_fdContexts.size() || !m_fdContexts[fd])
        return false;

    FdContext* fd_ctx = m_fdContexts[fd];
    lock.unlock();

    FdContext::MutexType::Lock lock2(fd_ctx->mutex);
    if (!(fd_ctx->events & (uint32_t)event))
        return false;

    uint32_t new_events = fd_ctx->events & ~(uint32_t)event;
    int op = new_events ? EPOLL_CTL_MOD : EPOLL_CTL_DEL;
    epoll_event epevent;
    memset(&epevent, 0, sizeof(epevent));
    epevent.events = EPOLLET | new_events;
    epevent.data.ptr = fd_ctx;

    if (::epoll_ctl(m_epfd, op, fd, &epevent)) {
        LOG_ERROR(LOGGER("system")) << "epoll_ctl(" << m_epfd << ", " << op << ", " << fd << ", "
                                    << new_events << "): " << strerror(errno);
        return false;
    }

    --m_eventCount;
    fd_ctx->triggerEvent(event);
    return true;
}

bool IOManager::cancelAll(int fd)
{
    RWMutexType::ReadLock lock(m_mutex);
    if (fd >= (int)m_fdContexts.size() || !m_fdContexts[fd])
        return false;

    FdContext* fd_ctx = m_fdContexts[fd];
    lock.unlock();

    FdContext::MutexType::Lock lock2(fd_ctx->mutex);
    if (!fd_ctx->events)
        return true;

    epoll_event epevent;
    memset(&epevent, 0, sizeof(epevent));
    epevent.data.ptr = fd_ctx;
    if (::epoll_ctl(m_epfd, EPOLL_CTL_DEL, fd, &epevent)) {
        LOG_ERROR(LOGGER("system"))
            << "epoll_ctl(" << m_epfd << ", " << EPOLL_CTL_DEL << ", " << fd << ", "
            << epevent.events << "): " << m_eventCount << " " << strerror(errno);
        return false;
    }

    if (fd_ctx->events & (uint32_t)IOEvent::READ) {
        fd_ctx->triggerEvent(IOEvent::READ);
        --m_eventCount;
    }

    if (fd_ctx->events & (uint32_t)IOEvent::WRITE) {
        fd_ctx->triggerEvent(IOEvent::WRITE);
        --m_eventCount;
    }

    ASSERT(fd_ctx->events == 0);
    return true;
}

void IOManager::tickle()
{
    if (!hasIdelThread())
        return;
    int ret = ::write(m_pipe[1], "1", 1);
    ASSERT(ret == 1);
}

bool IOManager::stopping(uint64_t& timeout)
{
    timeout = getNextTimeout();
    return timeout == ~0ull && m_eventCount == 0 && Scheduler::stopped();
}

bool IOManager::stopped()
{
    uint64_t timeout = 0;
    return stopping(timeout);
}

void IOManager::idle()
{
    const uint32_t MAX_EVENTS = 128;
    epoll_event* events = new epoll_event[MAX_EVENTS];
    std::shared_ptr<epoll_event> share_events(events, [](epoll_event* ptr) { delete[] ptr; });
    while (true) {
        uint64_t timeout = 0;
        if (stopping(timeout)) {
            LOG_INFO(LOGGER("system"))
                << "idle fiber " << Fiber::GetId() << " exit, " << Thread::GetName() << " stopping";
            break;
        }

        int ret;
        do {
            static const int MAX_TIMEOUT = 3000;
            timeout = timeout > MAX_TIMEOUT ? MAX_TIMEOUT : timeout;
            ret = ::epoll_wait(m_epfd, events, MAX_EVENTS, (int)timeout);
        } while (ret < 0 && errno == EINTR);

        if (ret == 0) {
            std::vector<std::function<void()>> cbs;
            listTimeoutCb(cbs);
            if (!cbs.empty()) {
                schedule(cbs.begin(), cbs.end());
                cbs.clear();
            }
        }

        for (int i = 0; i < ret; ++i) {
            epoll_event& event = events[i];
            if (event.data.fd == m_pipe[0]) {
                uint8_t dummpy;
                while (read(m_pipe[0], &dummpy, 1) == 1) {}
                continue;
            }
            FdContext* fd_ctx = (FdContext*)event.data.ptr;

            FdContext::MutexType::Lock lock(fd_ctx->mutex);
            if (event.events & (EPOLLERR | EPOLLHUP)) {
                event.events |= EPOLLIN | EPOLLOUT;
            }

            int real_events = event.events & 0x5;

            if (!(fd_ctx->events & real_events))
                continue;

            int left_events = fd_ctx->events & ~real_events;
            int op = left_events ? EPOLL_CTL_MOD : EPOLL_CTL_DEL;
            events->events = EPOLLET | left_events;

            if (::epoll_ctl(m_epfd, op, fd_ctx->fd, &event)) {
                LOG_ERROR(LOGGER("system"))
                    << "epoll_ctl(" << m_epfd << ", " << op << ", " << fd_ctx->fd << ", "
                    << event.events << "): " << strerror(errno);
                continue;
            }

            if (real_events & EPOLLIN) {
                fd_ctx->triggerEvent(IOEvent::READ);
                --m_eventCount;
            }

            if (real_events & EPOLLOUT) {
                fd_ctx->triggerEvent(IOEvent::WRITE);
                --m_eventCount;
            }
        }
        Fiber::YieldToHold();
    }
}

void IOManager::onTimerInsertAtFront()
{
    tickle();
}

}  // namespace miruy