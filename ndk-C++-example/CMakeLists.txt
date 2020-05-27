cmake_minimum_required(VERSION 3.5)
project(example)

set(CMAKE_CXX_STANDARD 11)
add_library(ndk SHARED cout.cpp)

add_executable(ndk_example main.cpp)
target_link_libraries(ndk_example ndk)
