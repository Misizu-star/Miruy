#ifndef __MIRUY_MUTEX_H__
#define __MIRUY_MUTEX_H__

#include <pthread.h>
#include <semaphore.h>
#include <atomic>
#include "noncopy.h"

namespace miruy {

    /**
     * @brief 信号量
     */
    class Semaphore : NonCopy
    {
    public:
        Semaphore(uint32_t count = 0);
        void wait();
        void notify();
        ~Semaphore();

    private:
        sem_t m_sem;
    };

    /**
     * @brief 局部锁的模板实现
     * @tparam T Mutex类型
     */
    template <class T> class _ScopedLockImpl
    {
    public:
        _ScopedLockImpl(T& mutex) : m_mutex(mutex)
        {
            m_mutex.lock();
            m_locked = true;
        }

        ~_ScopedLockImpl() { unlock(); }

        void lock()
        {
            if (!m_locked) {
                m_mutex.lock();
                m_locked = true;
            }
        }

        void unlock()
        {
            if (m_locked) {
                m_mutex.unlock();
                m_locked = false;
            }
        }

    private:
        T& m_mutex;
        bool m_locked;
    };

    /**
     * @brief 互斥量
     */
    class Mutex : NonCopy
    {
    public:
        using Lock = _ScopedLockImpl<Mutex>;
        Mutex();
        ~Mutex();

        void lock();
        void unlock();

    private:
        pthread_mutex_t m_lock;
    };

    /**
     * @brief 空锁
     */
    class NullMutex : NonCopy
    {
    public:
        using Lock = _ScopedLockImpl<NullMutex>;
        NullMutex() {}
        ~NullMutex() {}

        void lock() {}
        void unlock() {}
    };

    /**
     * @brief 局部读锁的模板实现
     * @tparam T RWMutex 类型
     */
    template <class T> class _ReadScopedLockImpl
    {
    public:
        _ReadScopedLockImpl(T& mutex) : m_mutex(mutex)
        {
            m_mutex.rdlock();
            m_locked = true;
        }

        ~_ReadScopedLockImpl() { unlock(); }

        void lock()
        {
            if (!m_locked) {
                m_mutex.rdlock();
                m_locked = true;
            }
        }

        void unlock()
        {
            if (m_locked) {
                m_mutex.unlock();
                m_locked = false;
            }
        }

    private:
        T& m_mutex;
        bool m_locked;
    };

    /**
     * @brief 局部写锁的模板实现
     * @tparam T RWMutex 类型
     */
    template <class T> class _WriteScopedLockImpl
    {
    public:
        _WriteScopedLockImpl(T& mutex) : m_mutex(mutex)
        {
            m_mutex.wrlock();
            m_locked = true;
        }

        ~_WriteScopedLockImpl() { unlock(); }

        void lock()
        {
            if (!m_locked) {
                m_mutex.wrlock();
                m_locked = true;
            }
        }

        void unlock()
        {
            if (m_locked) {
                m_mutex.unlock();
                m_locked = false;
            }
        }

    private:
        T& m_mutex;
        bool m_locked;
    };

    /**
     * @brief 读写互斥量
     */
    class RWMutex : NonCopy
    {
    public:
        using ReadLock = _ReadScopedLockImpl<RWMutex>;
        using WriteLock = _WriteScopedLockImpl<RWMutex>;
        RWMutex();
        ~RWMutex();

        void rdlock();
        void wrlock();
        void unlock();

    private:
        pthread_rwlock_t m_lock;
    };

    /**
     * @brief 空读写锁
     */
    class NullRWMutex : NonCopy
    {
    public:
        using ReadLock = _ReadScopedLockImpl<NullRWMutex>;
        using WriteLock = _WriteScopedLockImpl<NullRWMutex>;
        NullRWMutex() {}
        ~NullRWMutex() {}

        void rdlock() {}
        void wrlock() {}
        void unlock() {}
    };

    /**
     * @brief 自旋锁
     */
    class SpinLock : NonCopy
    {
    public:
        using Lock = _ScopedLockImpl<SpinLock>;
        SpinLock();
        ~SpinLock();

        void lock();
        void unlock();

    private:
        pthread_spinlock_t m_mutex;
    };

    class CASLock : NonCopy
    {
    public:
        using Lock = _ScopedLockImpl<CASLock>;
        CASLock();
        ~CASLock() = default;

        void lock();
        void unlock();

    private:
        volatile std::atomic_flag m_mutex;
    };
}  // namespace miruy

#endif