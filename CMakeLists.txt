cmake_minimum_required(VERSION 3.13.0)
project(AluminumTech VERSION 0.1.0 LANGUAGES C CXX)

option(ALTECH_SHARED_BUILD  "Build AluminumTech as a shared library" ON)
option(ALTECH_SAMPLES  "Build AluminumTech Samples" ON)

#Platform Detection
if(BUILD_SHARED_LIBS)
    add_compile_definitions(ALTECH_BUILD_DLL)
endif()

if(WIN32)
    add_compile_definitions(ALTECH_PLATFORM_WINDOWS)
endif()

file(GLOB_RECURSE ALTech_SRC
    "ALTech/*.cpp"
    "ALTech/*.c"
)
file(GLOB_RECURSE ALTech_HEADER
    "ALTech/*.hpp"
    "ALTech/*.h"
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if(ALTECH_SHARED_BUILD)
    add_library(AluminumTech SHARED ALTech.hpp ${ALTech_SRC} ${ALTech_HEADER})
    target_compile_definitions(AluminumTech PRIVATE ALTECH_BUILD_DLL)
else()
    add_library(AluminumTech STATIC ALTech.hpp ${ALTech_SRC} ${ALTech_HEADER})
endif()

if(ALTECH_SAMPLES)
add_subdirectory(Samples)
endif()
