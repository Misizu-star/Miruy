#ifndef __MIRUY_BYTEARRAY_H__
#define __MIRUY_BYTEARRAY_H__

#include <memory>
#include <string>
#include <cstring>
#include <stdint.h>
#include <endian.h>

namespace miruy {

    struct Node
    {
        Node() : size(0), ptr(nullptr), next(nullptr) {}
        Node(size_t s) : size(s), ptr(new char[s]), next(nullptr) {}
        ~Node() { delete[] ptr; }

        char* const ptr;
        Node* next;
        size_t size;
    };

    class ByteArray
    {
    public:
        using ptr = std::shared_ptr<ByteArray>;
        ByteArray(size_t bace_size = 4096);
        ~ByteArray();

        size_t getCapacity() const { return m_capacity; }
        size_t getBaseSize() const { return m_baseSize; }
        size_t getSize() const { return m_size; }
        bool empty() const { return m_size == 0; }
        bool isBigEndian() const { return m_endian == BIG_ENDIAN; }
        void setLittleEndian() { m_endian = LITTLE_ENDIAN; }
        void setBigEndian() { m_endian = BIG_ENDIAN; }
        void clear();

        template <class T, class = std::enable_if_t<std::is_integral<T>::value>>
        void writeInteger(T val) noexcept
        {
            if (BYTE_ORDER != m_endian) {
                switch (sizeof(T)) {
                    case 2: val = (T)__bswap_16((uint16_t)val); break;
                    case 4: val = (T)__bswap_32((uint32_t)val); break;
                    case 8: val = (T)__bswap_64((uint64_t)val); break;
                }
            }
            write(&val, sizeof(T));
        }

        template <class T, class = std::enable_if_t<std::is_floating_point<T>::value>>
        void writeDecimal(T val) noexcept
        {
            switch (sizeof(val)) {
                case 4: {
                    uint32_t v;
                    memcpy(&v, &val, 4);
                    writeInteger(v);
                    return;
                }
                case 8: {
                    uint64_t v;
                    memcpy(&v, &val, 8);
                    writeInteger(v);
                    return;
                }
            }
        }

        template <class T>
        std::enable_if_t<std::is_integral<T>::value, T> readInteger()
        {
            T val;
            if (!read(&val, sizeof(T)))
                throw std::logic_error("not enough space to read");
            if (BYTE_ORDER != m_endian) {
                switch (sizeof(T)) {
                    case 2: val = (T)__bswap_16((uint16_t)val); break;
                    case 4: val = (T)__bswap_32((uint32_t)val); break;
                    case 8: val = (T)__bswap_64((uint64_t)val); break;
                }
            }
            return val;
        }

        template <class T>
        std::enable_if_t<std::is_floating_point<T>::value, T> readDecimal()
        {
            T val;
            switch (sizeof(T)) {
                case 4: {
                    uint32_t f = readInteger<uint32_t>();
                    memcpy(&val, &f, 4);
                    return val;
                }
                case 8: {
                    uint64_t d = readInteger<uint64_t>();
                    memcpy(&val, &d, 8);
                    return val;
                }
            }
            return val;
        }

        /**
         * @brief 写入指定字节数的字符串, len 默认为 0, 当 len 为 0 时写入整个字符串
         * @param str 待写入字符串
         * @param len 写入字符串的字节数
         * @return size_t 返回实际写入的字节数
         */
        size_t writeString(const std::string& str, size_t len = 0);

        std::string readString(size_t len);

        bool copyToFile(const std::string& file) const;
        bool writeToFile(const std::string& file);
        bool readFromFile(const std::string& file);

        void write(const void* buf, size_t size) noexcept;
        bool read(void* buf, size_t size) noexcept;

        /**
         * @brief 从指定位置拷贝指定字节的数据, 此方法不会删除原本存储的数据
         * @param buf 代拷贝位置
         * @param size 拷贝指定的字节数, 若 size > 0, 则拷贝后 |size| 个数据, 若 size < 0, 则拷贝前
         * |size| 个数据
         * @param pos 拷贝起始位置, 默认为 0
         */
        void copy(void* buf, int64_t size, size_t pos = 0) const;

    private:
        void expanse(size_t size); /* 动态扩容 */
        void shrink();             /* 动态缩容 */

    private:
        size_t m_baseSize; /* 结点数据大小 */
        size_t m_capacity; /* 总容量 */
        size_t m_position; /* 读操作位置 */
        size_t m_size;     /* 存储数据字节数 */
        int32_t m_endian;  /* 数据字节序(默认为大端) */

        Node* m_read;  /* 读操作节点指针 */
        Node* m_write; /* 写操作节点指针 */
    };

}  // namespace miruy

#endif