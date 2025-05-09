#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void bubbleSort(int* ptr, int size);
void fillArray(int* ptr, int size, int valueMax);
void outputArray(int* ptr, int size, int valueMax);
void sortCheck(int* ptr, int size);

int main() {
    const int valueMax = 100;
    int* ptr = nullptr;
    int size;
    int index;

    srand(time(nullptr));

    cout << "\nEnter size of array: ";
    cin >> size;

    ptr = new int[size];

    fillArray(ptr, size, valueMax);
    outputArray(ptr, size, valueMax);

    cout << "\nSorting array\n";

    bubbleSort(ptr, size);
    outputArray(ptr, size, valueMax);
    sortCheck(ptr, size);

    delete [] ptr;
    return 0;
}

void bubbleSort(int* ptr, int size) {
    int temp;
    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            comparisons++;
            if (ptr[j] > ptr[j + 1]) {
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
                swaps++;
            }
        }
    }
    cout << "Completed with " << comparisons << " comparisons and " << swaps << " swaps.\n" << endl;
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

void sortCheck(int* ptr, int size) {
    bool sorted = true;
    int temp = ptr[0];

    for (int x = 0; x < size; x++) {
        if (ptr[x+1] < ptr[x]) {
            sorted = false;
        }
    }
    
    if (sorted) {
        cout << "Array is sorted in acending order." << endl;
    } else {
        cout << "Array is not sorted in acending order." << endl;
    }
}