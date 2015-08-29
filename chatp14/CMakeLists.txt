cmake_minimum_required(VERSION 3.3)
project(chatp14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Handle.h Ref_handle.h Ptr.cpp Ptr.h)
add_executable(chatp14 ${SOURCE_FILES})