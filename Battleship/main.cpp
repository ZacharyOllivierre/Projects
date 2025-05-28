#include "main.hpp"
#include "board.hpp"
#include "util.hpp"

int main() {
    // Clear Screen
    cout << "\033[2J";

    Board board1(1);
    Board board2(2);

    int array[3];
    array[0] = cordToIndex("D5");
    array[1] = cordToIndex("E5");
    array[2] = cordToIndex("F5");

    int* ptr = array;

    board1.acceptShip(ptr, 3);
    board2.acceptShip(ptr, 3);

    board1.displayBoard(2);
    board1.displayMedian();
    board2.displayBoard(2);

    return 0;
}