cmake_minimum_required(VERSION 3.3)
project(chapt9)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp student_info.cpp student_info.h student_grade_info.cpp student_grade_info.h)
add_executable(chapt9 ${SOURCE_FILES})