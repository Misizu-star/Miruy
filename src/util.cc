#include <unistd.h>
#include <sys/time.h>
#include <sys/syscall.h>
#include "util.h"
#include "fiber.h"

namespace miruy {

uint32_t GetThreadId()
{
    return (uint32_t)syscall(SYS_gettid);
}

uint64_t GetFiberId()
{
    return miruy::Fiber::GetId();
}

uint64_t GetMilliSec()
{
    struct timeval tv;
    ::gettimeofday(&tv, nullptr);
    return tv.tv_sec * 1000ul + tv.tv_usec / 1000;
}

uint64_t GetMicroSec()
{
    struct timeval tv;
    ::gettimeofday(&tv, nullptr);
    return tv.tv_sec * 1000 * 1000ul + tv.tv_usec;
}

}  // namespace miruy