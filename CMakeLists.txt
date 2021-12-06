cmake_minimum_required(VERSION 3.0.0)
project(Vector)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

include_directories(src)

# using vcpkg
# https://vcpkg.readthedocs.io/en/latest/users/integration/#integrate-command
find_package(GTest CONFIG REQUIRED)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

set(VECTOR_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Vector.h
)

# Vector header
add_library(vector_lib INTERFACE ${VECTOR_SRC}) # interface for header only library

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp src/Vector.h)

# Testing
add_executable(vector_test tests/vector_testing.cpp)
target_link_libraries(vector_test PRIVATE vector_lib GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main) 
add_test(vector_test vector_test)