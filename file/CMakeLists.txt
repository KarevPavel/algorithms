cmake_minimum_required(VERSION 3.17)
project(file)
set(CMAKE_CXX_STANDARD 14)

set(FILE_PATH_CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/generated_numbers.txt)
add_executable(${PROJECT_NAME} main.cpp)
configure_file(include/file_path_config.hpp.in ${CMAKE_BINARY_DIR}/generated/file_path_config.hpp)
include_directories(${CMAKE_BINARY_DIR}/generated/)

target_link_libraries(${PROJECT_NAME} PUBLIC utils)
target_include_directories(${PROJECT_NAME} PRIVATE include)