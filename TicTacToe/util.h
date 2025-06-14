#pragma once
#include <string>

// Converts row col to single int "location"
int rowColToLocation(int row, int col);

// Converts "location" to row call by reference
void locationToRowCol(int& row, int& col, int location);

// Converts "A1" to "location" equivalent
int alphaNumToLocation(std::string input);

void clearScreen();

