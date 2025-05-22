#include <iostream>
#include <string>
using namespace std;

void numOfDigits(char* text, int size);
void input(char*& text, int& size);

int main() {
    char* text = nullptr;
    int size;

    input(text, size);
    numOfDigits(text, size);

    return 0;
}

void numOfDigits(char* text, int size) {
    int count = 0;

    // for (int x = 0; x < size; x++) {
    //     cout << "text: " << text[x] << " | " << static_cast<int>(text[x]) << endl;
    //     if (text[x] >= 48 && text[x] <= 57) {
    //         count++;
    //     }
    // }

    int x = 0;
    while (text[x] != '\0') {
        if (text[x] >= 48 && text[x] <= 57) {
            count++;
        }
        x++;
    }

    cout << "There were " << count << " digits." << endl;
}

void input(char*& text, int& size) {
    string input;

    cout << "Enter a sentence: ";
    getline(cin, input);

    size = input.length();
    text = new char[size + 1];

    for (int x = 0; x < size; x++) {
        text[x] = input[x];
    }

    text[size] = '\0';
}