#pragma once
#include <vector>
namespace solver {
    class Solver{
        public:
            Solver();
            virtual ~Solver() = default;
            virtual std::vector<double> solve(const std::vector<double>& input) = 0;
    };
}