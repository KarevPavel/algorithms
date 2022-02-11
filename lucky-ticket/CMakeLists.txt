cmake_minimum_required(VERSION 3.17)
project(lucky_ticket)

################################
#	MAIN PROJECT
################################
set(CMAKE_CXX_STANDARD 14)
add_executable(lucky_ticket
			   main.cpp
			   src/table_generator.cpp)
target_include_directories(lucky_ticket PRIVATE include)
################################
#	TESTS
################################
add_subdirectory(lib/googletest)
include(GoogleTest)
include_directories(${gtest_SOURCE_DIR}/include
					${gtest_SOURCE_DIR})

#### NOT WORKING YET!
#include(GenerateTestCases.cmake)
#add_generated_stuff(${CMAKE_SOURCE_DIR} lucky_test ${CMAKE_SOURCE_DIR}/resources ${CMAKE_BINARY_DIR})

add_executable(runUnitTests src/table_generator_test.cc src/table_generator.cpp)
target_include_directories(runUnitTests PUBLIC include)
target_link_libraries(runUnitTests gtest gtest_main)
add_test(runUnitTests runUnitTests)
enable_testing()