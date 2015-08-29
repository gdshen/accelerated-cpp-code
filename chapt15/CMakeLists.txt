cmake_minimum_required(VERSION 3.3)
project(chapt15)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(chapt15 ${SOURCE_FILES})