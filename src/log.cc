#include <iostream>
#include <unistd.h>
#include "log.h"
#include "config.h"
#include "thread.h"
#include "util.h"

namespace miruy {

static const char* LevelToString(LogLevel level)
{
    switch (level) {
        case LogLevel::DEBUG: return "debug";
        case LogLevel::INFO: return "info";
        case LogLevel::WARN: return "warn";
        case LogLevel::ERROR: return "error";
        case LogLevel::FATAL: return "fatal";
        default: return "unknow";
    }
}

static LogLevel StrToLevel(const std::string& str)
{
    std::string _str = str;
    std::transform(str.begin(), str.end(), _str.begin(), ::tolower);
    if (_str == "debug" || _str == "1")
        return LogLevel::DEBUG;
    if (_str == "info" || _str == "2")
        return LogLevel::INFO;
    if (_str == "warn" || _str == "3")
        return LogLevel::WARN;
    if (_str == "error" || _str == "4")
        return LogLevel::ERROR;
    if (_str == "fatal" || _str == "5")
        return LogLevel::FATAL;
    return LogLevel::UNKNOW;
}

static const char* U64TimeToString(uint64_t time_us, bool usec = false)
{
    static time_t ts;
    static char date[32];
    ts = time_us / 1000000;
    memset(date, 0, sizeof(date));
    size_t size = ::strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", ::localtime(&ts));
    if (usec) {
        date[size++] = 0x2e;  // '.'
        uint8_t i = 6;
        int us = time_us % 1000000;
        while (i--) {
            date[size + i] = 0x30 + us % 10;  // '0' + 尾数
            us /= 10;
        }
    }
    return date;
}

LogEvent::LogEvent(std::shared_ptr<Logger> logger, const char* file, uint32_t line)
    : m_file(file), m_line(line), m_elapse(0), m_time(GetMicroSec()), m_logger(logger)
{
}

LogEventWrap::LogEventWrap(LogEvent::ptr event, LogLevel level) : m_level(level), m_event(event) {}

LogEventWrap::~LogEventWrap()
{
    m_event->getLogger()->log(m_level, m_event);
}

LogFormatter::LogFormatter(const std::string& pattern) : m_pattern(pattern)
{
    if (m_pattern.empty()) {
        m_pattern = "[%d]%T[%u]%T%t%T%F%T[%p]: %m%n";
    }
}

void LogFormatter::setPattern(const std::string& pattern)
{
    m_pattern = pattern;
    if (m_pattern.empty()) {
        m_pattern = "[%d]%T[%u]%T%t%T%F%T[%p]: %m%n";
    }
}

void LogFormatter::format(std::ostream& os,
                          LogLevel level,
                          const std::string& name,
                          LogEvent::ptr event,
                          bool usec) const
{
    int i = 0, l = 0, len = m_pattern.size();
    while (i < len) {
        if (m_pattern[i] != 0x25) {
            ++i;
            ++l;
            continue;
        }
        if (l > 0) {
            os << m_pattern.substr(i - l, l);
            l = 0;
        }
        ++i;
        if (i >= len) {
            os << m_pattern[i - 1];
            break;
        }
        switch (m_pattern[i]) {
            case 'd': os << U64TimeToString(event->getTime(), usec); break;
            case 'u': os << name; break;
            case 't': os << miruy::GetThreadId(); break;
            case 'N': os << miruy::Thread::GetName(); break;
            case 'F': os << miruy::GetFiberId(); break;
            case 'p': os << LevelToString(level); break;
            case 'l': os << event->getLine(); break;
            case 'm': os << event->getSS().str(); break;
            case 'f': os << event->getFile(); break;
            case 'n': os << "\n"; break;
            case 'T': os << "\t"; break;
            case 'r': os << event->getElapse(); break;
            default: os << m_pattern[i - 1] << m_pattern[i];
        }
        ++i;
    }
}

void StdoutAppender::log(LogLevel level,
                         const std::string& name,
                         LogEvent::ptr event,
                         const LogFormatter::ptr& formatter,
                         bool usec) const
{
    if (level < m_level)
        return;
    MutexType::Lock lock(m_mutex);
    formatter->format(std::cout, level, name, event, usec);
}

std::string StdoutAppender::toYamlString() const
{
    MutexType::Lock lock(m_mutex);
    YAML::Node node;
    node["type"] = "StdoutAppender";
    node["level"] = LevelToString(m_level);
    std::stringstream ss;
    ss << node;
    return ss.str();
}

FileAppender::FileAppender(const std::string& file, LogLevel level)
    : LogAppender(level), m_file(file)
{
}

void FileAppender::log(LogLevel level,
                       const std::string& name,
                       LogEvent::ptr event,
                       const LogFormatter::ptr& formatter,
                       bool usec) const
{
    if (level < m_level)
        return;

    if (access(m_file.data(), W_OK) || !m_stream.is_open())
        this->reopen();
    MutexType::Lock lock(m_mutex);
    formatter->format(m_stream, level, name, event, usec);
    m_stream.flush();
}

std::string FileAppender::toYamlString() const
{
    MutexType::Lock lock(m_mutex);
    YAML::Node node;
    node["type"] = "FileAppender";
    node["level"] = LevelToString(m_level);
    node["file"] = m_file;
    std::stringstream ss;
    ss << node;
    return ss.str();
}

bool FileAppender::reopen() const
{
    MutexType::Lock lock(m_mutex);
    if (m_stream) {
        m_stream.close();
    }
    m_stream.open(m_file, std::ios::app);
    return m_stream.is_open();
}

Logger::Logger(const std::string& user, bool stdoutAppender, const std::string& pattern, bool usec)
    : m_level(LogLevel::DEBUG), m_user(user), m_formatter(new LogFormatter(pattern)), m_usec(usec)
{
    if (stdoutAppender)
        m_appenders.push_back(LogAppender::ptr(new StdoutAppender()));
}

void Logger::setPattern(const std::string& pattern)
{
    MutexType::Lock lock(m_mutex);
    m_formatter->setPattern(pattern);
}

void Logger::addAppender(const LogAppender::ptr& appender)
{
    MutexType::Lock lock(m_mutex);
    auto it = std::find(m_appenders.begin(), m_appenders.end(), appender);
    if (it == m_appenders.end()) {
        m_appenders.push_back(appender);
    }
}

void Logger::clearAppender()
{
    MutexType::Lock lock(m_mutex);
    m_appenders.clear();
}

void Logger::log(LogLevel level, const LogEvent::ptr& event) const
{
    if (level >= m_level) {
        MutexType::Lock lock(m_mutex);
        for (auto& i : m_appenders) {
            i->log(level, m_user, event, m_formatter, m_usec);
        }
    }
}

void Logger::debug(const LogEvent::ptr& event) const
{
    this->log(LogLevel::DEBUG, event);
}
void Logger::info(const LogEvent::ptr& event) const
{
    this->log(LogLevel::INFO, event);
}
void Logger::warn(const LogEvent::ptr& event) const
{
    this->log(LogLevel::WARN, event);
}
void Logger::error(const LogEvent::ptr& event) const
{
    this->log(LogLevel::ERROR, event);
}
void Logger::fatal(const LogEvent::ptr& event) const
{
    this->log(LogLevel::FATAL, event);
}

std::string Logger::toYamlString() const
{
    MutexType::Lock lock(m_mutex);
    YAML::Node node;
    node["name"] = m_user;
    node["formatter"] = m_formatter->getPattern();
    node["level"] = LevelToString(m_level);
    node["us"] = m_usec ? "true" : "false";
    for (auto& i : m_appenders)
        node["appender"].push_back(YAML::Load(i->toYamlString()));

    std::stringstream ss;
    ss << node;
    return ss.str();
}

LoggerManager::LoggerManager()
    : m_sys_logger(new Logger("system", true, "[%d]%T[%u]%T%t%T%F%T[%p]: %m%n"))
{
}

void LoggerManager::addLogger(const Logger::ptr& logger)
{
    MutexType::Lock lock(m_mutex);
    m_loggers[logger->getName()] = logger;
}

Logger::ptr LoggerManager::getLogger(const std::string& user) const
{
    MutexType::Lock lock(m_mutex);
    auto it = m_loggers.find(user);
    if (it != m_loggers.end())
        return it->second;
    if (user == "system")
        return m_sys_logger;
    return nullptr;
}

struct LogAppenderDefine {
    int type{ 0 };  // 1 - stdout  2 - file	other - unknow
    LogLevel level{ LogLevel::UNKNOW };
    std::string file;

