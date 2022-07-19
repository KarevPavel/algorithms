cmake_minimum_required(VERSION 3.17)
project(lists)
set(CMAKE_CXX_STANDARD 14)

add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME} INTERFACE sort)
target_include_directories(${PROJECT_NAME} INTERFACE include)