# CMakeLists.txt

cmake_minimum_required(VERSION 3.0)

project(Forward_List)

# Include directories
include_directories(headers)

# Globbing the source files
file(GLOB SOURCES "src/*.cpp")

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

