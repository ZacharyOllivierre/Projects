#include <iostream>
using namespace std;

bool isPrime(int num);

int main() {
    int num;

    cout << "Enter: ";
    cin >> num;

    if (isPrime(num)) {
        cout << "Number is prime." << endl;
    } else {
        cout << "Number is not prime." << endl;
    }

    return 0;
}

bool isPrime(int num) {
    bool prime = true;

    for (int x = 2; x < num; x++) {
        if (num % x == 0) {
            prime = false;
        }
    }
    return prime;
}