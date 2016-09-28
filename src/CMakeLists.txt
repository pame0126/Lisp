cmake_minimum_required(VERSION 3.0)
project(ExprLisp)

add_executable(lispapp main.c)

install(TARGETS lispapp DESTINATION bin)

