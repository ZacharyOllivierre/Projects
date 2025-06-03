#include <iostream>
#include "game.h"

int main() {
    Game game1;

    std::cout << "\e[?25l"; // Hide cursor

    game1.gameLoop();

    std::cout << "\e[?25h"; // Show cursor

    return 0;
}