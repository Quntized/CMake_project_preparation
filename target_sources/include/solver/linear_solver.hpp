#pragma once
#include "solver.hpp"
namespace solver{
    class LinearSolver : public Solver{
        public:
            LinearSolver(double tolerance = 1e-06);
            std::vector<double> solve(const std::vector<double>& input) override;
        private:
            double tolerance_;
    };
}