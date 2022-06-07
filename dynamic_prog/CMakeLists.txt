cmake_minimum_required(VERSION 3.17)
project(dynamic_prog)
set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC utils)
target_include_directories(${PROJECT_NAME} PRIVATE include)