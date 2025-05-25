#include "hangman.h"
using namespace std;

// File words into string, returns pointer / wordCount by reference
string* readFromFile(int& wordCount) {
    wordCount = 0;
    string temp;
    string* wordList = nullptr;

    ifstream file("words.txt");
    if (!file) {
        cout << "ERROR | COULD NOT OPEN FILE" << endl;
        exit(1);
    }

    while (file >> temp) {
        wordCount++;
    }

    if (wordCount == 0) {
        cout << "ERROR | EMPTY FILE" << endl;
        exit(1);
    }
    
    file.clear();           // clear EOF flag
    file.seekg(0);          // move back to beginning

    wordList = new string[wordCount];

    for (int x = 0; x < wordCount; x++) {
        file >> wordList[x];
    }

    file.close();

    return wordList;
}

void printLines(int num) {
    for (int x = 0; x < num; x++) {
        cout << "-";
    }
}

bool playAgain() {
    char input;
    
    do {
        cout << "\n";
        printCentered("Would you like to play again (y | n): ");
        cin >> input;
        input = tolower(input);

    } while (input != 'y' && input != 'n');

    printLines(GAME_WIDTH);
    cout << "\n";

    cin.ignore();

    if (input == 'y') {
        return true;
    }
    return false;
}

void printCentered(const string& text, int extra, int width) {
    int padding = (width - text.length() - extra) / 2;

    if (padding < 0) {padding = 0;}

    cout << setw(padding + text.length()) << text;
}

void printCenteredMultiline(const string& text, int width) {
    string line = "";
    
    for (int x = 0; x < text.size(); x++) {
        char c = text[x];
        
        if (c == '\n') {
            // Print the current line centered
            int padding = max(0, (width - (int)line.size()) / 2);
            cout << setw(padding + line.size()) << line << endl;

            // reset for next line
            line = "";

        } else {
            line += c;
        }
    }

    // Print last line if no trailing newline
    if (!line.empty()) {
        int padding = max(0, (width - (int)line.size()) / 2);
        cout << setw(padding + line.size()) << line << endl;
    }
}