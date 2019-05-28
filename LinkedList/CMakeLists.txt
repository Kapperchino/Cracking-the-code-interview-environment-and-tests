cmake_minimum_required(VERSION 2.6)
project(linkedList)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(CMAKE_BUILD_TYPE Debug)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests linkListTest.cpp linkList.tcc)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)