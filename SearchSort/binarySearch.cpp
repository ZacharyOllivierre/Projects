#include <iostream>
#include <iomanip>
using namespace std;

int binarySearch(int* ptr, int size, int target);
void fillArrayAcending(int* ptr, int size);
void outputArray(int* ptr, int size);

int main() {
    int* ptr = nullptr;
    int size;
    int target;
    int index;

    cout << "\nEnter size of array: ";
    cin >> size;

    ptr = new int[size];
    fillArrayAcending(ptr, size);

    cout << "\nEnter target number: ";
    cin >> target;

    index = binarySearch(ptr, size, target);

    if (index != -1) {
        cout << target << " found at index " << index << "." << endl;
    } else {
        cout << target << " was not found." << endl;
    }

    return 0;
}

int binarySearch(int* ptr, int size, int target) {
    int leftIndex = 0;
    int middleIndex;
    int rightIndex = size - 1;
    int foundIndex = -1;

    while (leftIndex <= rightIndex) {
        middleIndex = (rightIndex + leftIndex) / 2;

        cout << "\nleft index: " << leftIndex;
        cout << "\nmiddle index: " << middleIndex << endl;
        cout << "right index: " << rightIndex << endl << endl;

        if (ptr[middleIndex] == target) {
            // middle is my target
            foundIndex = middleIndex;
            leftIndex += 1;
        } else if (ptr[middleIndex] < target) {
            // middle is less than target
            leftIndex = middleIndex + 1;
        } else {
            // middle is greater than target
            rightIndex = middleIndex - 1;
        }
    }
    return foundIndex;
}

void fillArrayAcending(int* ptr, int size) {
    for (int j = 0; j < size; j++) {
        ptr[j] = j + 1;
    }
    outputArray(ptr, size);
}

void outputArray(int* ptr, int size) {
    int wSpace = 2;
    int temp = size;

    while (temp > 0) {
        wSpace++;
        temp = temp / 10;
    }

    cout << endl << left;
    for (int x = 0; x < size; x++) {
        cout << setw(wSpace) << ptr[x];
    }
    cout << "\n";
    for (int x = 0; x < size; x++) {
        cout << setw(wSpace) << x;
    }
    cout << "\n";
}
