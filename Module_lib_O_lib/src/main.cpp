#include <iostream>
#include <dlfcn.h>
#include "solver_interface.hpp"

int main(){
    std::cout<<"Starting Simulation! HIIIIIII , yippi";
    std::cout<<"\n";
    std::cout<<"LOADING_EULER"<<std::endl;
    void* dl_reference = dlopen("./build/libeuler.so",RTLD_LAZY);
    if(!dl_reference){
        std::cerr<<"Failed to Plug In "<<std::endl;
        return 1;
    }
    SolverFunction e_solver = (SolverFunction)dlsym(dl_reference,"solver_equation");
    if(!e_solver){
        std::cerr<< "Failed to find function in  library" << dlerror()<<std::endl;
    }
    double approax_result = e_solver(10.0,0.1,10);
    std::cout<<"Euler Solver result : "<<approax_result<<std::endl;
    double exact_r = 10.22;
    double error = compute_error(exact_r , approax_result);
    std::cout<<"actual error = "<<error<<std::endl;
    dlclose(dl_reference);
    return 0;
}
