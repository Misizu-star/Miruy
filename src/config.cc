#include "config.h"
#include "log.h"

namespace miruy {
    ConfigVarBase::ConfigVarBase(const std::string& name, const std::string& desc) : m_name(name), m_desc(desc)
    {
        std::transform(m_name.begin(), m_name.end(), m_name.begin(), ::tolower);
        if (m_name.find_first_not_of("qwertyuiopasdfghjklzxcvbnm._0123456789") != std::string::npos) {
            LOG_ERROR(LOGGER("system"), "ConfigVarBase::ConfigVarBase() invalid key_name");
            throw std::invalid_argument(name);
        }
    }

    ConfigVarBase::ptr Config::Lookup(const std::string& name)
    {
        RWMutexType::ReadLock lock(GetMutex());
        auto it = Config::GetDatas().find(name);
        return it == Config::GetDatas().end() ? nullptr : it->second;
    }

    static void ListAllMenber(const std::string& prefix,
                              const YAML::Node& node,
                              std::list<std::pair<std::string, YAML::Node>>& output)
    {
        const char* safeStr = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM._0123456789";
        if (prefix.find_first_not_of(safeStr) != std::string::npos) {
            return;
        }
        output.push_back(std::make_pair(prefix, node));
        if (node.IsMap()) {
            for (auto it = node.begin(); it != node.end(); ++it) {
                ListAllMenber(prefix.empty() ? it->first.Scalar() : prefix + "." + it->first.Scalar(), it->second,
                              output);
            }
        }
    }

    void Config::LoadFromYaml(const char* file)
    {
        YAML::Node root = YAML::LoadFile(file);
        std::list<std::pair<std::string, YAML::Node>> all_node;
        ListAllMenber("", root, all_node);

        for (auto& i : all_node) {
            std::string key = i.first;
            if (key.empty())
                continue;

            std::transform(key.begin(), key.end(), key.begin(), ::tolower);
            auto var = Lookup(key);
            if (var) {
                if (i.second.IsScalar()) {
                    var->fromString(i.second.Scalar());
                } else {
                    std::stringstream ss;
                    ss << i.second;
                    var->fromString(ss.str());
                }
            }
        }
    }

    void Config::Visit(std::function<void(const ConfigVarBase::ptr&)> visitor)
    {
        RWMutexType::ReadLock locl(GetMutex());
        ConfigVarMap& m = GetDatas();
        for (auto it = m.begin(); it != m.end(); ++it) {
            visitor(it->second);
        }
    }
}  // namespace miruy