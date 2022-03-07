cmake_minimum_required(VERSION 3.17)
project(sort)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CUDA_STANDARD 14)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_COMPILER /opt/cuda/bin/nvcc)

include(CheckLanguage)
check_language(CUDA)
enable_language(CUDA)


include_directories(/opt/cuda/include)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC utils)
target_include_directories(${PROJECT_NAME} PRIVATE include)