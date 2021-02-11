# Include dirs
set(APPLICATION_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Header files
set(APPLICATION_HEADERS
    "pch.h"
    "core/logger.h"
    "debug/instrumentor.h"
)

# Source files
set(APPLICATION_SOURCES
    "main.cpp"
    "core/logger.cpp"
)

# Application executable
add_executable(application ${APPLICATION_SOURCES})

# Check for MSVC
if(MSVC)
    # Check for dynamic runtime
    if(USE_MSVC_DYNAMIC_LINKED_RUNTIME)
        set_target_properties(application PROPERTIES
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
        )
    else()
        set_target_properties(application PROPERTIES
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
        )
    endif()
endif()

# Definitions
target_compile_definitions(application
PUBLIC
    # Debug Build
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Debug>:_DEBUG>
    $<$<CONFIG:Debug>:ENABLE_LOG_MACROS>
    $<$<CONFIG:Debug>:ENABLE_PROFILING>
    # Release Build
    $<$<CONFIG:Release>:NDEBUG>
)

# Setting the pre compiled header
target_precompile_headers(application PUBLIC
    "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/pch.hpp>"
)

# Application properties
set_target_properties(application
PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED 17
)

# Applicaiton include dirs
target_include_directories(application
PUBLIC
    ${APPLICATION_INCLUDE_DIRS}
)

# Application libraries
target_link_libraries(application
PUBLIC
    spdlog::spdlog_header_only
)

# Setting custom commandos to copy all needed files to the right location
add_custom_target(copy_resources_application ALL
    COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/application/assets ${CMAKE_BINARY_DIR}/bin/assets
    COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/application/assets ${CMAKE_SOURCE_DIR}/bin/assets
    DEPENDS application)

# Setting the install command to the app
install(TARGETS application RUNTIME DESTINATION bin)
install(TARGETS application LIBRARY DESTINATION lib)
