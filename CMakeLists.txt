cmake_minimum_required(VERSION 3.1)

project(OffsideDetection)

set(OpenCV_DIR /usr/local/lib/cmake/opencv4)
set(OpenCV_INCLUDE_DIRS /usr/local/include/opencv4)
set(OpenCV_LIBS /usr/local/bin)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Inc)

add_library(OffsideDetection_lib Inc/edgeDetection.h Src/edgeDetection.cpp)

set(SOURCES
    Src/edgeDetection.cpp
    Src/offside.cpp
    Src/ObjectDetection.cpp
)


add_executable(Offside_Detection ${SOURCES})

target_link_libraries(Offside_Detection ${OpenCV_LIBS})

