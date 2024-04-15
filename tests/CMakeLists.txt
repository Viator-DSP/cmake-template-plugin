set(CMAKE_CXX_STANDARD 17)

if(BUILD_TESTING)
    add_executable(my_tests clipper-test.cpp
    clipper-test.h
            clipper-test.h)
    target_link_libraries(my_tests PRIVATE GTest::gtest_main)

    include(GoogleTest)

    # Finds all the Google tests associated with the executable
    gtest_discover_tests(my_tests)
endif()
