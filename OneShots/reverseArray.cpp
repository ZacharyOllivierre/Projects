#include <iostream>
using namespace std;

void reverseArray(int* arrayPtr, int size);
void fillArray(int* arrayPtr, int size);
void outputArray(int* arrayPtr, int size);

// Takes a pointer to an integer array and its size. Reverses the array in place using pointer arithmetic (not array indexing like 
// arr[i]). Demonstrate it in main() with an example array of at least 6 elements and print the reversed array.

int main() {
    int* arrayPtr = nullptr;
    int size;

    cout << "Enter size: ";
    cin >> size;
    arrayPtr = new int[size];
    fillArray(arrayPtr, size);

    cout << "Before reverse | ";
    outputArray(arrayPtr, size);

    reverseArray(arrayPtr, size);

    cout << "\nAfter reverse | ";
    outputArray(arrayPtr, size);

    delete [] arrayPtr;
    return 0;
}

void reverseArray(int* arrayPtr, int size) {
    int temp;
    int* end = arrayPtr + size - 1;

    while (arrayPtr < end) {
        temp = *end;
        *end = *arrayPtr;
        *arrayPtr = temp;

        arrayPtr++;
        end--;
    }
}

void fillArray(int* arrayPtr, int size) {
    for (int x = 0; x < size; x++) {
        *(arrayPtr + x) = x + 1;
    }
}

void outputArray(int* arrayPtr, int size) {
    cout << "Array: " << endl;

    for (int x = 0; x < size; x++) {
        cout << *(arrayPtr + x) << " ";
    }
    cout << endl;
}