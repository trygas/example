cmake_minimum_required(VERSION 2.8)
project(some_project)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV)
find_package(Eigen3)
find_package(GSLAM)

include_directories(
        .
        hbst
        Read_EXIF
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/rb_tree
        ${PROJECT_SOURCE_DIR}/parse_file
        ${OpenCV_DIRS}
        ${Eigen3_DIRS}
)

add_executable(bit_operation bit_operation/bit_operation.cpp)
add_executable(random_number random_number/random_number.cpp)
add_executable(sse_sse2 sse_sse2/sse_sse2.cpp)
add_executable(parse_file parse_file/parse_file.cpp)
target_link_libraries(parse_file ${OpenCV_LIBS})

add_executable(std_function std_function/std_function.cpp)
add_executable(raii RAII/raii.cpp)
add_executable(nocopyable_class nocopyable_class/nocopeable_class.cpp)
add_executable(function_bind function_bind/function_bind.cpp)
add_executable(share_ptr share_ptr/share_ptr.cpp)
add_executable(xx_cast xx_cast/xx_cast.cpp)
add_executable(thread thread/thread.cpp)
target_link_libraries(thread pthread)

add_executable(bilinear_interpolation bilinear_interpolation/bilinear_interpolation.cpp)
target_link_libraries(bilinear_interpolation ${OpenCV_LIBS})

add_executable(five_fundamental five_fundamental/five_fundamental.cpp)
target_link_libraries(five_fundamental ${OpenCV_LIBS})

add_executable(rotation_transportion rotation_transportion/rotation_transportion.cpp)
target_link_libraries(rotation_transportion ${OpenCV_LIBS} ${Eigen3_LIBS})

add_executable(json_example json_example/json_example.cpp)

add_executable(Read_EXIF Read_EXIF/Read_EXIF.cpp)
add_library(exif SHARED Read_EXIF/TinyEXIF.cpp)
target_link_libraries(Read_EXIF exif)
