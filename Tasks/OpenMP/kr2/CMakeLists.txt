cmake_minimum_required(VERSION 3.15)
project(kr2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

add_executable(kr2 main.cpp)