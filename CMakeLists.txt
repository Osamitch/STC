cmake_minimum_required(VERSION 3.10)


project(floatfinder)


add_library(floatfinder floatfinder.c)

add_subdirectory(tests)

