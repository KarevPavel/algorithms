cmake_minimum_required(VERSION 3.17)
project(sort_test)
set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC utils sort tabulate)