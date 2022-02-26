#include <stdexcept>
#include "mutex.h"
#include "log.h"

namespace miruy {

Semaphore::Semaphore(uint32_t count)
{
    if (sem_init(&m_sem, 0, count)) {
        LOG_ERROR(LOGGER("system")) << "sem_init error";
        throw std::logic_error("sem_init error");
    }
}

void Semaphore::wait()
{
    if (sem_wait(&m_sem)) {
        LOG_ERROR(LOGGER("system")) << "sem_wait error";
        throw std::logic_error("sem_wait error");
    }
}

void Semaphore::notify()
{
    if (sem_post(&m_sem)) {
        LOG_ERROR(LOGGER("system")) << "sem_post error";
        throw std::logic_error("sem_post error");
    }
}

Semaphore::~Semaphore()
{
    sem_destroy(&m_sem);
}

Mutex::Mutex()
{
    pthread_mutex_init(&m_lock, nullptr);
}
Mutex::~Mutex()
{
    pthread_mutex_destroy(&m_lock);
}
void Mutex::lock()
{
    pthread_mutex_lock(&m_lock);
}
void Mutex::unlock()
{
    pthread_mutex_unlock(&m_lock);
}

RWMutex::RWMutex()
{
    pthread_rwlock_init(&m_lock, nullptr);
}
RWMutex::~RWMutex()
{
    pthread_rwlock_destroy(&m_lock);
}
void RWMutex::rdlock()
{
    pthread_rwlock_rdlock(&m_lock);
}
void RWMutex::wrlock()
{
    pthread_rwlock_wrlock(&m_lock);
}
void RWMutex::unlock()
{
    pthread_rwlock_unlock(&m_lock);
}

SpinLock::SpinLock()
{
    pthread_spin_init(&m_mutex, 0);
}
SpinLock::~SpinLock()
{
    pthread_spin_destroy(&m_mutex);
}
void SpinLock::lock()
{
    pthread_spin_lock(&m_mutex);
}
void SpinLock::unlock()
{
    pthread_spin_unlock(&m_mutex);
}

CASLock::CASLock()
{
    m_mutex.clear();
}

void CASLock::lock()
{
    while (std::atomic_flag_test_and_set_explicit(&m_mutex, std::memory_order_acquire)) {}
}

void CASLock::unlock()
{
    std::atomic_flag_clear_explicit(&m_mutex, std::memory_order_release);
}

}  // namespace miruy