cmake_minimum_required(VERSION 3.10)
project(StuSystem)

set(CMAKE_CXX_STANDARD 11)

add_executable(StuSystem main.cpp Student.cpp Student.h Function.cpp Function.h)