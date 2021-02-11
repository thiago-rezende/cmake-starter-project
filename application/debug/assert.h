/**
 * @file assert.h
 * @brief Some Assertion Utilities
 *
 */

#pragma once

#include <filesystem>

#ifdef ENABLE_ASSERTIONS

/* Platform Checking for Proper Debugbreak */
#if defined(_WIN32)
#define H_DEBUGBREAK() __debugbreak() // MSVC Debugbreak
#elif defined(__linux__)
#include <signal.h>
#define H_DEBUGBREAK() raise(SIGTRAP) // Linux Debugbreak
#else
#define H_DEBUGBREAK() // No Debugbreak Available
#endif                 // _WIN32 on __linux__

/* Macro Utilities */
#define H_EXPAND_MACRO(x) x
#define H_STRINGIFY_MACRO(x) #x

/* Assertion Macros */
/* Simple assertion with default message */
#define H_ASSERT(check)                                                                                                                            \
    {                                                                                                                                              \
        if (!(check))                                                                                                                              \
        {                                                                                                                                          \
            H_ERROR("Assertion '{0}' failed at {1}:{2}", H_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__); \
            H_DEBUGBREAK();                                                                                                                        \
        }                                                                                                                                          \
    }
/* Simple assertion with custom message */
#define H_ASSERTM(check, message, ...)     \
    {                                      \
        if (!(check))                      \
        {                                  \
            H_ERROR(message, __VA_ARGS__); \
            H_DEBUGBREAK();                \
        }                                  \
    }
#else
#define H_ASSERT(check)
#define H_ASSERTM(check, message, ...)
#endif // ENABLE_ASSERTIONS
