# Minimum version to run the script
cmake_minimum_required(VERSION 3.16.0)

# Setting build type
set(default_build_type "Debug")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Setting up the project name and version
project(CMakeStarterProject
        VERSION 2.1.0
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
foreach( OUTPUT_CONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUT_CONFIG} OUTPUT_CONFIG )
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUT_CONFIG} ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUT_CONFIG} ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUT_CONFIG} ${CMAKE_BINARY_DIR}/lib)
endforeach( OUTPUT_CONFIG CMAKE_CONFIGURATION_TYPES )

# Setting the path to the vendor folder
set(VENDOR ${CMAKE_SOURCE_DIR}/vendor)

# Adding the vendor libs directories
add_subdirectory(${VENDOR}/spdlog)

# Setting the project folders
add_subdirectory(application)

# Visual Studio Config
if(MSVC)
    # Enable folders
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    # Horus Game Engine
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT application)
    set_property(TARGET application PROPERTY FOLDER "CMakeStarterProject")
    # Vendor
    set_property(TARGET spdlog PROPERTY FOLDER "Vendor")
endif(MSVC)
