#include "Log.hpp"

#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <cstdlib>


void ALTech::Logger::Log(ALTech::Logger::LogLevel level, const char* file, int line, const char* fmt, ...)
{
    //TODO_PLATFORM: ADD FILENAME FOR MORE PLATFORMS
    const char* filename = std::strrchr(file, '\\');
    if (filename) filename++;
    else filename = file;

    std::printf("%s[%s] ", ColorFromLevel(level), TypeToString(level));

    va_list args;
    va_start(args, fmt);
    std::vprintf(fmt, args);
    va_end(args);

    std::printf(" - (%s:%i)\n", filename, line);
    std::printf("\033[0m\n");

    std::fflush(stdout);
    std::fflush(stderr);
}

void ALTech::Logger::LogAssert(const char* expression, const char* file, int line, const char* message)
{
    if (strcmp(message, "") == 0)
        Log(ALTech::Logger::LogLevel::LEVEL_ERROR, file, line, "Assertion Failed: (%s)", expression);
    else
        Log(ALTech::Logger::LogLevel::LEVEL_ERROR, file, line, "Assertion Failed: (%s) - %s", expression, message);
}