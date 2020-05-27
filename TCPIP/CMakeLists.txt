cmake_minimum_required(VERSION 2.8)
project(TCPIP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
add_executable(op_client op_client.cpp)
add_executable(op_server op_server.cpp)
add_executable(uecho_server uecho_server.cpp)
add_executable(uecho_con_client uecho_con_client.cpp)
add_executable(gethostbyname gethostbyname.cpp)