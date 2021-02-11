/**
 * @file pch.hpp
 * @author Thiago Rezende (thiago-rezende.github.io)
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
#include <iostream>

/* Application Config */
#include "application/config.h"

/* Horus Logger */
#include "application/core/logger.h"
