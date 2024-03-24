cmake_minimum_required(VERSION 3.0)
project(MyStack)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(headers)
add_executable(main src/main.cpp)

