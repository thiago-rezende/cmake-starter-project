set(APPLICATION_TESTS_HEADERS
    ""
)

set(APPLICATION_TESTS_SOURCES
    "never_fails.cpp"
)

set(APPLICATION_TESTS_MAIN
    "main.cpp"
)

add_executable(application_tests
    ${APPLICATION_TESTS_MAIN}
    ${APPLICATION_TESTS_SOURCES}
    ${APPLICATION_TESTS_HEADERS}
)

add_test(NAME application_tests COMMAND application_tests)

target_link_libraries(application_tests PUBLIC gtest gmock)
