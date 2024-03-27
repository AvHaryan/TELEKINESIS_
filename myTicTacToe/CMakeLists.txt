cmake_minimum_required(VERSION 3.0)
project(TicTacToe)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(headers)

# Add source files
set(SOURCES
    src/board.cpp
    src/player.cpp
    src/main.cpp
)

# Add executable
add_executable(TicTacToe ${SOURCES})

