cmake_minimum_required(VERSION 3.15)
project(ctest C)

set(CMAKE_C_STANDARD 99)

add_executable(ctest main.c p1.c p2.c p3.c p4.c t1.c)