    bool operator==(const LogAppenderDefine& oth) const
    {
        return type == oth.type && file == oth.file && level == oth.level;
    }
};

struct LoggerDefine {
    LogLevel level{ LogLevel::UNKNOW };
    bool us;
    std::string name;
    std::string formatter;
    std::vector<LogAppenderDefine> appenders;

    bool operator==(const LoggerDefine& oth) const
    {
        return name == oth.name && level == oth.level && us == oth.us &&
               formatter == oth.formatter && appenders == oth.appenders;
    }

    bool operator<(const LoggerDefine& oth) const { return name < oth.name; }
};

static miruy::ConfigVar<std::set<LoggerDefine>>::ptr g_log_defines =
    miruy::Config::Lookup("logs", std::set<LoggerDefine>(), "logs config");

struct _LogIniter {
    _LogIniter()
    {
        g_log_defines->addListener(
            [](const std::set<LoggerDefine>& old_val, const std::set<LoggerDefine>& new_val) {
                for (auto& i : new_val) {
                    auto it = old_val.find(i);
                    Logger::ptr logger;
                    if (it == old_val.end()) {
                        /*add Logger*/
                        logger.reset(new Logger(i.name, false));
                        LoggerMgr::getInstance()->addLogger(logger);
                    } else {
                        if (!(i == *it)) {
                            /*update Logger*/
                            logger = LoggerMgr::getInstance()->getLogger(i.name);
                        }
                    }

                    if (logger) {
                        logger->clearAppender();
                        logger->setPattern(i.formatter);
                        logger->setUsec(i.us);
                        logger->setLevel(i.level);
                        for (auto& a : i.appenders) {
                            if (a.type == 1) {  // StdoutAppender
                                logger->addAppender(LogAppender::ptr(new StdoutAppender(a.level)));
                            } else if (a.type == 2) {  // FileAppender
                                logger->addAppender(
                                    LogAppender::ptr(new FileAppender(a.file, a.level)));
                            }
                        }
                    }
                }

                for (auto& i : old_val) {
                    auto it = new_val.find(i);
                    if (it == new_val.end()) {
                        /*delete Logger*/
                        auto logger = LoggerMgr::getInstance()->getLogger(i.name);
                        if (logger) {
                            logger->setLevel((LogLevel)100);
                            logger->clearAppender();
                        }
                    }
                }
            });
    }
};

static _LogIniter _log_init;
}  // namespace miruy

