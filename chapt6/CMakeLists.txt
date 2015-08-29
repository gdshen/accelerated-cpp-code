cmake_minimum_required(VERSION 3.2)
project(chapt6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp grade.h grade.cpp students_info.cpp students_info.h median.h median.cpp)
add_executable(chapt6 ${SOURCE_FILES})