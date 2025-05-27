#include "util.hpp"
#include <iostream>
#include <string>
#include <cctype>

// To decode row = return / 10 | col = return % 10
int cordToIndex(std::string coordinate) {
    char rowChar = toupper(coordinate[0]);

    int row = static_cast<int>(rowChar) - 65;
    int col = static_cast<int>(coordinate[1]) - '1';

    return row * 10 + col;
}

// Decodes encoded index, passes through reference
void indexToRowCol(int index, int& row, int& col) {
    row = index / 10;
    col = index % 10;
}