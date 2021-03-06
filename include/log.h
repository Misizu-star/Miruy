#ifndef __MIRUY_LOG_H__
#define __MIRUY_LOG_H__

#include <fstream>
#include <memory>
#include <string>
#include <sstream>
#include <list>
#include <unordered_map>
#include "singleton.h"
#include "mutex.h"

#define LOGGER(name) miruy::LoggerMgr::getInstance()->getLogger(std::string(name))

#define LOG_LEVEL(logger, level)                                                                   \
    if (miruy::Logger::ptr(logger))                                                                \
    miruy::LogEventWrap(miruy::LogEvent::ptr(new miruy::LogEvent(logger, __FILE__, __LINE__)),     \
                        (miruy::LogLevel)level)                                                    \
        .getSS()

#define LOG_DEBUG(logger) LOG_LEVEL(logger, 1)
#define LOG_INFO(logger) LOG_LEVEL(logger, 2)
#define LOG_WARN(logger) LOG_LEVEL(logger, 3)
#define LOG_ERROR(logger) LOG_LEVEL(logger, 4)
#define LOG_FATAL(logger) LOG_LEVEL(logger, 5)

namespace miruy {

class Logger;

/**
 * @brief 日志等级
 */
enum class LogLevel : uint32_t {
    UNKNOW = 0,  // unknow  级别
    DEBUG = 1,   // debug   级别
    INFO = 2,    // info    级别
    WARN = 3,    // warn    级别
    ERROR = 4,   // error   级别
    FATAL = 5    // fatal   级别
};

/**
 * @brief 日志事件
 * 该类中记录了 触发事件的文件、触发事件具体行数、启动耗时、线程号、协程号、日期以及消息内容
 */
class LogEvent
{
public:
    using ptr = std::shared_ptr<LogEvent>;
    LogEvent(std::shared_ptr<Logger> logger, const char* file, uint32_t line);

    const char* getFile() const { return m_file; }
    uint32_t getLine() const { return m_line; }
    uint32_t getElapse() const { return m_elapse; }
    uint64_t getTime() const { return m_time; }
    std::shared_ptr<Logger> getLogger() const { return m_logger; }
    std::stringstream& getSS() { return m_ss; }

private:
    uint32_t m_line;
    uint32_t m_elapse;
    const char* m_file;
    uint64_t m_time;
    std::shared_ptr<Logger> m_logger;
    std::stringstream m_ss;
};

class LogEventWrap
{
public:
    using ptr = std::shared_ptr<LogEventWrap>;
    LogEventWrap(LogEvent::ptr event, LogLevel level);
    ~LogEventWrap();

    LogEvent::ptr getEvent() const { return m_event; }
    std::stringstream& getSS() { return m_event->getSS(); }

private:
    LogLevel m_level;
    LogEvent::ptr m_event;
};

/**
 * @brief 日志事件格式器
 * 用于格式化日志事件，默认格式为："[%d]%T[%u]%T[%p]: %m%n"
 * 预设格式如下：
 *      %d: 时间    %u: 用户名    %t: 线程号    %N: 线程名    %F: 协程号    %p: 日志等级
 *      %l: 行号    %f: 文件名    %m: 消息体    %n: 换行符    %T: 制表符    %r: 启动耗时
 */
class LogFormatter
{
public:
    using ptr = std::shared_ptr<LogFormatter>;
    LogFormatter(const std::string& pattern);

    void setPattern(const std::string& pattern);
    const std::string& getPattern() const { return m_pattern; }
    void format(std::ostream& os,
                LogLevel level,
                const std::string& name,
                LogEvent::ptr event,
                bool usec) const;

private:
    std::string m_pattern;  // 格式化模板
};

/**
 * @brief 日志输出地 -- 基类
 * 用于输出格式化后的日志事件
 */
class LogAppender
{
public:
    using ptr = std::shared_ptr<LogAppender>;
    using MutexType = SpinLock;
    LogAppender(LogLevel level) : m_level(level) {}

    void setLevel(LogLevel level) { m_level = level; }
    LogLevel getLevel() const { return m_level; }

    virtual void log(LogLevel level,
                     const std::string& name,
                     LogEvent::ptr event,
                     const LogFormatter::ptr& formatter,
                     bool usec = false) const = 0;

    virtual std::string toYamlString() const = 0;

    virtual ~LogAppender() = default;

protected:
    LogLevel m_level;  // 最低日志等级
    mutable MutexType m_mutex;
};

/**
 * @brief 日志输出地
 * 标准输出/屏幕控制台打印，默认日志等级为 debug
 */
class StdoutAppender : public LogAppender
{
public:
    using ptr = std::shared_ptr<StdoutAppender>;
    StdoutAppender(LogLevel level = LogLevel::DEBUG) : LogAppender(level) {}

    void log(LogLevel level,
             const std::string& name,
             LogEvent::ptr event,
             const LogFormatter::ptr& formatter,
             bool usec = false) const override;

    std::string toYamlString() const override;
};

/**
 * @brief 日志输出地
 * 文件输出，默认日志等级为 warn
 */
class FileAppender : public LogAppender
{
public:
    using ptr = std::shared_ptr<FileAppender>;
    FileAppender(const std::string& file, LogLevel level = LogLevel::WARN);

    void log(LogLevel level,
             const std::string& name,
             LogEvent::ptr event,
             const LogFormatter::ptr& formatter,
             bool usec = false) const override;

    std::string toYamlString() const override;

    ~FileAppender() { m_stream.close(); }

private:
    bool reopen() const;

private:
    std::string m_file;
    mutable std::ofstream m_stream;
};

/**
 * @brief 日志器
 */
class Logger
{
public:
    using ptr = std::shared_ptr<Logger>;
    using MutexType = SpinLock;
    Logger(const std::string& user,
           bool stdoutAppender = false,
           const std::string& pattern = "",
           bool usec = false);

    void setLevel(LogLevel level) { m_level = level; }
    LogLevel getLevel() const { return m_level; }
    const std::string& getName() const { return m_user; }
    void setPattern(const std::string& pattern);
    void setUsec(bool usec) { m_usec = usec; }

    void addAppender(const LogAppender::ptr& appender);
    void clearAppender();

    void log(LogLevel level, const LogEvent::ptr& event) const;
    void debug(const LogEvent::ptr& event) const;
    void info (const LogEvent::ptr& event) const;
    void warn (const LogEvent::ptr& event) const;
    void error(const LogEvent::ptr& event) const;
    void fatal(const LogEvent::ptr& event) const;

    std::string toYamlString() const;

private:
    LogLevel m_level;
    LogFormatter::ptr m_formatter;
    bool m_usec;
    std::string m_user;
    mutable MutexType m_mutex;
    std::list<LogAppender::ptr> m_appenders;
};

/**
 * @brief 日志器管理器
 * 根据不同用户，管理不同的日志器
 */
class LoggerManager
{
public:
    using MutexType = SpinLock;
    LoggerManager();

    void addLogger(const Logger::ptr& logger);
    Logger::ptr getLogger(const std::string& user) const;

private:
    Logger::ptr m_sys_logger;
    mutable MutexType m_mutex;
    std::unordered_map<std::string, Logger::ptr> m_loggers;
};

using LoggerMgr = SingletonPtr<LoggerManager>;

}  // namespace miruy

#endif