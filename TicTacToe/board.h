#pragma once
#include <string>

class Board {
private:

    const int xBoardStart = 50;
    const int yBoardStart = 5;

    const int squareLength = 9;
    const int squareHeight = 5;

    static const int BOARDSIZE = 3;
    char values[BOARDSIZE][BOARDSIZE];

    // Stores last move from each player 
    int* lastMovesPtr;
    int numPlayers;

public:

    Board(int totalPlayers);
    
    void resetBoard();
    void printBoard();

    void acceptValue(char value, int location, int player);
    char getValue(int location);
    
    bool isValidMove(int location);
};