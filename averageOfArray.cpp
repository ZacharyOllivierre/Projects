#include <iostream>
using namespace std;

// Write a function that takes an array of integers and its size, and returns the average (as a double) of the values in the array.
// Demonstrate calling this function from main() with an example array of at least 5 values.

double averageInt(int* arrayPtr, int size);
void input(int* arrayPtr, int size);

int main() {
    int size;
    int* arrayPtr = nullptr;
    double valAverage;

    cout << "Enter size: ";
    cin >> size;

    arrayPtr = new int[size];

    input(arrayPtr, size);
    valAverage = averageInt(arrayPtr, size);

    cout << "Average of array is " << valAverage << endl;
    
    delete [] arrayPtr;
    return 0;
}

double averageInt(int* arrayPtr, int size) {
    double sum = 0;

    for (int j = 0; j < size; j++) {
        sum += arrayPtr[j];
    }

    return sum/static_cast<double>(size);
}

void input(int* arrayPtr, int size) {
    for (int n = 0; n < size; n++) {
        cout << "Enter value " << n + 1 << ": ";
        cin >> arrayPtr[n];
    }
}