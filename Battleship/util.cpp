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

// Start top left of box | end bottom right
void printBox(int startX, int startY, int endX, int endY) {
    int xLength = endX - startX;
    int yLength = endY - startY;
    char line;

    for (int x = 0; x <= xLength; x++ ) {
        if (x == 0 || x == xLength) {
            line = '+';
        }
        else {
            line = '-';
        }
        std::cout << "\033[" + std::to_string(startY) + ";" + std::to_string(startX + x) + "H" << line;
        std::cout << "\033[" + std::to_string(endY) + ";" + std::to_string(startX + x) + "H" << line;
    }

    for (int y = 1; y < yLength; y++ ) {
        std::cout << "\033[" << (startY + y) << ";" << startX << "H" << "|";
        std::cout << "\033[" << (startY + y) << ";" << endX << "H" << "|";
    }
}
