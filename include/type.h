#ifndef __MIRUY_TYPE_H__
#define __MIRUY_TYPE_H__

#include <type_traits>
#include <string>

namespace miruy {

/// 通用字符串: 支持 std::string类型、const char* 类型、char[] 类型、字符串字面常量
template <typename T>
struct is_string : std::false_type {};

template <>
struct is_string<std::string> : std::true_type {};

template <>
struct is_string<const char*> : std::true_type {};

template <>
struct is_string<char*> : std::true_type {};

template <size_t s>
struct is_string<char[s]> : std::true_type {};

template <>
struct is_string<char[]> : std::true_type {};

/// 简单类型: 包含通用字符串、整型(bool、short、int、long、long long及无符号形式)、浮点型(float、double)
template <typename T>
struct is_simple_type
    : std::integral_constant<bool, std::is_arithmetic<T>::value || is_string<T>::value> {};


template <typename T>
using is_string_t = typename std::enable_if<is_string<T>::value, T>::type;

template <typename T>
using is_simple_type_t = typename std::enable_if<is_simple_type<T>::value, T>::type;

}  // namespace miruy

#endif