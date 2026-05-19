#include "solver/nonlinear_solver.hpp"
#include "internal_utils.hpp"
namespace solver{
    NonLinearSolver::NonLinearSolver(int max_iter) : max_iter_(max_iter) {}
    std::vector<double> NonLinearSolver::solve(const std::vector<double>& input){
        auto result = input;
        for(int i =0; i<max_iter_; i++){
            result = internal::iterate(result);
        }
        return result;
    }
}