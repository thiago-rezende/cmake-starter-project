project(proj_test)

add_executable(proj_test ${SOURCES})

target_sources(proj_test
PUBLIC 
    "src/main.cpp"
    "src/Entity.cpp"
    "include/Entity.h"
)

target_include_directories(proj_test
PUBLIC 
    "include"
)

install(TARGETS proj_test RUNTIME DESTINATION bin)