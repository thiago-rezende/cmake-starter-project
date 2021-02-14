# Find Doxigen and require dot, treat the other components as optional
find_package(Doxygen)
option(APPLICATION_BUILD_DOCUMENTATION "Build application documentation (requires Doxygen)" ${DOXYGEN_FOUND})


if(APPLICATION_BUILD_DOCUMENTATION)
    if(NOT DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif()

    # Find all the public headers
    get_target_property(APPLICATION_PUBLIC_HEADER_DIR application INTERFACE_INCLUDE_DIRECTORIES)
    file(GLOB_RECURSE APPLICATION_PUBLIC_HEADERS
        ${APPLICATION_PUBLIC_HEADER_DIR}/*.h
        ${APPLICATION_PUBLIC_HEADER_DIR}/*.hpp
    )

    # This will be the main output of our command
    set(DOXYGEN_INPUT_DIR ${PROJECT_SOURCE_DIR}/application)
    set(DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/docs/doxygen)
    set(DOXYGEN_INDEX_FILE ${DOXYGEN_OUTPUT_DIR}/html/index.html)
    set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # Doxygen variables
    set(DOXYGEN_MAIN_PAGE_MDFILE ${PROJECT_SOURCE_DIR}/README.md)
    set(DOXYGEN_EXAMPLES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/examples)
    set(DOXYGEN_IMAGES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/images)

    # Replace variables inside @@ with the current values
    configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

    file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR}) # Doxygen won't create this for us
    add_custom_command(OUTPUT ${DOXYGEN_INDEX_FILE}
                    DEPENDS ${APPLICATION_PUBLIC_HEADERS}
                    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
                    MAIN_DEPENDENCY ${DOXYFILE_OUT} ${DOXYFILE_IN}
                    COMMENT "Generating docs")

    add_custom_target(doxygen ALL DEPENDS ${DOXYGEN_INDEX_FILE})

endif()
