#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

const string HANGMAN_STATES[] = {
    // 0 lives lost
    R"(
     +---+
     |   |
         |
         |
         |
         |
    =========)",

    // 1 life lost
    R"(
     +---+
     |   |
     O   |
         |
         |
         |
    =========)",

    // 2 lives lost
    R"(
     +---+
     |   |
     O   |
     |   |
         |
         |
    =========)",

    // 3 lives lost
    R"(
     +---+
     |   |
     O   |
    /|   |
         |
         |
    =========)",

    // 4 lives lost
    R"(
     +---+
     |   |
     O   |
    /|\  |
         |
         |
    =========)",

    // 5 lives lost
    R"(
     +---+
     |   |
     O   |
    /|\  |
    /    |
         |
    =========)",

    // 6 lives lost
    R"(
     +---+
     |   |
     O   |
    /|\  |
    / \  |
         |
    =========)"
};

string* readFromFile(int& wordCount);
void printLines(int num);

class Man {
    private:
        string codeWord;
        int lives = 6;
        bool won = false;

        char guesses[26];
        int guessCount = 0;
        char incorrectGuesses[26];
        int incorrectGuessesCount = 0;

        int horizontalLineSize = 20;

        bool isWithinGuesses(char letter) {
            for (int x = 0; x < guessCount; x++) {
                if (letter == guesses[x]) {
                    return true;
                }
            }
            return false;
        }

        bool isWithinWord(char letter) {
            for (int x = 0; x < codeWord.length(); x++) {
                if (letter == codeWord[x]) {
                    return true;
                } 
            }
            return false;
        }

        void beginMessage() {
            cout << "Welcome to Hangman" << endl;
            printLines(horizontalLineSize);
            cout << endl;
        }

        void endMessage(bool hasWon) {
            if (hasWon) {
                cout << "You won with " << guessCount << " guesses and " << lives << " lives." << endl;
                cout << "The word was " << codeWord << endl;
            } else {
                cout << "HANGED :(" << endl;
                cout << "The word was " << codeWord << endl;
            }
        }

        void winCheck() {
            won = true;

            for(int x = 0; x < codeWord.length(); x++) {
                if (!isWithinGuesses(codeWord[x])) {
                    won = false;
                    break;
                }
            }
        }

        void guessLetter() {
            char guess;

            cout << "Enter Guess: ";
            cin >> guess;
            guess = tolower(guess);

            while (isWithinGuesses(guess)) {
                cout << "Already tried " << guess << ", guess again: ";
                cin >> guess;
                guess = tolower(guess);
            }

            guesses[guessCount] = guess;
            guessCount++;

            if (!isWithinWord(guess)) {
                incorrectGuesses[incorrectGuessesCount] = guess;
                incorrectGuessesCount++;
                lives--;
            }   
        }

    public:
        Man(string* wordList, int wordCount) {
            srand(time(nullptr));
            int index = rand() % wordCount;
            codeWord = wordList[index];
        }

        void playRound() {
            beginMessage();

            while (!won && lives > 0) {
                printManState();
                printIncorrectGuesses();
                printWordState();

                guessLetter();

                winCheck();
            }

            if (lives == 0) {
                printManState();
            }

            endMessage(won);
        }

        void printManState() {
            switch (lives) {
                case 6:
                    cout << HANGMAN_STATES[0] << endl;
                    break;
                case 5:
                    cout << HANGMAN_STATES[1] << endl;
                    break;
                case 4:
                    cout << HANGMAN_STATES[2] << endl;
                    break;
                case 3:
                    cout << HANGMAN_STATES[3] << endl;
                    break;
                case 2:
                    cout << HANGMAN_STATES[4] << endl;
                    break;
                case 1:
                    cout << HANGMAN_STATES[5] << endl;
                    break;
                case 0:
                    cout << HANGMAN_STATES[6] << endl;
                    break;
                default:
                    cout << endl << "ERROR PRINTING GAMESTATE" << endl;
            }
        }
    
        void printWordState() {
            for (int x = 0; x < codeWord.length(); x++) {
                if (isWithinGuesses(codeWord[x])) {
                    cout << codeWord[x] << " ";
                } else {
                    cout << "? ";
                }
            }
            cout << endl;
        }

        void printIncorrectGuesses() {
            cout << "Incorrect Guesses: ";
            for (int x = 0; x < incorrectGuessesCount; x++) {
                cout << incorrectGuesses[x] << " ";
            }
            cout << endl;
        }
};

int main() {
    int wordCount = 0;
    string* wordList = readFromFile(wordCount);

    Man man1(wordList, wordCount);

    man1.playRound();

    return 0;
}

// File words into string, returns pointer / wordCount by reference
string* readFromFile(int& wordCount) {
    wordCount = 0;
    string temp;
    string* wordList = nullptr;

    ifstream file("words.txt");
    if (!file) {
        cout << "ERROR | COULD NOT OPEN FILE" << endl;
    }

    while (file >> temp) {
        wordCount++;
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