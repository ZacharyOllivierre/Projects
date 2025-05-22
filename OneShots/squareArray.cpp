#include <iostream>
using namespace std;

void squareArray(int* arrayPtr, int size);
void fillArray(int* arrayPtr, int size);
void outputArray(int* arrayPtr, int size);

int main() {
    int size;
    int* arrayPtr = nullptr;

    cout << "Enter size: ";
    cin >> size;

    arrayPtr = new int[size];
    fillArray(arrayPtr, size);
    squareArray(arrayPtr, size);
    outputArray(arrayPtr, size);
    
    delete [] arrayPtr;
    return 0;
}

void squareArray(int* arrayPtr, int size) {
    for (int x = 0; x < size; x++) {
        arrayPtr[x] = arrayPtr[x] * arrayPtr[x];
    }
}

void fillArray(int* arrayPtr, int size) {
    for (int x = 0; x < size; x++) {
        arrayPtr[x] = x + 1;
    }
}

void outputArray(int* arrayPtr, int size) {
    for (int x = 0; x < size; x++) {
        cout << arrayPtr[x] << " ";
    }
    cout << endl;
}