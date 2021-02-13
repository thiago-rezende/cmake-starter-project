/**
 * @file pch.hpp
 * @brief Pre-Compiled Header
 *
 * This file is auto included in all cpp files by cmake
 *
 */

#pragma once

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
