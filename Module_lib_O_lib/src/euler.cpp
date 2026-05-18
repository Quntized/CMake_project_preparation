#include "solver_interface.hpp"
#include <iostream>
extern "C" double solver_equation(double start_val, double step_size, int steps){
    double initial_val = start_val;
    double dt = step_size;
    double next_val = 0.0;
    double current_val = 0.0;
    for(int i = 0; i< steps; i++){
        current_val = i*dt;
        next_val = current_val + initial_val;
        std::cout<<"steps : "<<i<<" . Value: "<<next_val<<std::endl;
    }
    return next_val;
}