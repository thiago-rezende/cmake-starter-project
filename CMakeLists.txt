# Minimum version to run the script
cmake_minimum_required(VERSION 3.16.0)

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
        VERSION 2.2.4
        DESCRIPTION "A Simple C++ Starter Project Using CMake"
        HOMEPAGE_URL "https://github.com/thiago-rezende/cmake-starter-project"
        LANGUAGES CXX)

# Generate an config.h file based on config.in file
configure_file(${CMAKE_SOURCE_DIR}/application/config.in ${CMAKE_SOURCE_DIR}/application/config.h @ONLY NEWLINE_STYLE LF)

# Setting the install prefix
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

# First for the generic no-config case (e.g. with mingw)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# Second, for multi-config builds (e.g. msvc)
foreach(OUTPUT_CONFIG ${CMAKE_CONFIGURATION_TYPES})
    string( TOUPPER ${OUTPUT_CONFIG} OUTPUT_CONFIG )
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUT_CONFIG} ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUT_CONFIG} ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUT_CONFIG} ${CMAKE_BINARY_DIR}/lib)
endforeach(OUTPUT_CONFIG CMAKE_CONFIGURATION_TYPES)

# Setting the path to the vendor folder
set(VENDOR ${CMAKE_SOURCE_DIR}/vendor)

# Spdlog options
option(SPDLOG_ENABLE_PCH "Build static or shared library using precompiled header to speed up compilation time" ON)

# GoogleTest options
option(BUILD_GMOCK "Builds the googlemock subproject" ON)
option(INSTALL_GTEST "Enable installation of googletest. (Projects embedding googletest may want to turn this OFF.)" OFF)

# Adding the vendor libs directories
add_subdirectory(${VENDOR}/googletest)
add_subdirectory(${VENDOR}/spdlog)

# Setting project options
option(MSVC_DYNAMIC_LINKED_RUNTIME "Uses MSVC dynamic linked runtime" OFF)

# Setting the project folders
add_subdirectory(application)

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
    ## Utils
    set_property(TARGET copy_resources_application PROPERTY FOLDER "Utils")
    ## Tests
    set_property(TARGET application_tests PROPERTY FOLDER "Tests")
    ## Vendor
    # Google Test
    set_property(TARGET gtest PROPERTY FOLDER "Vendor/GoogleTest")
    set_property(TARGET gtest_main PROPERTY FOLDER "Vendor/GoogleTest")
    set_property(TARGET gmock PROPERTY FOLDER "Vendor/GoogleTest")
    set_property(TARGET gmock_main PROPERTY FOLDER "Vendor/GoogleTest")
    # Spdlog
    set_property(TARGET spdlog PROPERTY FOLDER "Vendor/Spdlog")
endif(MSVC)
