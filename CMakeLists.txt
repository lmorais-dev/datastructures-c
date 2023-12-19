cmake_minimum_required(VERSION 3.27)

project(datastructures_c C)

set(CMAKE_C_STANDARD 23)

add_subdirectory(lib)
add_subdirectory(demos)

add_dependencies(dsc_demos dsclib_static)