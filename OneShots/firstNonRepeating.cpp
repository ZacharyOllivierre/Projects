#include <iostream>
#include <string>
using namespace std;

char firstNonRepeating(char* input, int size);
void input(char*& input, int& size);

int main() {
    char* word = nullptr;
    int size;
    char letter;

    input(word, size);
    letter = firstNonRepeating(word, size);
    
    if (letter == '-') {
        cout << "There were no repeating characters" << endl;
    }
    else {
        cout << "The first repeating character was " << letter << endl;
    }

    delete [] word;
    return 0;
}

char firstNonRepeating(char* input, int size) {
    for (int x = 0; x < size - 1; x++) {
        for (int y = x + 1; y < size; y++) {
            if (input[x] == input[y]) {
                return input[x];
            }
        }
    }
    return '-';
}

void input(char*& input, int& size) {
    string word;

    cout << "Enter word: ";
    cin >> word;

    size = word.length();
    input = new char[size + 1];
    
    for (int x = 0; x < size; x++) {
        input[x] = word[x];
    }

    input[size] = '\0';
}