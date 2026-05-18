cmake_minimum_required(VERSION 3.10)
project(Random)
add_library(math_lib)
target_sources(math_lib PRIVATE src/math_lib.cpp)
target_include_directories(math_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_definitions(math_lib
    PRIVATE BUILDING_MATH_LIB
    INTERFACE USING_MATH_LIB
)
target_compile_features(math_lib PUBLIC cxx_std_17)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(math_lib PRIVATE -Wall -Wextra)
endif()

add_executable(ex src/main.cpp)
target_link_libraries(ex PRIVATE math_lib)