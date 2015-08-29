cmake_minimum_required(VERSION 3.3)
project(chapt10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(chapt10 ${SOURCE_FILES})