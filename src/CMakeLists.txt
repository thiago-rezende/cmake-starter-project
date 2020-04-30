# Setting the sources for the app
set(APPLICATION_SOURCES
    # Config File
    "project_config.h"
    # Precompiled headers
    "pch.h"
    "pch.cpp"
    # Logging System
    "log/log.cpp"
    "log/log.h"
    # Main application
    "main.cpp")

# Setting the executable for the app
add_executable(${EXE_NAME} ${APPLICATION_SOURCES})
# Setting the app properties for the app
set_property(TARGET ${EXE_NAME} PROPERTY CXX_STANDARD 17)
# Setting the logger variable
target_compile_definitions(${EXE_NAME} PRIVATE -DH_DEBUG)
# Setting the src default include dir
target_include_directories(${EXE_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)

### Linking the third-party libs
## Scripting
# Lua
target_include_directories(${EXE_NAME} PUBLIC ${LUA_LIB_INCLUDE})
target_link_libraries(${EXE_NAME} PUBLIC lua_static)
# Sol3
target_include_directories(${EXE_NAME} PUBLIC ${VENDOR}/scripting/sol3/include)
target_link_libraries(${EXE_NAME} INTERFACE sol2::sol2)
## Utils
# Spdlog
target_include_directories(${EXE_NAME} PUBLIC ${VENDOR}/utils/spdlog/include)
target_link_libraries(${EXE_NAME} PUBLIC spdlog::spdlog)
## Graphics
# OpenGL
target_link_libraries(${EXE_NAME} PUBLIC OpenGL::GL)
# GLFW
target_include_directories(${EXE_NAME} PUBLIC ${VENDOR}/graphics/glfw/include)
target_link_libraries(${EXE_NAME} PUBLIC glfw)

# Setting custom commandos to copy all needed files to the right location
add_custom_target(copy_resources ALL
    COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/src/assets ${CMAKE_BINARY_DIR}/bin/assets
    COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/src/assets ${CMAKE_SOURCE_DIR}/bin/assets
    DEPENDS ${EXE_NAME})

# Setting the install command to the app
install(TARGETS ${EXE_NAME} RUNTIME DESTINATION bin)

# Precompiled deader setup
add_precompiled_header(${EXE_NAME} pch.h pch.cpp)
