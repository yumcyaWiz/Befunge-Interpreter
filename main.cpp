#include <iostream>
#include "stack.h"
#include "source_stream.h"


int main() {
    Source src("abc\ndef");
    std::cout << src.getChar(2, 1) << std::endl;
}
