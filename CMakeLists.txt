cmake_minimum_required(VERSION 3.0.0)
project(Vector)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

find_package(GTest CONFIG REQUIRED)

add_library(vector_lib INTERFACE Vector.h) # interface for header only library
add_executable(${CMAKE_PROJECT_NAME} main.cpp Vector.h)

#add_subdirectory(tests/googletest/googletest)

#target_link_libraries(main PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

add_executable(vector_test tests/vector_testing.cpp tests/main.cpp)
target_link_libraries(vector_test PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main) 
add_test(vector_test vector_test)

#include(GoogleTest) 
#gtest_discover_tests(vector_test)


