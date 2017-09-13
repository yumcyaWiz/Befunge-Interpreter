#ifndef SOURCE_H
#define SOURCE_H
#include <iostream>
#include <cstdlib>
#include <string>


class Source {
    private:
        std::string src;
    public:
        Source() {};
        Source(const std::string& txt) {
            src = txt;
        };
        void setSource(const std::string& txt) {
            src = txt;
        };
        char getChar(int i, int j) const {
            int row = 1;
            int column = 1;
            int index = 0;
            while(index <= src.size()) {
                if(row == i && column == j) {
                    return src[index];
                }
                
                index++;
                column++;
                if(src[index] == '\n') {
                    if(i == row && j > column) {
                        std::cout << "out of range" << std::endl;
                        exit(1);
                    }
                    row++;
                    column = 1;
                    index++;
                }
            }
            std::cout << "out of range" << std::endl;
            exit(1);
        };
        void writeChar(int i, int j, char c) {
            int row = 1;
            int column = 1;
            int index = 0;
            while(index <= src.size()) {
                if(row == i && column == j) {
                    src[index] == c;
                    break;
                }

                index++;
                column++;
                if(src[index] == '\n') {
                    if(i == row && j > column) {
                        std::cout << "out of range" << std::endl;
                        exit(1);
                    }
                    row++;
                    column = 1;
                    index++;
                }
            }
            std::cout << "out of range" << std::endl;
            exit(1);
        }
};
#endif
