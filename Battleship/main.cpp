#include "main.hpp"
#include "board.hpp"
#include "util.hpp"

int main() {
    // Clear Screen
    cout << "\033[2J";

    Board board1(1);
    int array[3];
    array[0] = cordToIndex("D5");
    array[1] = cordToIndex("E5");
    array[2] = cordToIndex("F5");

    int* ptr = array;

    board1.acceptShip(ptr, 3);
    board1.acceptAttack(1, 1);
    board1.acceptAttack(0, 0);

    board1.displayBoard(2);

    return 0;
}