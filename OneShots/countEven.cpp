#include <iostream>
using namespace std;

int evenCount(int* arrayPtr, int size);
int* input(int size);

int main() {
    int size = 0;
    int even;
    int odd;

    cout << "Enter size of array: ";
    cin >> size;

    even = evenCount(input(size), size);
    odd = size - even;

    cout << "\nThere are " << even << " even numbers and " << odd << " odd numbers." << endl;
    
    delete [] input(size);
    return 0;
}

int evenCount(int* arrayPtr, int size) {
    int evenCount = 0;

    for (int x = 0; x < size; x++) {
        if (arrayPtr[x] % 2 == 0) {
            evenCount++;
        }
    }
    return evenCount;
}

int* input(int size) {
    int* arrayPtr = new int[size];

    for (int x = 0; x < size; x++) {
        cout << "Entry " << x + 1 << ": ";
        cin >> arrayPtr[x];
    }

    return arrayPtr;
}