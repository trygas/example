cmake_minimum_required(VERSION 3.14)
include_directories(.)
add_executable(example2_1 example2_1.cpp)
target_link_libraries(example2_1 pthread)

add_executable(example2_2 example2_2.cpp)
target_link_libraries(example2_2 pthread)

add_executable(scoped_thread scoped_thread.cpp)
target_link_libraries(scoped_thread pthread)

add_executable(thread_sum thread_sum.cpp)
target_link_libraries(thread_sum pthread)

add_executable(mutex_example mutex_example.cpp)
target_link_libraries(mutex_example pthread)

add_executable(thread_safe_stack thread_safe_stack.cpp)
target_link_libraries(thread_safe_stack pthread)

add_executable(lock_two_mutex lock_two_mutex.cpp)
target_link_libraries(lock_two_mutex pthread)

add_executable(hierarchical_mutex hierarchical_mutex.cpp)
target_link_libraries(hierarchical_mutex pthread)

add_executable(thread_safe_queue thread_safe_queue.cpp)
target_link_libraries(thread_safe_queue pthread)

add_executable(future future.cpp)
target_link_libraries(future pthread)