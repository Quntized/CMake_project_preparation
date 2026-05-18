#include "math_lib.hpp"
#ifdef BUILDING_MATH_LIB
#include <iostream>
#endif

std::optional<int> divide(double a, double b){
    #ifdef BUILDING_MATH_LIB
        std::cout<<"Internal_library log performing math ..."<<std::endl;
    #endif
    if (b==0){
        return std::nullopt;
    }
    return a / b;

}