cmake_minimum_required(VERSION 3.16)
project(taskboard)

set(CMAKE_CXX_STANDARD 17)

if (MSVC)
    add_compile_options(/utf-8)
endif()

add_executable(taskboard main.cpp)
