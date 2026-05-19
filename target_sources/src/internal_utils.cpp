#include "internal_utils.hpp"
#include <cmath>

namespace solver::internal {
    std::vector<double> normalize(const std::vector<double>& v, double tol){
        std::vector<double> result = v;
        for (auto& x: result){
            if (std::abs(x) < tol){
                x = 0.0;
            }  
        }
        return result;
    }
    std::vector<double> iterate(std::vector<double>& v){
        std::vector<double> result = v;
        for(auto& x: result){
            x = x - 0.01*x;
        }
        return result;
    }
}