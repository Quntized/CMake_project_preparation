#pragma once
#include "solver.hpp"
namespace solver{
    class NonLinearSolver : public Solver{
        public:
            NonLinearSolver(int max_iter = 100);
            std::vector<double> solve(const std::vector<double>& input) override;
        private:
            double max_iter_;
    };
}