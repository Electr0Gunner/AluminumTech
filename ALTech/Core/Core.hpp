#pragma once

#ifdef _DEBUG
    #define ALTECH_DEBUG
    #define ALTECH_LOGGING_ENABLED
    #define ALTECH_ASSERTS_ENABLED
#endif

#ifdef ALTECH_PLATFORM_WINDOWS
    #ifdef ALTECH_BUILD_DLL
        #define ALTECH_API __declspec(dllexport)
    #else
        #define ALTECH_API __declspec(dllimport)
    #endif
#else
    #error ALTech supports only windows for now.
#endif