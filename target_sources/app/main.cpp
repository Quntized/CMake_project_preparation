#include "solver/linear_solver.hpp"
#include <iostream>
int main(){
    solver::LinearSolver ls(1e-08);
    auto result = ls.solve({1.0,2.0,3.0});
    std::cout<<"Solved First Value: "<<result[0]<<std::endl;
    return 0;
}