cmake_minimum_required(VERSION 3.14)
include_directories(.)
add_executable(example2_1 example2_1.cpp)
target_link_libraries(example2_1 pthread)

add_executable(example2_2 example2_2.cpp)
target_link_libraries(example2_2 pthread)