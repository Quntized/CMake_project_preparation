#include <iostream>
#include <fstream>
#include <string>
#include "string_utils.h"

int main(int argc , char* argv[]){
    if (argc< 3){
        std::cerr<<"USAGE: generator <input_file> <output_file>\n";
    }
    std::ifstream infile(argv[1]);
    std::string line;
    std::getline(infile, line);
    infile.close();
    std::string res = addPrefix(line);
    std::ofstream outfile(argv[2]);
    outfile << res;
    outfile.close();

    return 0;
}