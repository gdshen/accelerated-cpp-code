cmake_minimum_required(VERSION 3.3)
project(chap11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp vec.h vec.cpp)
add_executable(chap11 ${SOURCE_FILES})