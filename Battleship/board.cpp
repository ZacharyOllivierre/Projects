#include "board.hpp"
#include "util.hpp"
#include <iostream>
#include <string>
using namespace std;

Board::Board(int playerID) {

    // Fill standing board with empties
    for (int y = 0; y < BOARDSIZE; y++) {
        
        for (int x = 0; x < BOARDSIZE; x++) {
            board[y][x] = cellState::Empty;
        }
    }

    // Set horizontal printing offset for player 2
    if (playerID == 2) {
        horizontalOffset = (BOXWIDTH + SPACING) * BOARDSIZE + MEDIANSIZE + 1 + MEDIANSPACE * 2;
    }
}

// void Board::displayBoard(int type) {
//     for (int y = 0; y < BOARDSIZE; y++) {
        
//         for (int x = 0; x < BOARDSIZE; x++) {
//             cout << "\033[" + to_string(y * (BOXHEIGHT + SPACING) + 1) + ";" + to_string(x * (BOXWIDTH + SPACING) + 1 + horizontalOffset) + "H" << "+---+";
//             cout << "\033[1B" << "\033[" + to_string(BOXWIDTH) + "D" << "| " << Board::displayCenter(type, x, y) << " |";
//             cout << "\033[1B" << "\033[" + to_string(BOXWIDTH) + "D" << "+---+";
//         }
//     }
// }

void Board::displayBoard(int type) {

    int playerBoardXLength = BOARDSIZE * BOXWIDTH;
    int playerBoardYLength = BOARDSIZE * BOXHEIGHT;
    int marginSize = 2;
    int marginPadding = 1;

    int gameBoardYPadding = 2;
    int gameBoardXPadding = gameBoardYPadding * 2;
    int gameBoardStartX = 1;
    int gameBoardStartY = 1;
    int gameBoardEndX = gameBoardStartX + (gameBoardXPadding * 2) + (playerBoardXLength * 2) + (marginPadding * 2) + marginSize; 
    int gameBoardEndY = gameBoardStartY + (gameBoardYPadding * 2) + playerBoardYLength + 2;

    int playerBoardStartX = gameBoardStartX + gameBoardXPadding;
    int playerBoardStartY = gameBoardStartY + gameBoardYPadding + 1; 
    int playerBoardEndX = playerBoardStartX + playerBoardXLength;
    int playerBoardEndY = playerBoardStartY + playerBoardYLength;

    if (horizontalOffset) {
        playerBoardStartX = playerBoardStartX + playerBoardXLength + (marginPadding * 2) + marginSize;
        playerBoardEndX = playerBoardEndX + playerBoardXLength + (marginPadding * 2) + marginSize;
    }

    printBox(gameBoardStartX, gameBoardStartY, gameBoardEndX, gameBoardEndY);
    printBox(playerBoardStartX, playerBoardStartY, playerBoardEndX, playerBoardEndY);

    // for (int z = 0; z < BOARDSIZE; z++) {
    //     cout << "\033[" << playerBoardStartY - 1 << ";" << playerBoardStartX + z * BOXWIDTH << "H" << "| " << z + 1 << " |";
    // }

}

string Board::displayCenter(int type, int x, int y) {
    switch (type) {
        case 0:
            return " ";

        case 1:
            return "x";
        
        case 2:
            return to_string(static_cast<int>(board[y][x]));

        default:
            cerr << "ERROR | DISPLAYCENTER";
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

        board[row][col] = cellState::Ship;
    }
}

void Board::removeShip(int* cordNum, int size) {
    int row;
    int col;
    for(int x = 0; x < size; x++) {
        indexToRowCol(cordNum[x], row, col);

        board[row][col] = cellState::Empty;
    }
}

void Board::acceptAttack(int row, int col) {
    if (attackHit(row, col)) {
        board[row][col] = cellState::Hit;

    }
    else {
        board[row][col] = cellState::Miss;
    }

}

bool Board::attackHit(int row, int col) {
    if (board[row][col] == cellState::Ship) {
        return true;

    } else {
        return false;
    }
}

void Board::reset() {
    // Fill standing board with empties
    for (int y = 0; y < BOARDSIZE; y++) {
        
        for (int x = 0; x < BOARDSIZE; x++) {
            board[y][x] = cellState::Empty;
        }
    }
}