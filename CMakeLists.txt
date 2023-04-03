cmake_minimum_required(VERSION 3.22)

project(ex2)

set(CMAKE_CXX_STANDARD 23)

add_executable (${CMAKE_PROJECT_NAME})

add_subdirectory (include)
add_subdirectory (src)



