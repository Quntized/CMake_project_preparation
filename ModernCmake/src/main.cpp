#include "math_lib.hpp"
#include <iostream>
int main(){
    std::cout<<"APp StArTiNg: "<<std::endl;
    auto result = divide(5,2);
    if(result){
        std::cout<< " Result: " << *result<<std::endl;
    }
    return 0;
}