namespace miruy {

template <>
class LexicalCast<std::string, std::set<LoggerDefine>>
{
public:
    std::set<LoggerDefine> operator()(const std::string& str)
    {
        YAML::Node nodes = YAML::Load(str);
        std::set<LoggerDefine> logger_set;

        for (size_t i = 0; i < nodes.size(); ++i) {
            auto node = nodes[i];
            LoggerDefine logger;
            if (!node["name"].IsDefined())
                continue;

            logger.name = node["name"].as<std::string>();
            logger.us = node["us"].IsDefined() ? node["us"].as<bool>() : false;
            logger.level = node["level"].IsDefined() ? StrToLevel(node["level"].as<std::string>()) :
                                                       LogLevel::UNKNOW;
            logger.formatter =
                node["formatter"].IsDefined() ? node["formatter"].as<std::string>() : "";

            if (node["appender"].IsDefined()) {
                for (size_t j = 0; j < node["appender"].size(); ++j) {
                    auto a = node["appender"][j];
                    if (!a["type"].IsDefined())
                        continue;

                    LogAppenderDefine lad;
                    std::string type = a["type"].as<std::string>();
                    if (type == "StdoutAppender") {
                        lad.type = 1;
                    } else if (type == "FileAppender") {
                        lad.type = 2;
                        if (!a["file"].IsDefined())
                            continue;
                        lad.file = a["file"].as<std::string>();
                    } else {
                        continue;
                    }
                    lad.level = a["level"].IsDefined() ? StrToLevel(a["level"].as<std::string>()) :
                                                         logger.level;

                    logger.appenders.push_back(std::move(lad));
                }
            }
            logger_set.insert(std::move(logger));
        }

        return logger_set;
    }
};

template <>
class LexicalCast<std::set<LoggerDefine>, std::string>
{
public:
    std::string operator()(const std::set<LoggerDefine>& logger_set)
    {
        YAML::Node nodes;
        for (auto& logger : logger_set) {
            YAML::Node node;

            node["name"] = logger.name;
            node["us"] = logger.us ? "true" : "false";
            node["level"] = LevelToString(logger.level);
            node["formatter"] = logger.formatter;

            for (auto& a : logger.appenders) {
                YAML::Node n;
                if (a.type == 1) {
                    n["type"] = "StdoutAppender";
                } else if (a.type == 2) {
                    n["type"] = "FileAppender";
                    n["file"] = a.file;
                }
                n["level"] = LevelToString(a.level);
                node["appender"].push_back(std::move(n));
            }
            nodes.push_back(std::move(node));
        }
        std::stringstream ss;
        ss << nodes;
        return ss.str();
    }
};

}  // namespace miruy
