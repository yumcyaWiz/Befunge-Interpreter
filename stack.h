#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstdlib>


class Stack {
    private:
        int* stack;
        int index;
        int size;
    public:
        Stack() {};
        Stack(int _size) {
            size = _size;
            stack = new int[size];
            index = 0;
        };
        ~Stack() {
            delete[] stack;
        };
        

        int operator[](int _index) {
            if(_index < 0 || _index >= index) {
                std::cout << "invalid index" << std::endl;
                exit(1);
            }
            return stack[_index];
        };


        void push(int x) {
            if(index >= size) {
                std::cout << "stack overflow" << std::endl;
                exit(1);
            }
            stack[index] = x;
            index++;
        };
        int pop() {
            if(index <= 0) {
                //std::cout << "no data in stack" << std::endl;
                return 0;
            }
            index--;
            return stack[index];
        };
        int count() {
            return index;
        };
        int stack_size() {
            return size;
        };
};
#endif
