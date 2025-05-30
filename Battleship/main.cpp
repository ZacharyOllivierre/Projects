#include "main.hpp"
#include "board.hpp"
#include "ship.hpp"
#include "util.hpp"

int main() {
    // Clear Screen
    cout << "\033[2J";
    
    Board board1(1);
    Board board2(2);

    board1.displayBoard(0);
    board2.displayBoard(0);
    

    return 0;
}