/**
 * @file pch.hpp
 * @brief Pre-Compiled Header
 *
 */

#pragma once

/* Windows Stuff */
#ifdef WIN32

/* Exclude rarely-used services from Windows headers */
#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif // VC_EXTRALEAN

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif // WIN32_LEAN_AND_MEAN

/* Windows Header */
#include <Windows.h>

#endif // WIN32

/* StdLib Stuff */
#include <mutex>
#include <string>
#include <thread>
#include <chrono>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <filesystem>

/* Application Config */
#include "config.h"

/* Horus Logger */
#include "core/logger.h"
#include "debug/assert.h"
#include "debug/instrumentor.h"
