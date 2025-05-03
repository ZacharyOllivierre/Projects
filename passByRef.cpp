#include <iostream>
using namespace std;

// Next, write a function that takes a reference to an int and doubles its value. Then call it from main and print the result 
// before and after the function call.

void passByRef(int& n);

int main() {
    int num;

    cout << "Enter number: ";
    cin >> num;

    cout << "Your number was " << num << endl;
    passByRef(num);
    cout << "After function call your number is " << num << endl;

    return 0;
}

void passByRef(int& n) {
    n *= 2;
}