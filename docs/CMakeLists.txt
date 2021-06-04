# Documentation CMake Script

if(BUILD_DOCUMENTATION)
    find_package(Doxygen)

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
    set(DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/doxygen)
    set(DOXYGEN_INDEX_FILE ${DOXYGEN_OUTPUT_DIR}/html/index.html)
    set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # Doxygen variables
    set(DOXYGEN_MAIN_PAGE_MDFILE ${PROJECT_SOURCE_DIR}/README.md)
    set(DOXYGEN_EXAMPLES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/examples)
    set(DOXYGEN_IMAGES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/images)
    set(DOXYGEN_LOGO "")
    set(DOXYGEN_HTML_EXTRA_STYLESHEET "${CMAKE_CURRENT_SOURCE_DIR}/theme/doxygen-awesome.css")

    # Replace variables inside @@ with the current values
    configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

    file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR}) # Doxygen won't create this for us
    add_custom_command(OUTPUT ${DOXYGEN_INDEX_FILE}
                    DEPENDS ${APPLICATION_PUBLIC_HEADERS}
                    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
                    MAIN_DEPENDENCY ${DOXYFILE_OUT} ${DOXYFILE_IN}
                    COMMENT "Generating docs")

    add_custom_target(doxygen ALL DEPENDS ${DOXYGEN_INDEX_FILE})

    add_custom_target(copy_doxygen_documentation ALL
        COMMAND cmake -E copy_directory ${DOXYGEN_OUTPUT_DIR}/html/ ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_DOCDIR}
        DEPENDS doxygen)

    install(DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_DOCDIR}/ TYPE DOC)
endif()
