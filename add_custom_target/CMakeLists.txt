cmake_minimum_required(VERSION 3.10)
project(add_custom_targett)
add_executable(exe src/main.cpp)
add_custom_target(tar_exe
    COMMAND exe
    DEPENDS exe
    COMMENT "EXECUTING executable "
    VERBATIM
)
add_custom_target(exe_run ALL
    ${CMAKE_COMMAND} -E echo "Generating XYZ.."
    COMMENT "RUNNING XYZ generator target"
    VERBATIM
)