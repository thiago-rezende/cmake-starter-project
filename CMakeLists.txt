# Minimum version to run the script
cmake_minimum_required(VERSION 3.16.0)

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
        VERSION 3.0.5
        DESCRIPTION "A Simple C++ Starter Project Using CMake"
        HOMEPAGE_URL "https://github.com/thiago-rezende/cmake-starter-project"
        LANGUAGES CXX)

# Add the cmake folder so the modules path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

# Setting the install prefix
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

# Setting the output dirs config
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

# Adding the vendor libs directories
add_subdirectory(${VENDOR}/catch2)
add_subdirectory(${VENDOR}/spdlog)

# Setting project options
option(USE_STATIC_RUNTIME "Uses MSVC static linked runtime" OFF)
option(BUILD_DOCUMENTATION "Build documentation for the project (requires Doxygen)" OFF)

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
    ## Tests
    set_property(TARGET application_tests PROPERTY FOLDER "Tests")
    ## Vendor
    # Catch2
    set_property(TARGET Catch2 PROPERTY FOLDER "Vendor/Catch2")
    set_property(TARGET Catch2WithMain PROPERTY FOLDER "Vendor/Catch2")
    # Spdlog
    set_property(TARGET spdlog PROPERTY FOLDER "Vendor/Spdlog")
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

if(USE_STATIC_RUNTIME)
    message(STATUS "[OPTION] RUNTIME_TYPE -> Static")
else()
    message(STATUS "[OPTION] RUNTIME_TYPE -> Dynamic")
endif()

message(STATUS "[OPTION] BUILD_DOCUMENTATION -> ${BUILD_DOCUMENTATION}")
