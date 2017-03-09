cmake_minimum_required(VERSION 3.6)
project(Verctor)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp vector.h vector.cpp)
add_executable(Verctor ${SOURCE_FILES})