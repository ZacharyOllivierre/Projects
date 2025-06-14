#pragma once
#include <string>
#include "board.h"

class Player {
private:
    // Type H(num) | B(num)
    std::string type;
    
    // Total moves made counter
    int moves;
    bool won;
    char symbol;

    // Expected 1-3
    int numPlayers;

    void updateWon(Board* board);
    int getBotMove(Board* board);
    bool isValidInputFormat(std::string input);

public:
    Player(std::string playerType, int totalPlayers);
    void moveInput(Board* board);
    bool getWon();
    void resetPlayer();
};