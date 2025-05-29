#pragma once
#include <string>

enum class cellState { 
    Empty = 0,
    Ship = 1,
    Hit = 2,
    Miss = 3
};
    
class Board {
private:
    static const int BOARDSIZE = 10;
    const int SPACING = 1;
    const int BOXWIDTH = 5;
    const int BOXHEIGHT = 3;
    const int MEDIANSIZE = 2;
    const int MEDIANSPACE = 2;

    cellState board[BOARDSIZE][BOARDSIZE];
    // 0 = Empty | 1 = Ship | 2 = Hit | 3 = Miss

    int horizontalOffset = 0;

    // Checks if cell[row][col] is currently a ship
    bool attackHit(int row, int col);

public:
    // Establishes empty board, playerID expects 1 or 2 to set horizontal offset
    Board(int playerID);
    
    // Display board array, type changes center printing type
    void displayBoard(int type);

    // (Could be Private as of Now) Prints center of box dependent on print type ie x, val, " "
    std::string displayCenter(int type, int x, int y);

    // Prints Median between boards (prints in fixedish location)
    void displayMedian();

    // Changes cell states to represent ship addition, expects numbered encoded coordinate
    void acceptShip(int* cordNum, int size);

    // Changes cell states to empty
    void removeShip(int* cordNum, int size);

    // Changes cell state to hit or miss
    void acceptAttack(int row, int col);

    void reset();
};