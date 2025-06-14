#include <iostream>
#include <string>
#include "board.h"
#include "util.h"

//Public
Board::Board(int totalPlayers) {
    numPlayers = totalPlayers;
    lastMovesPtr = new int[numPlayers];

    resetBoard();
}

void Board::resetBoard() {
    // Clear board values
    for (int y = 0; y < BOARDSIZE; y++) {
        for (int x = 0; x < BOARDSIZE; x++) {
            values[y][x] = ' ';
        }
    }

    // Clear last moves array
    for (int i = 0; i < numPlayers; i++) {
        lastMovesPtr[i] = -1;
    }
}

void Board::printBoard() {
    // Print Boxes
    for (int y = 0; y < BOARDSIZE; y++) {
        for (int x = 0; x < BOARDSIZE; x++) {
            // Go to top left corner of calculated position for box
            std::cout << "\033[" << yBoardStart + y * (squareHeight - 1) << ";" << xBoardStart + x * (squareLength - 1) << "H";
            std::cout << "+-------+" << "\033[1B" << "\033[" << squareLength << "D";
            std::cout << "|       |" << "\033[1B" << "\033[" << squareLength << "D";
            std::cout << "|   " << values[y][x] << "   |" << "\033[1B" << "\033[" << squareLength << "D";
            std::cout << "|       |" << "\033[1B" << "\033[" << squareLength << "D";
            std::cout << "+-------+";
        }
    }

    // Print board headers
    for (int x = 0; x < BOARDSIZE; x++) {
        std::cout << "\033[" << yBoardStart - 1 << ";" << xBoardStart + squareLength / 2 + x * (squareLength - 1) << "H" << x + 1;
        std::cout << "\033[" << yBoardStart + squareHeight / 2 + x * (squareHeight - 1) << ";" << xBoardStart - 2 << "H" << static_cast<char>(65 + x);
    }
}

void Board::acceptValue(char value, int location, int player) {
    int row, col;
    locationToRowCol(row, col, location);

    values[row][col] = value;

    // Debugging line
    if (player < 1 || player > numPlayers) {
        std::cout << "ERROR! ACCEPT VALUES";
        exit(1);
    }

    lastMovesPtr[player - 1] = location;
}

char Board::getValue(int location) {
    int row, col;
    locationToRowCol(row, col, location);

    return values[row][col];
}

bool Board::isValidMove(int location) {
    int row, col;
    locationToRowCol(row, col, location);
    bool valid = true;

    if (numPlayers == 2) {
        if (values[row][col] == ' ') {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        for (int i = 0; i < numPlayers; i++) {
            if (location == lastMovesPtr[i]) {
                valid = false;
            }
        }
    }
    return valid;
}

// Private
