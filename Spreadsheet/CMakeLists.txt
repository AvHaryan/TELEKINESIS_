cmake_minimum_required(VERSION 3.5)

project(your_project_name)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(headers)

set(SOURCES
    src/cell.cpp
    src/main.cpp
    src/spreadsheet.cpp
)

add_executable(your_executable_name ${SOURCES})

