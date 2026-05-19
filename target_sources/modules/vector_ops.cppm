export module vector_ops;
import <vector>;
export namespace vec{
    double dot(const std::vector<double>& a, const std::vector<double>& b){
        double sum = 0.0;
        for(size_t i = 0; i<a.size(); i++){
            sum = a[i] * b[i];
        }
        return sum;
    }
}