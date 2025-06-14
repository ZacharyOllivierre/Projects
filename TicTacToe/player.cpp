#include <iostream>
#include <string>
#include <cstdlib>
#include "util.h"
#include "player.h"
#include "board.h"

// Public

Player::Player(std::string playerType, int totalPlayers) {
    // Initiallize player for start of round
    type = playerType;
    won = false;
    moves = 0;
    numPlayers = totalPlayers;

    switch (playerType[1]) {
        case '1':
            symbol = 'X';
            break;

        case '2':
            symbol = 'O';
            break;

        case '3':
            symbol = 'E';
            break;
    }
}

void Player::moveInput(Board* board) {
    std::string input;
    int location;
    int playerId = type[1] - '0';

    // If Bot
    if (type[0] == 'B') {
        location = getBotMove(board);

        board->acceptValue(symbol, location, playerId);
        updateWon(board);
        return;
    }

    do {
        do {
            // Go to 50, 75 and clear anything after
            std::cout << "\033[20;50H" << "\033[0J" << "Player " << type[1] << " Enter Position (ex A1): ";
            std::cin >> input;

        // Input Validation
        } while(!isValidInputFormat(input));
        
        location = alphaNumToLocation(input);

    // Board validation
    } while(!board->isValidMove(location));

    board->acceptValue(symbol, location, playerId);

    updateWon(board);

    // Check if Board is full if so reset
    bool full = true;
    for (int y = 0; y < 3 & numPlayers == 2; y++) {
        for (int x = 0; x < 3; x++) {
            if (board->getValue(rowColToLocation(y, x)) == ' ') {
                full = false;
            }
        }
    }
    if (full && numPlayers == 2) {board->resetBoard();}
}

bool Player::getWon() {
    return won;
}

void Player::resetPlayer() {
    moves = 0;
    won = false;
}

// Private

void Player::updateWon(Board* board) {
    // Check Row Wins
    for (int y = 0; y < 3; y++) {
        if (board->getValue(y * 10) == symbol && board->getValue(y * 10 + 1) == symbol && board->getValue(y * 10 + 2) == symbol) {
            won = true;
            return;
        } 
    }

    // Check Column Wins
    for (int x = 0; x < 3; x++) {
        if (board->getValue(0 * 10 + x) == symbol && board->getValue(1 * 10 + x) == symbol && board->getValue(2 * 10 + x) == symbol) {
            won = true;
            return;
        }
    }

    // Check Diagonal top left to bottom right
    if (board->getValue(0) == symbol && board->getValue(11) == symbol && board->getValue(22) == symbol) {
        won = true;
        return;
    }

    // Check Anti-diagonal top right to bottom left
    if (board->getValue(0 * 10 + 2) == symbol && board->getValue(1 * 10 + 1) == symbol && board->getValue(2 * 10 + 0) == symbol) {
        won = true;
        return;
    }
}

int Player::getBotMove(Board* board) {
    int row, col;

    do {
        int random = rand() % 9;
        row = random / 3;
        col = random % 3;
        
    } while (!board->isValidMove(rowColToLocation(row, col)));

    return rowColToLocation(row, col);
}

bool Player::isValidInputFormat(std::string input) {
    if (input.length() != 2) return false;

    char rowChar = toupper(input[0]);
    char colChar = input[1];

    if (rowChar < 'A' || rowChar > 'C') return false;
    if (colChar < '1' || colChar > '3') return false;

    return true;
}