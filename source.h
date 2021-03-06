#ifndef SOURCE_H
#define SOURCE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>


class Source {
    private:
        std::vector<std::string> src;
    public:
        Source() {};
        Source(const std::string& filename) {
            std::ifstream file;
            file.open(filename, std::ios::binary);
            std::string reading_buffer;
            while(!file.eof()) {
                std::getline(file, reading_buffer);
                src.push_back(reading_buffer);
            }
            file.close();
        };
        int rows() const {
            return src.size() - 1;
        };
        int columns(int i) const {
            return src[i].size();
        };
        char getChar(int i, int j) const {
            //if(i < 0 || i >= src.size() || j < 0 || j >= src[i].size()) {
            //    std::cout << "invalid (row, column) access at (" << i << ", " << j << ")" << std::endl;
            //    exit(1);
            //}
            if(i < 0 || i >= src.size()) {
                std::cout << "incalid row read " << i << std::endl;
                exit(1);
            }
            if(j < 0 || j >= src[i].size())
                return ' ';
            return src[i][j];
        };
        void writeChar(int i, int j, char c) {
            if(i < 0 || i >= src.size() || j < 0 || j >= src[i].size()) {
                std::cout << "invalid (row, column) write at (" << i << ", " << j << ")" << std::endl;
                exit(1);
            }
            src[i][j] = c;
        }
        std::string getLine(int i) const {
            return src[i];
        };
        int getLRCount() const {
            int count = 0;
            for(int i = 0; i < this->rows(); i++) {
                for(int j = 0; j < this->columns(i); j++) {
                    char ch = this->getChar(i, j);
                    if(ch == '\n')
                        count++;
                }
            }
            return count;
        };
};
#endif
