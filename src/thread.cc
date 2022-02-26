#include <sys/syscall.h>
#include <unistd.h>
#include "thread.h"
#include "log.h"

namespace miruy {

static thread_local Thread* t_thread = nullptr;
static thread_local std::string t_thread_name = "";

Thread::Thread(std::function<void()> callback, const std::string& name)
    : m_cb(callback), m_name(name)
{
    int ret = pthread_create(&m_thread, nullptr, &Thread::run, this);
    if (ret) {
        LOG_ERROR(LOGGER("system")) << "pthread_create error";
        throw std::logic_error("pthread_create error");
    }
    m_sem.wait();
}

Thread::~Thread()
{
    if (m_thread) {
        pthread_detach(m_thread);
        m_thread = { 0 };
    }
}

void Thread::join()
{
    if (m_thread) {
        int ret = pthread_join(m_thread, nullptr);
        if (ret) {
            LOG_ERROR(LOGGER("system")) << "pthread_join error";
            throw std::logic_error("pthread_join error");
        }
        m_thread = { 0 };
    }
}

void Thread::detach()
{
    if (m_thread) {
        int ret = pthread_detach(m_thread);
        if (ret) {
            LOG_ERROR(LOGGER("system")) << "pthread_detach error";
            throw std::logic_error("pthread_detach error");
        }
        m_thread = { 0 };
    }
}

void* Thread::run(void* arg)
{
    Thread* thread = (Thread*)arg;
    t_thread = thread;
    t_thread_name = thread->m_name;
    thread->m_id = syscall(SYS_gettid);
    SetName(thread->m_name);
    std::function<void()> cb;
    cb.swap(thread->m_cb);

    thread->m_sem.notify();
    cb();
    return nullptr;
}

Thread* Thread::GetThis()
{
    return t_thread;
}

std::string Thread::GetName()
{
    if (t_thread_name.empty()) {
        t_thread_name.resize(32);
        pthread_getname_np(pthread_self(), &t_thread_name[0], 32);
    }
    return t_thread_name;
}

void Thread::SetName(const std::string& name)
{
    if (name.empty())
        return;
    if (t_thread) {
        t_thread->m_name = name;
    }
    pthread_setname_np(pthread_self(), name.substr(0, 15).data());
    t_thread_name = name;
}

}  // namespace miruy