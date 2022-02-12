#ifndef __MIRUY_UTIL_H__
#define __MIRUY_UTIL_H__

#include <pthread.h>
#include <assert.h>
#include <iostream>

#define ASSERT(x)                                                                                  \
    if (!(x)) {                                                                                    \
        std::cout << "ASSERTION: " << #x << std::endl;                                             \
        assert(x);                                                                                 \
    }

#define ASSERT2(x, w)                                                                              \
    if (!(x)) {                                                                                    \
        std::cout << "ASSERTION: " << std::string(w) << std::endl;                                 \
        assert(x);                                                                                 \
    }

namespace miruy {

    uint32_t GetThreadId();

    uint64_t GetFiberId();

    const char* GetThreadName();

    uint64_t GetCurrentMS();

    uint64_t GetCurrentUS();

}  // namespace miruy

#endif