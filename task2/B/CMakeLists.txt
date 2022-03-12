cmake_minimum_required(VERSION 3.10)

project(cmake_add_lib)

set(SOURCE_LIB lib.cpp)

add_library(MyLib SHARED ${SOURCE_LIB})
