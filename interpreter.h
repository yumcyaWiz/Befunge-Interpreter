#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <random>
#include "stack.h"
#include "source_stream.h"


std::random_device rand_dev;
std::mt19937 mt(rand_dev());
std::uniform_int_distribution<> rand_int(1, 4);
inline int rand() {
    return rand_int(mt);
}


class Interpreter {
    private:
        Stack<int> stack;
        Source src;
        int row;
        int column;
        int direction;
        bool end;
        bool skip;
    public:
        Interpreter(std::string source_code) {
            src.setSource(source_code);
            row = 1;
            column = 1;
            end = false;
            skip = false;
        };
        void run() {
            while(!end) {
                char c = src.getChar(row, column);
                if(c == '<') {
                    direction = 1;
                }
                else if(c == '>') {
                    direction = 3;
                }
                else if(c == '^') {
                    direction = 2;
                }
                else if(c == "v") {
                    direction = 4;
                }
                else if(c == "_") {
                    if(stack.pop() == 0) {
                        direction = 3;
                    }
                    else {
                        direction = 1;
                    }
                }
                else if(c == '|') {
                    if(stack.pop() == 0) {
                        direction = 4;
                    }
                    else {
                        direction = 2;
                    }
                }
                else if(c == '?') {
                    direction = rand();
                }
                else if(c == ' ') {
                }
                else if(c == '#') {
                    skip = true;
                }
                else if(c == '@') {
                    end = true;
                }
                else if(c == '0') {
                    stack.push(0);
                }
                else if(c == '1') {
                    stack.push(1);
                }
                else if(c == '2') {
                    stack.push(2);
                }
                else if(c == '3') {
                    stack.push(3);
                }
                else if(c == '4') {
                    stack.push(4);
                }
                else if(c == '5') {
                    stack.push(5);
                }
                else if(c == '6') {
                    stack.push(6);
                }
                else if(c == '7') {
                    stack.push(7);
                }
            }
        };
};
#endif
