cmake_minimum_required(VERSION 3.22)

project(ex2)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})


include_directories (include)
include_directories (src)
