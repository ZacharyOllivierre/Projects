#include <iostream>
#include <string>
using namespace std;

int main() {
    const int SIZE = 10;
    int board[SIZE][SIZE];

    cout << "\033[2J";
    
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            board[y][x] = 0;
        }
    }

    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            cout << "\033[" + to_string(y * 4 + 1) + ";" + to_string(x * 6 + 1) + "H" << "+---+" << "\033[s";
            cout << "\033[1B" << "\033[5D" << "| " << board[y][x] << " |";
            cout << "\033[1B" << "\033[5D" << "+---+";
        }
    }

    cout << "\033[1;51H" << "||||";

    return 0;
}

// +---+
// | 0 |
// +---+

// \033[<r>;<c>H	    Move cursor to row r, column c	\033[5;10H → row 5, col 10
// \033[<n>A	        Move cursor up by n rows	\033[3A → up 3 rows
// \033[<n>B	        Move cursor down by n rows	\033[2B → down 2 rows
// \033[<n>C	        Move cursor forward (right) by n cols	\033[4C → right 4 columns
// \033[<n>D	        Move cursor backward (left) by n cols	\033[1D → left 1 column
// \033[s	            Save current cursor position	
// \033[u	            Restore saved cursor position	
// \033[H or \033[;H	Move cursor to home position (1,1)

