#include "main.hpp"
#include "board.hpp"
#include "ship.hpp"
#include "util.hpp"

int main() {
    // Clear Screen
    cout << "\033[2J";
    int array[5];

    Board board1(1);
    Board board2(2);
    
    Ship ship2(5, "Carrier");

    array[0] = cordToIndex("A1");
    array[1] = cordToIndex("A2");
    array[2] = cordToIndex("A3");
    array[3] = cordToIndex("A4");
    array[4] = cordToIndex("A5");

    int* ptr = array;

    board2.acceptShip(ptr, 5);
    ship2.setCoordinates(ptr, 5);


    board1.displayBoard(2);
    board2.displayBoard(2);
    board1.displayMedian();

    cout << endl;
    
    return 0;
}