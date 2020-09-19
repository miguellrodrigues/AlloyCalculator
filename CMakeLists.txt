cmake_minimum_required(VERSION 3.17)
project(AlloyCalculator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(AlloyCalculator main.cpp Alloy.cpp Alloy.h)