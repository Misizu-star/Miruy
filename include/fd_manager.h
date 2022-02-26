#ifndef __FD_MANAGER_H__
#define __FD_MANAGER_H__

#include <memory>
#include <vector>
#include "mutex.h"
#include "singleton.h"

namespace miruy {

class Fd : public std::enable_shared_from_this<Fd>
{
public:
    using ptr = std::shared_ptr<Fd>;
    Fd(int fd);
    ~Fd() = default;

    bool close();
    bool isInit() const { return m_isInit; }
    bool isSocket() const { return m_isSocket; }
    bool isNonblock() const { return m_Nonblock; }
    bool isClosed() const { return m_isClose; }
    void setNonblock(bool flag);

    /**
     * @brief Set fd read or write Timeout
     * @param type read: SO_RCVTIMEO(20)、write: SO_SNDTIMEO(21)
     * @param timeout 超时时间, 单位 ms
     */
    void setTimeout(int type, uint64_t timeout);

    /**
     * @brief Get fd read or write Timeout
     * @param type read: SO_RCVTIMEO(20)、write: SO_SNDTIMEO(21)
     * @return uint64_t 超时时间, 单位 ms
     */
    uint64_t getTimeout(int type) const;

    static bool ISNonBlock(int fd);
    static void SetNonBlock(int fd, bool flag = true);

private:
    bool m_isInit{ false };
    bool m_isSocket{ false };
    bool m_Nonblock{ false };
    bool m_isClose{ false };
    int m_fd;
    uint64_t m_recvTimeout{ 0 };
    uint64_t m_sendTimeout{ 0 };
};

class FdManager
{
public:
    using ptr = std::shared_ptr<FdManager>;
    using RWMutexType = RWMutex;
    FdManager();

    Fd::ptr getfd(int fd, bool auto_create = false);
    void delfd(int fd);

private:
    RWMutexType m_mutex;
    std::vector<Fd::ptr> m_fds;
};

using FdMgr = SingletonPtr<FdManager>;

}  // namespace miruy

#endif
