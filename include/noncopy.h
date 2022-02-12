#ifndef __MIRUY_NONCOPY_H__
#define __MIRUY_NONCOPY_H__

namespace miruy {

    class NonCopy
    {
    public:
        NonCopy() = default;
        ~NonCopy() = default;
        NonCopy(const NonCopy&) = delete;
        NonCopy& operator=(const NonCopy&) = delete;
    };

}  // namespace miruy
#endif