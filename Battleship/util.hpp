#pragma once
#include <string>

// Naming Convention
// strCord = "A1"   |   index = 11 (encoded row & col)
// Need to update naming to ^

int cordToIndex(std::string coordinate);

void indexToRowCol(int cordNum, int& row, int& col);

void printBox(int startX, int startY, int endX, int endY);

