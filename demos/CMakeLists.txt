cmake_minimum_required(VERSION 3.27)

project(datastructures_c C)

set(CMAKE_C_STANDARD 23)

add_executable(dsc_demos src/main.c)
target_link_libraries(dsc_demos dsclib_static)