#include "solver/linear_solver.hpp"
#include "internal_utils.hpp"
#include <cmath>
namespace solver{
    LinearSolver::LinearSolver(double tolerance) : tolerance_(tolerance) {}
    std::vector<double> LinearSolver::solve(const std::vector<double>& input){
        return internal::normalize(input, tolerance_);
    }
}