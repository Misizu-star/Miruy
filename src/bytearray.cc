#include <fstream>
#include "bytearray.h"

namespace miruy {

    ByteArray::ByteArray(size_t bace_size)
        : m_baseSize(bace_size), m_position(0), m_capacity(bace_size), m_size(0),
          m_read(new Node(bace_size)), m_write(m_read), m_endian(BIG_ENDIAN)
    {
    }

    ByteArray::~ByteArray()
    {
        while (m_read) {
            m_write = m_read;
            m_read = m_read->next;
            delete m_write;
        }
    }

    void ByteArray::clear()
    {
        m_position = m_size = 0;
        m_capacity = m_baseSize;
        Node* tmp = m_read->next;
        while (tmp) {
            m_write = tmp;
            tmp = tmp->next;
            delete m_write;
        }
        m_write = m_read;
        m_read->next = nullptr;
    }

    size_t ByteArray::writeString(const std::string& str, size_t len)
    {
        len = len ? len : str.size();
        len = len < str.size() ? len : str.size();
        write(str.data(), len);
        return len;
    }

    std::string ByteArray::readString(size_t len)
    {
        std::string str;
        if (m_size == 0)
            return str;
        len = len ? len : m_size;
        len = m_size < len ? m_size : len;
        str.resize(len);
        read(&str[0], len);
        return str;
    }

    bool ByteArray::copyToFile(const std::string& file) const
    {
        std::ofstream ofs;
        ofs.open(file, std::ios::trunc | std::ios::binary);
        if (!ofs.is_open())
            return false;

        size_t len = m_size, pos = m_position;
        Node* cur = m_read;
        while (len > 0) {
            pos %= m_baseSize;
            size_t left = (len > m_baseSize ? m_baseSize : len) - pos;
            ofs.write(cur->ptr + pos, left);
            cur = cur->next;
            len -= left;
            pos += left;
        }
        return true;
    }

    bool ByteArray::writeToFile(const std::string& file)
    {
        bool flag = copyToFile(file);
        clear();
        return flag;
    }

    bool ByteArray::readFromFile(const std::string& file)
    {
        std::ifstream ifs;
        ifs.open(file, std::ios::binary);
        if (!ifs.is_open())
            return false;

        std::shared_ptr<char> buf(new char[m_baseSize], [](char* ptr) { delete[] ptr; });
        while (!ifs.eof()) {
            ifs.read(buf.get(), m_baseSize);
            write(buf.get(), ifs.gcount());
        }
        return true;
    }

    void ByteArray::write(const void* buf, size_t size) noexcept
    {
        if (!size)
            return;
        expanse(size);

        size_t pos = m_position + m_size, left;
        m_size += size;

        while ((int64_t)size > 0ll) {
            pos %= m_baseSize;
            left = m_baseSize - pos;
            if (left > size) {
                memcpy(m_write->ptr + pos, buf, size);
            } else {
                memcpy(m_write->ptr + pos, buf, left);
                pos += left;
                buf = (char*)buf + left;
                m_write = m_write->next;
            }
            size -= left;
        }
    }

    bool ByteArray::read(void* buf, size_t size) noexcept
    {
        if (!size || size > m_size)
            return false;

        size_t pos = m_position, left;
        m_size -= size;
        m_position += size;
        Node* cur = m_read;

        while ((int64_t)size > 0ll) {
            pos %= m_baseSize;
            left = m_baseSize - pos;
            if (left >= size) {
                memcpy(buf, cur->ptr + pos, size);
            } else {
                memcpy(buf, cur->ptr + pos, left);
                pos += left;
                buf = (char*)buf + left;
                cur = cur->next;
            }
            size -= left;
        }
        shrink();
        return true;
    }

    void ByteArray::copy(void* buf, int64_t size, size_t pos) const
    {
        if (!size)
            return;

        pos = m_position + (size < 0 ? ((int64_t)pos + size) : pos);
        size = size < 0 ? -size : size;
        if (pos < m_position || (pos + size > m_position + m_size))
            throw std::logic_error("position out of range");

        Node* cur = m_read;
        size_t offset = pos / m_baseSize - m_position / m_baseSize, left;
        while (offset--)
            cur = cur->next;

        while ((int64_t)size > 0ll) {
            offset = pos % m_baseSize;
            left = m_baseSize - offset;
            if (left >= size) {
                memcpy(buf, cur->ptr + offset, size);
            } else {
                memcpy(buf, cur->ptr + offset, left);
                offset += left;
                buf = (char*)buf + left;
                cur = cur->next;
            }
            size -= left;
        }
    }

    void ByteArray::expanse(size_t size)
    {
        int64_t add = m_position + m_size + size - m_capacity;
        if (add <= 0)
            return;
        size = add / m_baseSize + (add % m_baseSize ? 1 : 0);
        Node* cur = m_read;
        while (cur->next)
            cur = cur->next;

        for (size_t i = 0; i < size; ++i) {
            cur->next = new Node(m_baseSize);
            cur = cur->next;
            m_capacity += m_baseSize;
            if (!m_write && i == 0)
                m_write = cur;
        }
    }

    void ByteArray::shrink()
    {
        // 无数据
        if (m_position == m_capacity) {
            m_position = 0;
            m_write = m_read;
            return;
        }

        size_t i = m_position / m_baseSize;
        Node* tmp;
        while (i--) {
            tmp = m_read;
            m_read = m_read->next;
            delete tmp;
            m_position -= m_baseSize;
            m_capacity -= m_baseSize;
        }
    }

}  // namespace miruy