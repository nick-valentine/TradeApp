#ifndef BUFFER_LOGGER_HPP
#define BUFFER_LOGGER_HPP

#include <cstring>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <string>
#include <utility>

#include "Services/Logger/Logger.hpp"

/**
 * BufferLogger.
 * Log direcly to a vector of strings.
 * Utility class for things like a console window.
 */
class BufferLogger : public Logger
{
public:
    typedef std::pair<Logger::LogLevel, std::string> LogEntry;
    BufferLogger();
    virtual ~BufferLogger();

    void setBufferCapacity(int newCapacity);

    virtual void debug(const char *fmt, ...);
    virtual void info(const char *fmt, ...);
    virtual void warn(const char *fmt, ...);
    virtual void error(const char *fmt, ...);
    virtual void log(Logger::LogLevel level, const char *fmt, ...);

    virtual std::list<LogEntry> &getBuffer();
    int getBufferSize();
protected:
    const static int defaultCapacity;
    virtual void addToBuffer(Logger::LogLevel level, const char *fmt, va_list args); 

    int bufferCapacity;
    int bufferSize;
    std::list<LogEntry> buffer;
};

#endif //BUFFER_LOGGER_HPP
