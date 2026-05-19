cmake_minimum_required(VERSION 3.10)
project(XYZ)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3") #global flags , every c++ target gets this.
add_executable(exe src/main.cpp src/legacy.c)
target_compile_options(exe PRIVATE -Wall $<$<COMPILE_LANGUAGE:CXX>:-Wextra>)
#message("${CMAKE_CXX_COMPILE_FEATURES}")
add_library(lib STATIC src/math.cpp)
target_compile_options(lib INTERFACE -Werror)
target_link_libraries(exe PRIVATE lib)
