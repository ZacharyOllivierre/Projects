#include "board.hpp"
#include "util.hpp"
#include <iostream>
#include <string>
using namespace std;

Board::Board(int playerID) {

    // Fill standing board with empties
    for (int y = 0; y < BOARDSIZE; y++) {
        
        for (int x = 0; x < BOARDSIZE; x++) {
            board[y][x] = 0;
        }
    }

    // Set horizontal printing offset for player 2
    if (playerID == 2) {
        horizontalOffset = (BOXWIDTH + SPACING) * BOARDSIZE + MEDIANSIZE + 1 + MEDIANSPACE * 2;
    }
}

void Board::displayBoard(int type) {
    for (int y = 0; y < BOARDSIZE; y++) {
        
        for (int x = 0; x < BOARDSIZE; x++) {
            cout << "\033[" + to_string(y * (BOXHEIGHT + SPACING) + 1) + ";" + to_string(x * (BOXWIDTH + SPACING) + 1 + horizontalOffset) + "H" << "+---+";
            cout << "\033[1B" << "\033[" + to_string(BOXWIDTH) + "D" << "| " << Board::displayCenter(type, x, y) << " |";
            cout << "\033[1B" << "\033[" + to_string(BOXWIDTH) + "D" << "+---+";
        }
    }
}

string Board::displayCenter(int type, int x, int y) {
    switch (type) {
        case 0:
            return " ";

        case 1:
            return "x";
        
        case 2:
            return to_string(board[y][x]);

        default:
            cout << "ERROR | DISPLAYCENTER";
            return " ";
    }
}

void Board::displayMedian() {
    int boardHeight = (BOXHEIGHT + SPACING) * BOARDSIZE - 1;
    
    for (int y = 0; y < boardHeight; y++) {
        cout << "\033[" + to_string(y + 1) + ";" + to_string(BOARDSIZE * (BOXWIDTH + SPACING) + 1 + MEDIANSPACE) + "H" << "||";
    }
}

void Board::acceptShip(int* cordNum, int size) {
    int row;
    int col;
    for (int x = 0; x < size; x++) {
        indexToRowCol(cordNum[x], row, col);

        board[row][col] = 1;
    }
}

void Board::removeShip(int* cordNum, int size) {
    int row;
    int col;
    for(int x = 0; x < size; x++) {
        indexToRowCol(cordNum[x], row, col);

        board[row][col] = 0;
    }
}

void Board::acceptAttack(int row, int col) {
    if (attackHit(row, col)) {
        board[row][col] = 2;

    }
    else {
        board[row][col] = 3;
    }

}

bool Board:: attackHit(int row, int col) {
    if (board[row][col] == 1) {
        return true;

    } else {
        return false;
    }
}