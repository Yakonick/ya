cmake_minimum_required(VERSION 3.15)
project(shad)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

add_executable(shad main.cpp)