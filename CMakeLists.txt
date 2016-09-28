cmake_minimum_required(VERSION 3.0)
project(ExprLisp)

enable_testing()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lm -g -std=c11")

add_subdirectory(src)
