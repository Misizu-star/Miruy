#ifndef __MIRUY_THREAD_H__
#define __MIRUY_THREAD_H__

#include <memory>
#include <functional>
#include <pthread.h>
#include <string>
#include "mutex.h"

namespace miruy {

class Thread : public NonCopy
{
public:
    using ptr = std::shared_ptr<Thread>;
    Thread(std::function<void()> callback, const std::string& name = "");
    ~Thread();

    pid_t getId() { return m_id; }

    void join();
    void detach();

    static Thread* GetThis();
    static std::string GetName();
    static void SetName(const std::string& name);

private:
    static void* run(void* arg);

private:
    pid_t m_id{ -1 };
    std::string m_name;
    pthread_t m_thread{ 0 };
    std::function<void()> m_cb;
    Semaphore m_sem;
};

}  // namespace miruy

#endif