#include <iostream>
#include "stack.h"
#include "source.h"
#include "interpreter.h"


int main(int argc, char** argv) {
    if(argc != 3) {
        std::cout << "Invalid parameters" << std::endl;
        exit(1);
    }

    std::string filename(argv[1]);
    std::string runSpeed_s(argv[2]);
    int runSpeed = std::stoi(runSpeed_s);

    Source src(filename);
    Interpreter intp(src, runSpeed);
    intp.run();
}

