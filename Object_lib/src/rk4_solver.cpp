#include "rk4_solver.hpp"
double solve_rk4_step(DerivativeFunction f, double t, double y, double h){
    double k1 = h * f(t,y);
    double k2 = h * f(t + h/2.0 , y+ k1/2.0);
    double k3 = h * f(t + h/2.0, y + k2/2.0);
    double k4 = h * f(t + h, y+k3);
    return y + (1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
}