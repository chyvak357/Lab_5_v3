cmake_minimum_required(VERSION 3.9)
project(lab1_v5_encod)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab1_v5_encod main.cpp
        menu.cpp
        menu.h
        cl_kind.cpp
        cl_kind.h
        cl_book.h
        cl_book.cpp)