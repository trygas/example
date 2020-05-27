cmake_minimum_required(VERSION 2.8)
project(some_project)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_BUILD_TYPE Debug)
set(OpenCV_DIR /opt/opencv3.3/share/OpenCV/OpenCVConfig.cmake)

find_package(OpenCV)
find_package(Eigen3)
find_package(GSLAM)
find_package(Ceres)
find_package(SDL2 REQUIRED)

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")

find_path(AVCODEC_INCLUDE_DIR libavcodec/avcodec.h)
find_library(AVCODEC_LIBRARY avcodec)

find_path(AVFORMAT_INCLUDE_DIR libavformat/avformat.h)
find_library(AVFORMAT_LIBRARY avformat)

find_path(AVUTIL_INCLUDE_DIR libavutil/avutil.h)
find_library(AVUTIL_LIBRARY avutil)
set(CMAKE_CXX_FLAGS "-D__STDC_CONSTANT_MACROS")
find_path(AVDEVICE_INCLUDE_DIR libavdevice/avdevice.h)
find_library(AVDEVICE_LIBRARY avdevice)

include_directories(
        .
        hbst
        Read_EXIF
        /usr/local/ffmpeg/include
        /usr/local/include/liveMedia
#        /usr/local/include/x86_64-linux-gnu
#        ./rtsp/ffmpeg3.3.9
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/rb_tree
        ${PROJECT_SOURCE_DIR}/parse_file
        ${OpenCV_DIRS}
        ${Eigen3_DIRS}
        ${Ceres_DIRS}
        ${SDL2_INCLUDE_DIRS}
)

link_directories(
        /usr/local/ffmpeg/lib
#        /home/liu/my_progs/example/some_example/rtsp/ffmpeg3.3.9/lib
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
target_link_libraries(rotation_transportion ${OpenCV_LIBS} ${Eigen3_LIBS} ${Ceres_LIBS})

add_executable(game_king game_king/game_king.cpp)
add_executable(find_string find_string/find_string.cpp)

<<<<<<< HEAD
add_executable(game_king game_king/game_king.cpp)
add_executable(find_string find_string/find_string.cpp)
=======
add_executable(json_example json_example/json_example.cpp)

add_executable(Read_EXIF Read_EXIF/Read_EXIF.cpp)
add_library(exif SHARED Read_EXIF/TinyEXIF.cpp)
target_link_libraries(Read_EXIF exif)
<<<<<<< HEAD
<<<<<<< HEAD


add_executable(GSLAM_Sub_Pub GSLAM_Sub_Pub/GSLAM_Sub_Pub.cpp)
target_link_libraries(GSLAM_Sub_Pub pthread)

add_executable(self_calibration self_calibration/self_calibration.cpp)
target_link_libraries(self_calibration ${OpenCV_LIBS})

add_executable(CreateJSON CreateJSON/CreateJSON.cpp)
add_executable(sift sift/sift.cpp)
add_executable(youzhiyingyong youzhiyingyong/youzhiyingyong.cpp)

target_link_libraries(sift ${OpenCV_LIBS})


=======
>>>>>>> 000df2967160e72f219ff2bd976e1763f16614f0
>>>>>>> d9246b7b993b6f430d1bc64bec49ebdadc41b88b
=======
>>>>>>> 000df2967160e72f219ff2bd976e1763f16614f0
>>>>>>> d9246b7b993b6f430d1bc64bec49ebdadc41b88b
