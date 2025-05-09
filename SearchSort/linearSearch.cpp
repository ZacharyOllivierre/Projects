#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int linearSearch(int* ptr, int size, int target);
void fillArray(int* ptr, int size, int valueMax);
void outputArray(int* ptr, int size, int valueMax);

int main() {
    const int valueMax = 100;
    int* ptr = nullptr;
    int size;
    int target;
    int index;

    srand(time(nullptr));

    cout << "\nEnter size of array: ";
    cin >> size;

    ptr = new int[size];

    fillArray(ptr, size, valueMax);
    outputArray(ptr, size, valueMax);

    cout << "\nEnter target value: ";
    cin >> target;

    index = linearSearch(ptr, size, target);

    delete [] ptr;
    return 0;
}

int linearSearch(int* ptr, int size, int target) {
    int index = -1;
    int comparisons = 0;

    for (int j = 0; j < size && index == -1; j++) {
        if (ptr[j] == target) {
            index = j;
        }
        comparisons++;
    }
    
    cout << "\nCompleted " << comparisons << " comparisons." << endl;
    cout << target << " found at index " << index << endl;

    return index;
}

void fillArray(int* ptr, int size, int valueMax) {
    for (int x = 0; x < size; x++) {
        ptr[x] = rand() % valueMax;
    }
}

void outputArray(int* ptr, int size, int valueMax) {
    int wSpace = 0;

    while (valueMax > 0) {
        wSpace += 1;
        valueMax = valueMax / 10;
    }

    for (int x = 0; x < size; x++) {
        cout << left << setw(wSpace) << ptr[x] << " ";
    }
    cout << endl;
    for (int x = 0; x < size; x++) {
        cout << setw(wSpace) << x << " ";
    }
    cout << endl;
}