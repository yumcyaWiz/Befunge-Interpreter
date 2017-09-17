#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <random>
#include <cstdlib>
#include <thread>
#include "stack.h"
#include "source.h"


std::random_device rand_dev;
std::mt19937 mt(rand_dev());
std::uniform_int_distribution<> rand_int(1, 4);
inline int rand() {
    return rand_int(mt);
}


class Interpreter {
    private:
        Stack stack = Stack(100);
        Source src;
        int row;
        int column;
        int direction;
        bool end;
        bool skip;
        bool ascii;
        std::string output;
        int runSpeed;
        std::chrono::milliseconds duration;
    public:
        Interpreter(const Source& _src, int _runSpeed) {
            src = _src;
            row = 0;
            column = 0;
            direction = 3;
            end = false;
            skip = false;
            ascii = false;
            runSpeed = _runSpeed;
            duration = std::chrono::milliseconds(runSpeed);
        };
        void sleep() {
            std::this_thread::sleep_for(duration);
        };
        void move() {
            if(direction == 1) {
                column--;
                if(column < 0)
                    column = src.columns(row) - 1;
            }
            else if(direction == 2) {
                row--;
                if(row < 0)
                    row = src.rows() - 1;
            }
            else if(direction == 3) {
                column++;
                if(column >= src.columns(row))
                    column = 0;
            }
            else if(direction == 4) {
                row++;
                if(row >= src.rows())
                    row = 0;
            }
            else {
                std::cout << "invalid direction" << std::endl;
                exit(1);
            }
        }
        void draw() {
            //show source code
            std::string str;
            for(int i = 0; i < src.rows(); i++) {
                for(int j = 0; j < src.columns(i); j++) {
                    char ch = src.getChar(i, j);
                    std::string chstr(1, ch);
                    if(i == row && j == column)
                        str += "\e[48;5;248m" + chstr + "\e[0m";
                    else
                        str += chstr;
                }
                str += "\n";
            }
            str += "\n";

            //show stack
            for(int i = 0; i < stack.count(); i++)
               str += std::to_string(stack[i]) + " ";
            for(int i = stack.count(); i < 30; i++)
                str += " ";
            str += "\n";

            //show result
            str += output;
            str += "\n";

            str += "\r\e[" + std::to_string(3 + src.rows()) + "A";
            std::cout << str << std::flush;
        }
        void run() {
            while(!end) {
                this->draw();

                if(skip) {
                    skip = false;
                    move();
                    continue;
                }

                char c = src.getChar(row, column);
                //std::cout << c << row << column << std::endl;
                if(ascii) {
                    if(c == '"') {
                        ascii = false;
                    }
                    else {
                        stack.push((int)c);
                    }
                }
                else {
                    if(c == '<') {
                        direction = 1;
                    }
                    else if(c == '>') {
                        direction = 3;
                    }
                    else if(c == '^') {
                        direction = 2;
                    }
                    else if(c == 'v') {
                        direction = 4;
                    }
                    else if(c == '_') {
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
                    else if(c == '8') {
                        stack.push(8);
                    }
                    else if(c == '9') {
                        stack.push(9);
                    }
                    else if(c == '"') {
                        ascii = true;
                    }
                    else if(c == '&') {
                        std::string input;
                        std::cin >> input;
                        stack.push(std::stoi(input));
                    }
                    else if(c == '~') {
                        char input;
                        std::cin >> input;
                        stack.push((int)input);
                    }
                    else if(c == '.') {
                        int x = stack.pop();
                        output += std::to_string(x) + " ";
                    }
                    else if(c == ',') {
                        int x = stack.pop();
                        std::string ch(1, (char)x);
                        output += ch;
                    }
                    else if(c == '+') {
                        int y = stack.pop();
                        int x = stack.pop();
                        stack.push(x + y);
                    }
                    else if(c == '-') {
                        int y = stack.pop();
                        int x = stack.pop();
                        stack.push(x - y);
                    }
                    else if(c == '*') {
                        int y = stack.pop();
                        int x = stack.pop();
                        stack.push(x * y);
                    }
                    else if(c == '/') {
                        int y = stack.pop();
                        int x = stack.pop();
                        stack.push(x / y);
                    }
                    else if(c == '%') {
                        int y = stack.pop();
                        int x = stack.pop();
                        stack.push(x % y);
                    }
                    else if(c == '`') {
                        int y = stack.pop();
                        int x = stack.pop();
                        if(x > y)
                            stack.push(1);
                        else
                            stack.push(0);
                    }
                    else if(c == '!') {
                        int x = stack.pop();
                        if(x == 0)
                            stack.push(1);
                        else
                            stack.push(0);
                    }
                    else if(c == ':') {
                        int x = stack.pop();
                        stack.push(x);
                        stack.push(x);
                    }
                    else if(c == '\\') {
                        int y = stack.pop();
                        int x = stack.pop();
                        stack.push(y);
                        stack.push(x);
                    }
                    else if(c == '$') {
                        stack.pop();
                    }
                    else if(c == 'g') {
                        int y = stack.pop();
                        int x = stack.pop();
                        int ch = (int)src.getChar(y, x);
                        stack.push(ch);
                    }
                    else if(c == 'p') {
                        int y = stack.pop();
                        int x = stack.pop();
                        int v = stack.pop();
                        src.writeChar(y, x, (char)v);
                    }
                    else {
                        std::cout << "syntax error" << std::endl;
                        exit(1);
                    }
                }

                sleep();
                move();
            }
            std::cout << std::flush;
        };
};
#endif
