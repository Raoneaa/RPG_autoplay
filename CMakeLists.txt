cmake_minimum_required(VERSION 3.28)
project(Project3 C)

set(CMAKE_C_STANDARD 99)

add_executable(Project3 main.c
        champion.h
        champion.c)
