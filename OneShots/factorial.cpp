#include <iostream>
using namespace std;

int factorial(int num);

int main() {
    int num;

    cout << "Enter: ";
    cin >> num;

    cout << "Factorial is " << factorial(num) << endl;

    return 0;
}

int factorial(int num) {
    int total = 1;

    while (num > 0) {
        total = total * num;
        num--;
    } 
    return total;
}