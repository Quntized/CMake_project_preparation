#include <iostream>
#include <fstream>
#include "formatter.h"

int main(int argc, char* argv[]){
    if (argc<2){
        std::cerr<<"Usage my tool <...> \n";
        return 1;
    }
    std::string finalMessage = formatMessage("Generated CMake Command! ");
    std::ofstream outfile(argv[1]);
    outfile << finalMessage;
    outfile.close();
    return 0;
}