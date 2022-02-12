#ifndef __MIRUY_CONFIG_H__
#define __MIRUY_CONFIG_H__

#include <string>
#include <memory>
#include <yaml-cpp/yaml.h>
#include <boost/lexical_cast.hpp>
#include <functional>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "mutex.h"

namespace miruy {

    /**
     * @brief 类型转换模板
     * @tparam F where are you from
     * @tparam T where are you going
     */
    template <class F, class T>
    class LexicalCast
    {
    public:
        T operator()(const F& v) { return boost::lexical_cast<T>(v); }
    };

    /**
     * @brief 配置项基类
     */
    class ConfigVarBase
    {
    public:
        using ptr = std::shared_ptr<ConfigVarBase>;
        ConfigVarBase(const std::string& name, const std::string& desc = "");

        std::string getName() const { return m_name; }
        std::string getDesc() const { return m_desc; }
        virtual std::string getType() const = 0;

        /* 序列化配置项 */
        virtual std::string toString() const = 0;
        /* 反序列化配置项 */
        virtual bool fromString(const std::string& from) = 0;

        virtual ~ConfigVarBase() = default;

    protected:
        std::string m_name;
        std::string m_desc;
    };

    /**
     * @brief 配置项
     * @tparam T 类型
     * @tparam FromStr 转换类：std::string --> T
     * @tparam ToStr   转换类：T --> std::string
     */
    template <class T, class FromStr = LexicalCast<std::string, T>, class ToStr = LexicalCast<T, std::string>>
    class ConfigVar : public ConfigVarBase
    {
    public:
        using ptr = std::shared_ptr<ConfigVar>;
        using RWMutexType = RWMutex;
        using on_change = std::function<void(const T& old_val, const T& new_val)>;
        ConfigVar(const std::string& name, const T& value, const std::string& desc = "")
            : ConfigVarBase(name, desc), m_val(value)
        {
        }

        const T getValue() const
        {
            RWMutexType::ReadLock lock(m_mutex);
            return m_val;
        }

        void setValue(const T& value)
        {
            {
                RWMutexType::ReadLock lock(m_mutex);
                if (m_val == value)
                    return;

                for (auto& i : m_cbs) {
                    i.second(m_val, value);
                }
            }
            RWMutexType::WriteLock lock(m_mutex);
            m_val = value;
        }

        std::string getType() const override { return typeid(m_val).name(); }

        std::string toString() const override
        {
            try {
                RWMutexType::ReadLock lock(m_mutex);
                return ToStr()(m_val);
            } catch (...) {
                return "";
            }
        }

        bool fromString(const std::string& from) override
        {
            try {
                setValue(FromStr()(from));
            } catch (...) {
                return false;
            }
            return true;
        }

        uint64_t addListener(on_change callback)
        {
            static uint64_t s_fun_id = 0;
            RWMutexType::WriteLock lock(m_mutex);
            ++s_fun_id;
            m_cbs[s_fun_id] = callback;
            return s_fun_id;
        }

        void delListener(uint64_t key)
        {
            RWMutexType::WriteLock lock(m_mutex);
            m_cbs.erase(key);
        }

        void clearListener()
        {
            RWMutexType::WriteLock lock(m_mutex);
            m_cbs.clear();
        }

        on_change getListener(uint64_t key) const
        {
            RWMutexType::ReadLock locl(m_mutex);
            auto it = m_cbs.find(key);
            return it == m_cbs.end() ? nullptr : it->second;
        }

        virtual ~ConfigVar() = default;

    private:
        mutable RWMutexType m_mutex;
        T m_val;
        /* 事件机制 ---- 变更回调函数数组 */
        std::map<uint64_t, on_change> m_cbs;
    };

    /**
     * @brief 配置（文件配置）：通常约定 先于 文件，文件 优于 约定
     */
    class Config
    {
    public:
        using ConfigVarMap = std::map<std::string, ConfigVarBase::ptr>;
        using RWMutexType = RWMutex;

