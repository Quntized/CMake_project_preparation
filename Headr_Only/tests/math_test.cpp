#include <iostream>
#include "math.hpp"
int main() {
    if(add_numbers(2.0, 2.0)!= 4){
        std::cerr<<"Test Failed! 2 + 2 did not equal 4! \n";
    }
    std::cout<<"Test passed! "<<std::endl;
    return 0;
}