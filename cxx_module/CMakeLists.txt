cmake_minimum_required(VERSION 3.28)
project(export_module CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(math_lib STATIC)
target_sources(math_lib
    PUBLIC
        FILE_SET CXX_MODULES
        TYPE CXX_MODULES
        FILES
            src/math_core.cppm
)
add_executable(random src/main.cpp)
target_link_libraries(random PRIVATE math_lib)