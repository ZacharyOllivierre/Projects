#include <iostream>
using namespace std;

bool isAnagram(char* wordOne, char* wordTwo, int wordSize);
bool searchLetter(char* word, char letter, int wordSize);

int main() {
    int wordSize;
    char* wordOne = nullptr;
    char* wordTwo = nullptr;

    cout << "Enter word size: ";
    cin >> wordSize;

    wordOne = new char[wordSize];
    wordTwo = new char[wordSize];

    cout << "Enter word one: ";
    cin >> wordOne;
    cout << "Enter word two: ";
    cin >> wordTwo;

    cout << endl;
    if (isAnagram(wordOne, wordTwo, wordSize)) {
        cout << "Word one: " << wordOne << "\nWord two: " << wordTwo << "\nAre anagrams." << endl;
    } else {
        cout << "Word one: " << wordOne << "\nWord two: " << wordTwo << "\nAre not anagrams." << endl;
    }

    return 0;
}

bool isAnagram(char* wordOne, char* wordTwo, int wordSize) {
    bool anagram = true;

    for (int y = 0; y < wordSize && anagram == true; y++) {
        if (searchLetter(wordTwo, wordOne[y], wordSize) == false) {
            anagram = false;
        }
    }

    return anagram;
}

bool searchLetter(char* word, char letter, int wordSize) {
    bool within = false;

    for (int x = 0; x < wordSize && !within; x++) {
        if (word[x] == letter) {
            within = true;
        }
    }

    return within;
}