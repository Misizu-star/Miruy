#ifndef __MIRUY_UTIL_H__
#define __MIRUY_UTIL_H__

#include <pthread.h>
#include <assert.h>
#include <cstdint>
#include "type.h"

#define ASSERT(x)                                                                                  \
    if (!(x)) {                                                                                    \
        printf("ASSERTION: %s\n", #x);                                                             \
        abort();                                                                                   \
    }

#define ASSERT2(x, w)                                                                              \
    if (!(x)) {                                                                                    \
        printf("ASSERTION: %s\n", (const char*)w);                                                 \
        abort();                                                                                   \
    }

namespace miruy {

// 获取当前线程id
uint32_t GetThreadId();

// 获取当前协程id
uint64_t GetFiberId();

// 获取当前毫秒数
uint64_t GetMilliSec();

// 获取当前微妙数
uint64_t GetMicroSec();

}  // namespace miruy

#endif