        template <class T>
        static typename ConfigVar<T>::ptr Lookup(const std::string& name)
        {
            RWMutexType::ReadLock lock(GetMutex());
            auto it = Config::GetDatas().find(name);
            if (it == Config::GetDatas().end())
                return nullptr;
            return std::dynamic_pointer_cast<ConfigVar<T>>(it->second);
        }

        /**
         * @brief 查找/设置配置项
         * @tparam T 配置项类型
         * @param[in] name 配置项名称(key)
         * @param[in] value 配置项值
         * @param[in] desc 配置项描述
         * @return 查找/设置的配置项智能指针
         * @exception 当名称包含非法字符时抛出异常
         */
        template <class T>
        static typename ConfigVar<T>::ptr Lookup(const std::string& name, const T& value, const std::string& desc = "")
        {
            RWMutexType::WriteLock lock(GetMutex());
            auto it = Config::GetDatas().find(name);
            if (it != Config::GetDatas().end()) {
                auto tmp = std::dynamic_pointer_cast<ConfigVar<T>>(it->second);
                return tmp;
            }

            typename ConfigVar<T>::ptr v(new ConfigVar<T>(name, value, desc));
            Config::GetDatas()[name] = v;
            return v;
        }

        /**
         * @brief 加载 yaml 格式文件
         * @param file 文件名
         * @exception 文件出错抛出异常
         */
        static void LoadFromYaml(const char* file);

        static void Visit(std::function<void(const ConfigVarBase::ptr&)> callback);

    private:
        static ConfigVarBase::ptr Lookup(const std::string& name);

        static ConfigVarMap& GetDatas()
        {
            static ConfigVarMap s_datas;
            return s_datas;
        }

        static RWMutexType& GetMutex()
        {
            static RWMutexType s_mutex;
            return s_mutex;
        }
    };

}  // namespace miruy

/**
 * @brief std 标准容器偏特化
 * 目前支持 vector、list、set、map、unordered_set、unordered_map 的序列化和反序列化
 * 若需实现自定义 class 的序列化和反序列化，需自己实现 miruy::LexicalCase 的偏特化
 */
namespace miruy {

    /**
     * @brief 偏特化 std::vector
     * @tparam T
     */
    template <class T>
    class LexicalCast<std::string, std::vector<T>>
    {
    public:
        std::vector<T> operator()(const std::string& v)
        {
            YAML::Node node = YAML::Load(v);
            typename std::vector<T> vec;
            std::stringstream ss;
            for (size_t i = 0; i < node.size(); ++i) {
                ss.str("");
                ss << node[i];
                vec.push_back(LexicalCast<std::string, T>()(ss.str()));
            }
            return vec;
        }
    };

    template <class T>
    class LexicalCast<std::vector<T>, std::string>
    {
    public:
        std::string operator()(const std::vector<T>& vec)
        {
            YAML::Node node;
            for (auto& i : vec) {
                node.push_back(YAML::Load(LexicalCast<T, std::string>()(i)));
            }
            std::stringstream ss;
            ss << node;
            return ss.str();
        }
    };

    /**
     * @brief 偏特化 std::list
     * @tparam T
     */
    template <class T>
    class LexicalCast<std::string, std::list<T>>
    {
    public:
        std::list<T> operator()(const std::string& v)
        {
            YAML::Node node = YAML::Load(v);
            typename std::list<T> list;
            std::stringstream ss;
            for (size_t i = 0; i < node.size(); ++i) {
                ss.str("");
                ss << node[i];
                list.push_back(LexicalCast<std::string, T>()(ss.str()));
            }
            return list;
        }
    };

    template <class T>
    class LexicalCast<std::list<T>, std::string>
    {
    public:
        std::string operator()(const std::list<T>& list)
        {
            YAML::Node node;
            for (auto& i : list) {
                node.push_back(YAML::Load(LexicalCast<T, std::string>()(i)));
            }
            std::stringstream ss;
            ss << node;
            return ss.str();
        }
    };

