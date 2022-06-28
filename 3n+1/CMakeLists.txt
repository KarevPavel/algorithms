cmake_minimum_required(VERSION 3.17)
project(3n+1)
set(CMAKE_CXX_STANDARD 14)

#find_package(Boost REQUIRED COMPONENTS system)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC utils tabulate boost)