cmake_minimum_required(VERSION 3.10)
project(ExecutableDemo)
add_library(formatter src/formatter.cpp)
add_executable(mytool src/mytool.cpp)
target_link_libraries(mytool formatter)

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/output.txt
    COMMAND mytool ${CMAKE_CURRENT_BINARY_DIR}/output.txt
    COMMENT "Running my tool generate our text file"
)

add_custom_target(GenerateMyFile ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/output.txt
)
