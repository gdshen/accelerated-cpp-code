cmake_minimum_required(VERSION 3.2)
project(chapt7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(chapt7 ${SOURCE_FILES})