cmake_minimum_required(VERSION 3.15)
project(1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

add_executable(1 main.cpp)