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
        };
        int rows() const {
            return src.size() - 1;
        };
        int columns(int i) const {
            return src[i - 1].size();
        };
        char getChar(int i, int j) const {
            if(i < 1 || i > src.size() || j < 1 || j > src[i - 1].size()) {
                std::cout << "invalid (row, column) access at (" << i << ", " << j << ")" << std::endl;
                exit(1);
            }
            return src[i - 1][j - 1];
        };
        void writeChar(int i, int j, char c) {
            if(i < 1 || i > src.size() || j < 1 || j > src[i - 1].size()) {
                std::cout << "invalid (row, column) access at (" << i << ", " << j << ")" << std::endl;
                exit(1);
            }
            src[i - 1][j - 1] = c;
        }
        std::string getLine(int i) const {
            return src[i];
        };
};
#endif
