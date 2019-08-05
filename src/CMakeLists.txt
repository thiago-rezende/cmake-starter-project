# Setting the sources for the app
set(MYAPP_SOURCES
    # Precompiled headers
    "pch.h"
    "pch.cpp"
    # Main application
    "main.cpp"
)

# Setting the executable for the app
add_executable(myapp ${MYAPP_SOURCES})
# Setting the app properties for the app
set_property(TARGET myapp PROPERTY CXX_STANDARD 17)

# Setting custom commandos to copy all needed files to the right location
add_custom_target(copy_resources ALL
    COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/src/assets ${CMAKE_BINARY_DIR}/bin/assets
    COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/src/assets ${CMAKE_SOURCE_DIR}/bin/assets
    DEPENDS myapp)

# Setting the install command to the app
install(TARGETS myapp RUNTIME DESTINATION bin)

# Precompiled deader setup
add_precompiled_header(myapp pch.h pch.cpp)
