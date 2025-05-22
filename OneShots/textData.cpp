#include <iostream>
#include <string>
using namespace std;

void getData(string text);
int countSpaces(string text, int size);
int countVowels(string text, int size);
int countUpper(string text, int size);
int countLower(string text, int size);
void output(int spaces, int vowels, int upper, int lower);

int main() {
    const string text = "The Quick Brown Fox Jumps Over The Lazy Dog";

    getData(text);

    return 0;
}

void getData(string text) {
    int spaces;
    int vowels;
    int upper;
    int lower;
    int size = text.length();

    spaces = countSpaces(text, size);
    vowels = countVowels(text, size);
    upper = countUpper(text, size);
    lower = countLower(text, size);

    output(spaces, vowels, upper, lower);
}

int countSpaces(string text, int size) {
    int count = 0;

    for (int x = 0; x < size; x++) {
        if (text[x] == ' ') {
            count++;
        }
    }
    return count;
}

int countVowels(string text, int size) {
    int count = 0;

    for (int x = 0; x < size; x++) {
        char c = text[x];

        if (c >= 'A' && c <= 'Z') {
            c = c + 32;
        }
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
            count++;
        }
    }
    return count;
}

int countUpper(string text, int size) {
    int count = 0;

    for (int x = 0; x < size; x++) {

        if (isupper(text[x])) {
            count++;
        }
    
    }
    return count;
}

int countLower(string text, int size) {
    int count = 0;

    for (int x = 0; x < size; x++) {
        if (islower(text[x])) {
            count++;
        }
    
    }
    return count;
}

void output(int spaces, int vowels, int upper, int lower) {
    cout << "There were " << spaces << " spaces." << endl;
    cout << "There were " << vowels << " vowels." << endl;
    cout << "There were " << upper << " uppercase letters." << endl;
    cout << "There were " << lower << " lowercase letters." << endl;
}