cmake_minimum_required(VERSION 3.14.0)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

add_subdirectory(proj_test)

set_property(TARGET proj_test PROPERTY CXX_STANDARD 17)
