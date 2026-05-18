#ifndef SOLVER_INTERFACE_HPP
#define SOLVER_INTERFACE_HPP
double compute_error(double exact, double approax);
extern "C" {
    typedef double (*SolverFunction)(double start_val, double step_size, int steps);
}
#endif
