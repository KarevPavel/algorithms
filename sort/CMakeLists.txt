cmake_minimum_required(VERSION 3.17)
project(sort LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)

find_package(OpenCL REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_auto_type)

target_link_libraries(${PROJECT_NAME} PUBLIC utils OpenCL::OpenCL)
target_include_directories(${PROJECT_NAME} PRIVATE include)