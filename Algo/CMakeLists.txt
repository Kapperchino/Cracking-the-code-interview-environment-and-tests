cmake_minimum_required(VERSION 2.6)
project(array)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(CMAKE_BUILD_TYPE Debug)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests algoTest.cpp algo.cpp )
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)