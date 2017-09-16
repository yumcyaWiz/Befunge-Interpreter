#include <iostream>
#include "stack.h"
#include "source.h"
#include "interpreter.h"


int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout << "Invalid parameters" << std::endl;
        exit(1);
    }
    std::string filename(argv[1]);
    Source src(filename);
    Interpreter intp(src);
    intp.run();
}

