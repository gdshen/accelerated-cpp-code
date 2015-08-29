cmake_minimum_required(VERSION 3.2)
project(chapt5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp grade.cpp grade.h median.cpp median.h students_info.cpp students_info.h)
add_executable(chapt5 ${SOURCE_FILES})