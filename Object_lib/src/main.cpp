#include <iostream>
#include "rk4_solver.hpp"

double my_equation(double t, double y){
    return t - y;
}
int main(){
    std::cout<<"-----Runge Kutta Solver-----"<<std::endl;
    double t = 0.0;
    double y = 1.0;
    double h = 0.01;
    std::cout<<" Initial Value : y( "<<t<<" )"<<" = "<<y<<std::endl;
    y = solve_rk4_step(my_equation,t,y,h);
    t += h;
    std::cout<<"After 1 step: y( "<<t<<" ) = "<<y<<std::endl;
    return 0;
}