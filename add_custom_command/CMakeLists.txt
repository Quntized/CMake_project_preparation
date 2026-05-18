cmake_minimum_required(VERSION 3.10)
project(PracticeMe)
add_library(stru src/string_utils.cpp)
add_executable(generator src/generator.cpp)
target_link_libraries(generator stru)
add_custom_command(
    TARGET generator POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "============================================"
    COMMAND ${CMAKE_COMMAND} -E echo "      generator compiled successfully       "
    COMMAND ${CMAKE_COMMAND} -E echo "============================================"
    VERBATIM
)
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/final_output.txt
    COMMAND generator
            ${CMAKE_CURRENT_SOURCE_DIR}/data/raw.txt
            ${CMAKE_CURRENT_BINARY_DIR}/final_output.txt
    DEPENDS generator ${CMAKE_CURRENT_SOURCE_DIR}/data/raw.txt
    COMMENT "Running generator to process the raw data"
    VERBATIM
)
add_custom_target(ProcessData ALL 
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/final_output.txt    
)
