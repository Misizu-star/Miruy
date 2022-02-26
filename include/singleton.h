#ifndef __MIRUY_SINGLETON_H__
#define __MIRUY_SINGLETON_H__

#include <memory>

namespace miruy {

template <class T, class X = void, int N = 0>
class Singleton
{
public:
    static T* getInstance()
    {
        static T o;
        return &o;
    }
};

template <class T, class X = void, int N = 0>
class SingletonPtr
{
public:
    static std::shared_ptr<T> getInstance()
    {
        static std::shared_ptr<T> o{ new T };
        return o;
    }
};

}  // namespace miruy

#endif