#include <iostream>
#include "util.h"

// Converts row col to single int "location"
int rowColToLocation(int row, int col) {
    return row * 10 + col;
}

// Converts "location" to row call by reference
void locationToRowCol(int& row, int& col, int location) {
    row = location / 10;
    col = location % 10;

    // Debugging line
    if (row >= 3 || col >= 3) {
        std::cout << "ERROR Util";
        exit(1);
    }
    
}

int alphaNumToLocation(std::string input) {
    
    int row = static_cast<int>(toupper(input[0])) - 'A';
    int col = input[1] - '1';

    return rowColToLocation(row, col);
}

void clearScreen() {
    std::cout << "\033[2J";
}
