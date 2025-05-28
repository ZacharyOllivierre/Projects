#pragma once
#include <string>

class Board {
private:
    static constexpr int BOARDSIZE = 10;
    const int SPACING = 1;
    const int BOXWIDTH = 5;
    const int BOXHEIGHT = 3;
    const int MEDIANSIZE = 2;
    const int MEDIANSPACE = 2;

    int board[static_cast<int>(BOARDSIZE)][static_cast<int>(BOARDSIZE)];
    // 0 = Empty | 1 = Ship | 2 = Hit | 3 = Miss
    
    int horizontalOffset = 0;

    bool attackHit(int row, int col);

public:
    Board(int playerID);
    
    void displayBoard(int type);
    std::string displayCenter(int type, int x, int y);
    void displayMedian();
    void acceptShip(int* cordNum, int size);
    void removeShip(int* cordNum, int size);
    void acceptAttack(int row, int col);
};


// Class board;
// 	Create and initialize a fresh board (2D int array)
// 	Display the board (with or without hidden ships)
// 	Place ships on the board (check bounds, overlaps)
// 	Handle incoming attacks (hit, miss, already hit)
// 	Track state using enum (EMPTY, SHIP, HIT, MISS)
