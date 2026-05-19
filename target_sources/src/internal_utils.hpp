#pragma once
#include <vector>
namespace solver::internal{
    std::vector<double> normalize(const std::vector<double>& v, double tol);
    std::vector<double> iterate(const std::vector<double>& v);
}