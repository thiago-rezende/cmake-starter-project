/**
 * @file pch.h
 * @author Thiago Rezende (thiago-rezende.github.io)
 * @brief Pre-Compiled Header
 * @version 0.1
 * @date 2020-09-26
 *
 * @copyright Copyright (c) 2020 Thiago Rezende
 *
 */

#pragma once

#include <iostream>
#include <application/core/logger.h>

/* Windows Things */
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
