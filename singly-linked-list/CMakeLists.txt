cmake_minimum_required(VERSION 3.1)

project(singly-linked-list)
set(CMAKE_VERBOSE_MAKEFILE true)

set(CMAKE_SOURCE_DIR src/)

add_executable("c.out" "${CMAKE_SOURCE_DIR}main.c")
