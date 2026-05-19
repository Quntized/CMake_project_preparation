#include <iostream>
extern "C" void run_legacy_code();
extern int calculate_sum(int a, int b);
int main(){
    std::cout<<"Starting the simulation........"<<std::endl;
    run_legacy_code();
    int res = calculate_sum(2,4);
    std::cout<<"The result: "<<res<<std::endl;
    return 0;
}