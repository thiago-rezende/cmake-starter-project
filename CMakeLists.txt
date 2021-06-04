# Minimum version to run the script
cmake_minimum_required(VERSION 3.16.0)

# Policies
cmake_policy(SET CMP0091 NEW) # MSVC runtime library flags are selected by an abstraction.

# VCPKG Library Manager
# if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
#     set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
# endif()

# Conan Package Manager
# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# conan_basic_setup()

# Setting build type
set(DEFAULT_BUILD_TYPE "Debug")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Setting up the project name and version
project(CMakeStarterProject
        VERSION 3.1.2
        DESCRIPTION "A Simple C++ Starter Project Using CMake"
        HOMEPAGE_URL "https://github.com/thiago-rezende/cmake-starter-project"
        LANGUAGES CXX)

# Add the cmake folder so the modules path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

# Setting the install dirs
# set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
include(GNUInstallDirs)

# Setting the output dirs config
# First for the generic no-config case (e.g. with mingw)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
# Second, for multi-config builds (e.g. msvc)
foreach(OUTPUT_CONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUT_CONFIG} OUTPUT_CONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUT_CONFIG} ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUT_CONFIG} ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUT_CONFIG} ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
endforeach(OUTPUT_CONFIG CMAKE_CONFIGURATION_TYPES)

# Project options
option(USE_MSVC_STATIC_RUNTIME "Uses MSVC static linked runtime" ON)
option(BUILD_DOCUMENTATION "Build documentation for the project (requires Doxygen)" OFF)

# MSVC Runtime
if(USE_MSVC_STATIC_RUNTIME)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
else()
    set(CMAKE_MSVC_RUNTIME_LIBRARY  "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

# Setting the path to the vendor folder
set(VENDOR ${CMAKE_SOURCE_DIR}/vendor)

## Vendor options
# Spdlog options
option(SPDLOG_ENABLE_PCH "Build static or shared library using precompiled header to speed up compilation time" ON)

# Doctest options
option(DOCTEST_WITH_TESTS               "Build tests/examples" OFF)
option(DOCTEST_WITH_MAIN_IN_STATIC_LIB  "Build a static lib (cmake target) with a default main entry point" ON)
option(DOCTEST_NO_INSTALL               "Skip the installation process" ON)
option(DOCTEST_USE_STD_HEADERS          "Use std headers" ON)

# Adding the vendor libs directories
add_subdirectory(${VENDOR}/spdlog)
add_subdirectory(${VENDOR}/doctest)

# Generate an config.h file based on config.h.in file
configure_file(${CMAKE_SOURCE_DIR}/application/config.h.in ${CMAKE_SOURCE_DIR}/application/config.h @ONLY NEWLINE_STYLE LF)

# Setting the project folders
add_subdirectory(application)

# Adding docs generation
add_subdirectory(docs)

# Adding Tests
enable_testing()
add_subdirectory(tests)

# Visual Studio Config
if(MSVC)
    ## Enable folders
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    ## Application
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT application)
    set_property(TARGET application PROPERTY FOLDER "Application")
    ## Docs
    if(BUILD_DOCUMENTATION)
        set_property(TARGET doxygen PROPERTY FOLDER "Docs")
    endif()
    ## Utils
    set_property(TARGET copy_resources_application PROPERTY FOLDER "Utils")
    if(BUILD_DOCUMENTATION)
        set_property(TARGET copy_doxygen_documentation PROPERTY FOLDER "Utils")
    endif()
    ## Tests
    set_property(TARGET application_tests PROPERTY FOLDER "Tests")
    ## Vendor
    # Spdlog
    set_property(TARGET spdlog PROPERTY FOLDER "Vendor/Spdlog")
    set_property(TARGET spdlog_header_only PROPERTY FOLDER "Vendor/Spdlog")
    # Doctest
    set_property(TARGET doctest PROPERTY FOLDER "Vendor/Doctest")
    set_property(TARGET doctest_with_main PROPERTY FOLDER "Vendor/Doctest")
endif(MSVC)

# Log info
message(STATUS "[INFO] CMAKE_BUILD_TYPE -> ${CMAKE_BUILD_TYPE}")
message(STATUS "[INFO] CMAKE_MODULE_PATH -> ${CMAKE_MODULE_PATH}")
message(STATUS "[INFO] CMAKE_INSTALL_PREFIX -> ${CMAKE_INSTALL_PREFIX}")
message(STATUS "[INFO] CMAKE_RUNTIME_OUTPUT_DIRECTORY -> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "[INFO] CMAKE_LIBRARY_OUTPUT_DIRECTORY -> ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(STATUS "[INFO] CMAKE_ARCHIVE_OUTPUT_DIRECTORY -> ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message(STATUS "[INFO] VENDOR -> ${VENDOR}")

if(DEFINED CMAKE_TOOLCHAIN_FILE)
    message(STATUS "[INFO] CMAKE_TOOLCHAIN_FILE -> ${CMAKE_TOOLCHAIN_FILE}")
endif()

if(DEFINED VCPKG_CHAINLOAD_TOOLCHAIN_FILE)
    message(STATUS "[INFO] VCPKG_CHAINLOAD_TOOLCHAIN_FILE -> ${VCPKG_CHAINLOAD_TOOLCHAIN_FILE}")
endif()

if(USE_MSVC_STATIC_RUNTIME)
    message(STATUS "[OPTION] RUNTIME_TYPE -> Static")
else()
    message(STATUS "[OPTION] RUNTIME_TYPE -> Dynamic")
endif()

message(STATUS "[OPTION] BUILD_DOCUMENTATION -> ${BUILD_DOCUMENTATION}")
