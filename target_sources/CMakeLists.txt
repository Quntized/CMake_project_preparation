cmake_minimum_required(VERSION 3.28)
project(sol_proj VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
cmake_policy(SET CMP0076 NEW)
add_library(shitty_numeri)
target_sources(shitty_numeri 
    PRIVATE 
        src/solver.cpp 
        src/linear_solver.cpp 
        src/nonlinear_solver.cpp 
        src/internal_utils.cpp)
target_sources(shitty_numeri 
    PRIVATE 
        src/internal_utils.hpp)
target_sources(shitty_numeri 
    PRIVATE 
        "$<$<CONFIG:Debug>:${CMAKE_CURRENT_SOURCE_DIR}/src/dbgsrc.cpp>")
target_sources(shitty_numeri 
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
        FILES 
            include/solver/solver.hpp
            include/solver/linear_solver.hpp
            include/solver/nonlinear_solver.hpp
)
target_sources(shitty_numeri 
    INTERFACE 
        FILE_SET solver_public_api
        TYPE HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/interface
        FILES
            interface/solver_api.hpp
)
target_sources(shitty_numeri
    PUBLIC
        FILE_SET CXX_MODULES
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/modules
        FILES 
            modules/matrix_ops.cppm
            modules/vector_ops.cppm
)
target_sources(shitty_numeri
    PUBLIC 
        FILE_SET HEADERS
        FILES 
            include/solver/solver.hpp      
)
add_custom_target(generatedox
    COMMAND ${CMAKE_COMMAND} -E echo "Generating documentation... "
)
target_sources(generatedox
    PRIVATE 
        README.md
        docs/api.md
)
add_library(ExternalMath INTERFACE IMPORTED)
target_sources(ExternalMath 
    INTERFACE
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/interface
        FILES 
            interface/solver_api.hpp
)
add_executable(solver_app app/main.cpp)
target_link_libraries(solver_app PRIVATE shitty_numeri)
include(GNUInstallDirs)
install(TARGETS shitty_numeri
    EXPORT NumSolverTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR}
    FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILE_SET solver_public_api DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/solver_api
    FILE_SET CXX_MODULES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/modules
)
install(EXPORT NumSolverTargets
    FILE NumSolverTargets.cmake
    NAMESPACE NumSolver::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/NumSolver
)
get_target_property(_sources shitty_numeri SOURCES)
get_target_property(_iface_sources shitty_numeri INTERFACE_SOURCES)
get_target_property(_header_set shitty_numeri HEADER_SETS)
get_target_property(_iface_header_set shitty_numeri INTERFACE_HEADER_SETS)
get_target_property(_cxx_module_sets shitty_numeri CXX_MODULE_SETS)
get_target_property(_inc_dir shitty_numeri INCLUDE_DIRECTORIES)
get_target_property(_iface_dir shitty_numeri INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "SOURCES   :${_sources}")
message(STATUS "INTERFACE_SOURCES : ${_iface_sources}")
message(STATUS "HEADER SETS    : ${_header_set}")
message(STATUS "INTERFACE_HEADER_SETS   :  ${_iface_header_set}")
message(STATUS "CXX_MODULE_SET   : ${_cxx_module_sets}")
message(STATUS "INCLUDE_DIRECTORIES :  ${_inc_dir}")
message(STATUS "INTERFACE INCLUDE DIRECTORIES   :  ${_iface_dir}")