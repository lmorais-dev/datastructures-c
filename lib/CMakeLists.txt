cmake_minimum_required(VERSION 3.27)

project(datastructures_c C)

set(CMAKE_C_STANDARD 23)

set(SOURCES src/lib.c src/list/array_list.c)

add_library(dsclib_static STATIC ${SOURCES})
target_include_directories(dsclib_static PUBLIC ./include)
set_target_properties(dsclib_static PROPERTIES OUTPUT_NAME "dsclib")


add_library(dsclib_shared SHARED ${SOURCES})
target_include_directories(dsclib_shared PUBLIC ./include)
set_target_properties(dsclib_shared PROPERTIES OUTPUT_NAME "dsclib")