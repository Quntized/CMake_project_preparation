#include <iostream>
extern int calculate_physics(double temp, double density);
int main(){
    std::cout<<"SOme Physics is going on ------------------"<<std::endl;
    int pres= calculate_physics(1000,3000);
    std::cout<<"after simulatiuon the result is = "<<pres<<std::endl;
    return 0;
}