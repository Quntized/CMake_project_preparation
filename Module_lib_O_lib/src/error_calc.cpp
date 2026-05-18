#include "solver_interface.hpp"
#include <cmath>
double compute_error(double exact, double approax){
    return std::abs(approax - exact) ;
}