cmake_minimum_required(VERSION 3.17)
project(tree)
set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC utils tabulate)
target_include_directories(${PROJECT_NAME} PRIVATE include)

#add_library(${PROJECT_NAME} INTERFACE)
#target_include_directories(${PROJECT_NAME} INTERFACE include)