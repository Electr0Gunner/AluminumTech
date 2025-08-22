#pragma once

#include "Core.hpp"
#include "Debug.hpp"

namespace ALTech::Logger
{
    enum LogLevel
    {
        LEVEL_INFO,
        LEVEL_DEBUG,
        LEVEL_WARNING,
        LEVEL_ERROR,
    };

    ALTECH_API void Log(LogLevel level, const char* file, int line, const char* fmt, ...);
    ALTECH_API void LogAssert(const char* expression, const char* file, int line, const char* message);

    /// @brief Get an ANSI color code based on the Log Level
    /// @param level The log level
    /// @return ANSI color code represented as const char*
    inline const char* ColorFromLevel(LogLevel level)
    {
        switch (level)
        {
        case LogLevel::LEVEL_INFO:
            return "\033[32m"; 
        case LogLevel::LEVEL_DEBUG:
            return "\033[36m"; 
        case LogLevel::LEVEL_WARNING:
            return "\033[33m"; 
        case LogLevel::LEVEL_ERROR:
            return "\033[31m"; 
        default:
            return "\033[0m";
        }
    }

    /// @brief Get a string version of the Log Level
    /// @param level The log level
    /// @return the string version of the level
    inline const char* TypeToString(LogLevel level)
    {
        switch (level)
        {
        case LogLevel::LEVEL_INFO:
            return "INFO"; 
        case LogLevel::LEVEL_DEBUG:
            return "DEBUG"; 
        case LogLevel::LEVEL_WARNING:
            return "WARNING"; 
        case LogLevel::LEVEL_ERROR:
            return "ERROR"; 
        default:
            return "UNKNOWN";
        } 
    }
    
} // namespace ALTech


#ifdef ALTECH_LOGGING_ENABLED
    #define ALTECH_LOG_INFO(...) ALTech::Logger::Log(ALTech::Logger::LogLevel::LEVEL_INFO, __FILE__, __LINE__, ##__VA_ARGS__)
    #define ALTECH_LOG_DEBUG(...) ALTech::Logger::Log(ALTech::Logger::LogLevel::LEVEL_DEBUG, __FILE__, __LINE__, ##__VA_ARGS__)
    #define ALTECH_LOG_WARN(...) ALTech::Logger::Log(ALTech::Logger::LogLevel::LEVEL_WARNING, __FILE__, __LINE__, ##__VA_ARGS__)
    #define ALTECH_LOG_ERROR(...) ALTech::Logger::Log(ALTech::Logger::LogLevel::LEVEL_ERROR, __FILE__, __LINE__, ##__VA_ARGS__)
#else
    #define ALTECH_LOG_INFO(...) void(0)
    #define ALTECH_LOG_DEBUG(...) void(0)
    #define ALTECH_LOG_WARN(...) void(0)
    #define ALTECH_LOG_ERROR(...) void(0)
#endif

#ifdef ALTECH_ASSERTS_ENABLED
    #define ALTECH_ASSERT_MESSAGE(expr, message) \
    do { \
        if (!(expr)) { \
            ALTech::Logger::LogAssert(#expr, __FILE__, __LINE__, message); \
            ALTECH_DEBUG_BREAK(); \
        } \
    } while (0); 
    
    #define ALTECH_ASSERT(expr) \
    do { \
        if (!(expr)) { \
            ALTech::Logger::LogAssert(#expr, __FILE__, __LINE__, ""); \
            ALTECH_DEBUG_BREAK(); \
        } \
    } while (0); 
    
#else
    #define ALTECH_ASSERT_MESSAGE(expr, message) void(0)
    #define ALTECH_ASSERT(expr) void(0)
#endif