    /**
     * @brief 偏特化 std::set
     * @tparam T
     */
    template <class T>
    class LexicalCast<std::string, std::set<T>>
    {
    public:
        std::set<T> operator()(const std::string& v)
        {
            YAML::Node node = YAML::Load(v);
            typename std::set<T> set;
            std::stringstream ss;
            for (size_t i = 0; i < node.size(); ++i) {
                ss.str("");
                ss << node[i];
                set.insert(LexicalCast<std::string, T>()(ss.str()));
            }
            return set;
        }
    };

    template <class T>
    class LexicalCast<std::set<T>, std::string>
    {
    public:
        std::string operator()(const std::set<T>& set)
        {
            YAML::Node node;
            for (auto& i : set) {
                node.push_back(YAML::Load(LexicalCast<T, std::string>()(i)));
            }
            std::stringstream ss;
            ss << node;
            return ss.str();
        }
    };

    /**
     * @brief 偏特化 std::unordered_set
     * @tparam T
     */
    template <class T>
    class LexicalCast<std::string, std::unordered_set<T>>
    {
    public:
        std::unordered_set<T> operator()(const std::string& v)
        {
            YAML::Node node = YAML::Load(v);
            typename std::unordered_set<T> uset;
            std::stringstream ss;
            for (size_t i = 0; i < node.size(); ++i) {
                ss.str("");
                ss << node[i];
                uset.insert(LexicalCast<std::string, T>()(ss.str()));
            }
            return uset;
        }
    };

    template <class T>
    class LexicalCast<std::unordered_set<T>, std::string>
    {
    public:
        std::string operator()(const std::unordered_set<T>& uset)
        {
            YAML::Node node;
            for (auto& i : uset) {
                node.push_back(YAML::Load(LexicalCast<T, std::string>()(i)));
            }
            std::stringstream ss;
            ss << node;
            return ss.str();
        }
    };

    /**
     * @brief 偏特化 std::map<std::string, T>
     * @tparam T
     */
    template <class T>
    class LexicalCast<std::string, std::map<std::string, T>>
    {
    public:
        std::map<std::string, T> operator()(const std::string& v)
        {
            YAML::Node node = YAML::Load(v);
            typename std::map<std::string, T> map;
            std::stringstream ss;
            for (auto it = node.begin(); it != node.end(); ++it) {
                ss.str("");
                ss << it->second;
                map.insert(std::make_pair(it->first.Scalar(), LexicalCast<std::string, T>()(ss.str())));
            }
            return map;
        }
    };

    template <class T>
    class LexicalCast<std::map<std::string, T>, std::string>
    {
    public:
        std::string operator()(const std::map<std::string, T>& map)
        {
            YAML::Node node;
            for (auto& i : map) {
                node[i.first] = YAML::Load(LexicalCast<T, std::string>()(i.second));
            }
            std::stringstream ss;
            ss << node;
            return ss.str();
        }
    };

    /**
     * @brief 偏特化 std::unordered_map<std::string, T>
     * @tparam T
     */
    template <class T>
    class LexicalCast<std::string, std::unordered_map<std::string, T>>
    {
    public:
        std::unordered_map<std::string, T> operator()(const std::string& v)
        {
            YAML::Node node = YAML::Load(v);
            typename std::unordered_map<std::string, T> umap;
            std::stringstream ss;
            for (auto it = node.begin(); it != node.end(); ++it) {
                ss.str("");
                ss << it->second;
                umap.insert(std::make_pair(it->first.Scalar(), LexicalCast<std::string, T>()(ss.str())));
            }
            return umap;
        }
    };

    template <class T>
    class LexicalCast<std::unordered_map<std::string, T>, std::string>
    {
    public:
        std::string operator()(const std::unordered_map<std::string, T>& umap)
        {
            YAML::Node node;
            for (auto& i : umap) {
                node[i.first] = YAML::Load(LexicalCast<T, std::string>()(i.second));
            }
            std::stringstream ss;
            ss << node;
            return ss.str();
        }
    };

}  // namespace miruy

#endif