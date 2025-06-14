#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "board.h"
#include "player.h"
#include "util.h"

int main() {
    bool playing = 1;
    bool playAgain;
    int numPlayers = 0;
    int numHumPlayers = 0;
    bool won = false;
    int winner;

    srand(time(nullptr));
    clearScreen();

    // Get number of total players
    do {
        std::cout << "Enter Total Players (2 - 3): ";
        std::cin >> numPlayers;

        std::cout << "Enter Number of Human Players (1 - 3): ";
        std::cin >> numHumPlayers;
    } while ((numPlayers < 2 || numPlayers > 3) || (numHumPlayers < 1 || numHumPlayers > 3) || numHumPlayers > numPlayers);

    // Create Board
    Board board(numPlayers);

    // Create Players
    Player** players = new Player*[numPlayers];

    for (int i = 0; i < numPlayers; i++) {
        // If Human Player else create as bot
        if (i < numHumPlayers) {
            players[i] = new Player("H" + std::to_string(i + 1), numPlayers);
        }
        else {
            players[i] = new Player("B" + std::to_string(i + 1), numPlayers);
        }
    }


    // Main game loop
    while (playing) {
        clearScreen();  
        board.printBoard();

        for (int i = 0; i < numPlayers && !won; i++) {
            players[i]->moveInput(&board);
            board.printBoard();

            if (players[i]->getWon()) {
                won = true;
                winner = i + 1;
            }

        }
        
        // Winner message and play again
        if (won) {
            std::cout << "\033[22;50H" << "Player " << winner << " has won.";
            std::cout << "\033[24;50H" << "Would you like to play again (1 | 0): ";
            std::cin >> playAgain;
            
            // Reset for play again
            if (playAgain) {
                board.resetBoard();
                for (int i = 0; i < numPlayers; ++i) {
                    players[i]->resetPlayer();
                }
                won = false;
            }
            else {
                playing = false;
            }
        }
    }

    // Free Memory
    for (int i = 0; i < numPlayers; ++i) {
        delete players[i];
    }
    delete[] players;
    
    clearScreen();
    return 0;
}