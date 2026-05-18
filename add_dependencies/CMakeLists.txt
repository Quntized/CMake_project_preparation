cmake_minimum_required(VERSION 3.10)
project(XYZProject)
add_custom_target(target_stuff
    COMMAND ${CMAKE_COMMAND} -E echo "Building some stuff ..."
    COMMAND ${CMAKE_COMMAND} -E touch txt_creation_at_compiling_with_cmake.txt
    COMMENT "Starting some stuff ..."
    VERBATIM
)
add_executable(code src/main.cpp)
add_dependencies(code target_stuff)