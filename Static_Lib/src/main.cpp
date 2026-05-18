#include <iostream>
#include "math_tools.hpp"
#include "volume.hpp"

int main(){
    std::cout<<"Starting the solver: "<<std::endl;
    int area= calculateArea(4,10);
    std::cout<<" The result is: "<<area<<std::endl;
    int volume = calculateVolume(2,3,4);
    std::cout<<"Your volume is = "<<volume<<std::endl;
    return 0;

}
