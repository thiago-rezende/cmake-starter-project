# Minimun versior to run the script
cmake_minimum_required(VERSION 3.1)

# Global CMake Vars
set(PRJ_NAME MyProject)
set(EXE_NAME myapp)

# Chicking version
if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Setting up the project name and version
# project(${PRJ_NAME} VERSION 1.0.0)
project(${PRJ_NAME}
        VERSION 1.0.0.0
        DESCRIPTION "Simple CMake Starter Project"
        HOMEPAGE_URL "https://gitlab.com/thiago-rezende/cmake-starter-project"
        LANGUAGES CXX C)

# Setting the path to the vendor folder
set(VENDOR ${CMAKE_SOURCE_DIR}/vendor)

# Setting CMake module path
list(APPEND CMAKE_MODULE_PATH ${VENDOR}/cmake-pch)

# Loading CMake pch module
include(PrecompiledHeader)

# Setting CXX version
set(CMAKE_CXX_STANDARD_REQUIRED 17)
# Setting the output path to the binaries
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
# Setting the output path to the libraries
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
# Setting the output to the Dinamic Libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# Stting the install prefix
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

## Adding the third-party subdirectories
# Lua
add_subdirectory(${VENDOR}/cmake-lua)
# Sol3
add_subdirectory(${VENDOR}/sol3)

# Adding the source folder
add_subdirectory(src)
