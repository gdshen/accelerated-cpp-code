cmake_minimum_required(VERSION 3.3)
project(chapt13)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Core.cpp Core.h Grad.cpp Grad.h Students_info.cpp Students_info.h)
add_executable(chapt13 ${SOURCE_FILES})