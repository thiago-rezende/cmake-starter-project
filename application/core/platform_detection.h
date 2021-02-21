/**
 * @file platform_detection.h
 * @brief Platorm detection using predefined macros
 *
 * This header will provide some macros to identify the platform.
 * This can be used for compile time restrictions or for platform specific code sections.
 *
 * To apply platform restrictions, just uncomment the #error on the desired platform
 *
 */
#pragma once

/* Check for Emscripten */
#if defined(__EMSCRIPTEN__)
#define H_PLATFORM_EMSCRIPTEN
// #error "[PLATFORM]: Emscripten platform is not supported!"
/* Check for Windows platform */
#elif defined(_WIN32)
#define H_PLATFORM_WINDOWS
// #error "[PLATFORM]: Windows platform is not supported!"
/* Windows x64/x86 */
#if defined(_WIN64)
/* Windows x64  */
#define H_PLATFORM_WINDOWS_64
// #error "[PLATFORM]: x64 Builds are not supported!"
#else // _WIN64
/* Windows x86 */
#define H_PLATFORM_WINDOWS_86
// #error "[PLATFORM]: x86 Builds are not supported!"
#endif // _WIN32
/* Check for Apple flatofrms */
#elif defined(__APPLE__) || defined(__MACH__)
#define H_PLATFORM_APPLE
// #error "[PLATFORM]: Apple platforms are not supported!"
#include <TargetConditionals.h>
/* TARGET_OS_MAC exists on all the platforms
* so we must check all of them (in this order)
* to ensure that we're running on MAC
* and not some other Apple platform
*/
#if TARGET_IPHONE_SIMULATOR == 1
#define H_PLATFORM_IOS_SIMULATOR
// #error "[PLATFORM]: IOS simulator is not supported!"
#elif TARGET_OS_IPHONE == 1
#define H_PLATFORM_IOS
// #error "[PLATFORM]: IOS is not supported!"
#elif TARGET_OS_MAC == 1
#define H_PLATFORM_MACOS
// #error "[PLATFORM]: MacOS is not supported!"
#else
#error "[PLATFORM]: Unknown Apple platform!"
#endif // __APPLE__ || __MACH__
/* We also have to check __ANDROID__ before __linux__
 * since android is based on the linux kernel
 * it has __linux__ defined
 */
#elif defined(__ANDROID__)
#define H_PLATFORM_ANDROID
// #error "[PLATFORM]: Android is not supported!"
#elif defined(__linux__)
#define H_PLATFORM_LINUX
// #error "[PLATFORM]: Linux is not supported!"
#else // __linux__
/* Unknown compiler/platform */
#error "[PLATFORM]: Unknown platform!"
#endif
