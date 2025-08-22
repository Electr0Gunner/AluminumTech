#pragma once

#if defined(_MSC_VER)
    #define ALTECH_DEBUG_BREAK() __debugbreak();
#elif defined(__GNUC__)
    #define ALTECH_DEBUG_BREAK() __builtin_trap();
#else
    #define ALTECH_DEBUG_BREAK() std::abort();
#endif