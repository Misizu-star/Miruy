#ifndef __MIRUY_FIBER_H__
#define __MIRUY_FIBER_H__

#include <memory>
#include <functional>
#include <ucontext.h>

namespace miruy {

/**
 * @brief 协程状态定义
 * 分为初始化、就绪、运行、挂起、结束、异常六个状态
 */
enum class State : uint32_t {
    INIT,   // 初始化
    READY,  // 就绪
    EXEC,   // 运行
    HOLD,   // 挂起
    TERM,   // 结束
    EXCPT   // 异常
};

class Scheduler;

/**
 * @brief 协程类
 */
class Fiber : public std::enable_shared_from_this<Fiber>
{
    friend class Scheduler;

public:
    using ptr = std::shared_ptr<Fiber>;
    Fiber(std::function<void()> callback, size_t stacksize = 0);
    ~Fiber();

    uint64_t getId() const { return m_id; }
    State getState() const { return m_state; }

    void reset(std::function<void()> callback);
    void swapIn();

    static Fiber::ptr GetThis();
    static void YieldToRead();
    static void YieldToHold();
    static uint64_t GetId();
    static uint64_t TotalFibers();

private:
    void swapOut();
    static void MainFunc();

private:
    uint64_t m_id;
    State m_state;
    size_t m_stacksize{ 0 };
    ucontext_t m_ctx;
    void* m_stack{ nullptr };
    std::function<void()> m_cb;
};

}  // namespace miruy

#endif