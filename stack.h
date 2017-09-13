#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstdlib>


template <typename T>
class Stack {
    private:
        T *stack;
        int index;
    public:
        Stack() {
            stack = new T[100];
            index = 0;
        };
        ~Stack() {
            delete[] stack;
        };
        void push(T x) {
            if(index == 100) {
                std::cout << "stack overflow" << std::endl;
                exit(1);
            }
            stack[index] = x;
            index++;
        };
        T pop() {
            if(index == 0) {
                std::cout << "no data in stack" << std::endl;
                exit(1);
            }
            index--;
            return stack[index];
        };
        int count() {
            return index;
        };
};
#endif
