#include <iostream>
using namespace std;

// Now write a function that takes a pointer to an int, checks if it’s nullptr, and if not, sets the value it points to as the 
// square of its original value. Demonstrate it in main with proper pointer setup.

void ptrChecker(int* ptr);

int main() {
    int num = 10;
    int* ptr = nullptr;
    int choice;

    do {
        cout << "Enter choice (0 - null : 1 - address): ";
        cin >> choice;
    } while (choice != 0 && choice != 1);

    if (choice) {
        ptr = &num;
        cout << "Before function call pointer is " << *ptr << endl;
        ptrChecker(ptr);
        cout << "After function call pointer is " << *ptr << endl;
    } else {
        cout << "Before function call pointer is " << ptr << endl;
        ptrChecker(ptr);
        cout << "After function call pointer is " << ptr << endl;
    }
    
    return 0;
}

void ptrChecker(int* ptr) {
    if (ptr == nullptr) {
        cout << "Pointer is null." << endl;
    } else {
        cout << "Pointer is " << *ptr << endl;
        *ptr = *ptr * *ptr;
    }
}