cmake_minimum_required(VERSION 3.2)
project(chapt4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(chapt4 ${SOURCE_FILES} median.h median.cpp students_info.h students_info.cpp grade.h grade.cpp)