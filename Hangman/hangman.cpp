#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int GAME_WIDTH = 60;
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
bool playAgain();
void printCentered(const string& text, int extra = 0, int width = GAME_WIDTH); // Extra = additive length of text
void printCenteredMultiline(const string& text, int width = GAME_WIDTH);

class Man {
    private:
        string codeWord;
        int lives = 6;
        bool won = false;

        char guesses[26];
        int guessCount = 0;
        char incorrectGuesses[26];
        int incorrectGuessesCount = 0;

        const int width = GAME_WIDTH;

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
            printCentered("Welcome to Hangman");
            cout << endl;
            printLines(width);
            cout << endl;
        }

        void endMessage(bool hasWon) {
            string message;
            cout << "\n\n\n";

            if (hasWon) {
                printLines(width);
                cout << "\n";
                message = "You won with " + to_string(guessCount) + " guesses and " + to_string(lives) + " body parts left!";
                printCentered(message, guessCount / 10);
                cout << "\n";

            } else {
                cout << "\n";
                printCentered("HANGED :(");
                cout << "\n";
            }

            message = "The word was ";
            printCentered(message);
            cout << "\n";
            printWordState();
            cout << "\n";
        }

        void winCheck() {
            won = true;

            for(int x = 0; x < codeWord.length(); x++) {
                if (!isWithinGuesses(codeWord[x])) {
                    won = false;
                    break;
                }
            }
            // cout << "winCheck sets won = " << won << endl;
        }

        void guessLetter() {
            string input;
            char guess;
            bool valid = false;

            while (!valid) {
                printCentered("Enter Guess: ");
                getline(cin, input);

                if (input.length() == 1 && isalpha(input[0])) {
                    guess = tolower(input[0]);

                    if (!isWithinGuesses(guess)) {
                        valid = true;
                    } else {
                        string message = "Already tried " + string(1, guess) + ", guess again.";
                        printCentered(message);
                        cout << "\n";
                    }

                } else {
                    printCentered("Please enter a single letter.");
                    cout << "\n";
                }
            }

            guesses[guessCount++] = guess;
            
            if (!isWithinWord(guess)) {
                incorrectGuesses[incorrectGuessesCount++] = guess;
                lives--;
            }
            cout << "\n\n";
        }

        void printManState() {
            switch (lives) {
                case 6:
                    printCenteredMultiline(HANGMAN_STATES[0]);
                    cout << endl;
                    break;
                case 5:
                    printCenteredMultiline(HANGMAN_STATES[1]);
                    cout << endl;
                    break;
                case 4:
                    printCenteredMultiline(HANGMAN_STATES[2]);
                    cout << endl;
                    break;
                case 3:
                    printCenteredMultiline(HANGMAN_STATES[3]);
                    cout << endl;
                    break;
                case 2:
                    printCenteredMultiline(HANGMAN_STATES[4]);
                    cout << endl;
                    break;
                case 1:
                    printCenteredMultiline(HANGMAN_STATES[5]);
                    cout << endl;
                    break;
                case 0:
                    printCenteredMultiline(HANGMAN_STATES[6]);
                    cout << endl;
                    break;
                default:
                    cout << endl << "ERROR | PRINTING GAMESTATE" << endl;
            }
            printLines(width);
        }
    
        void printWordState() {
            string message = "";
            for (int x = 0; x < codeWord.length(); x++) {
                if (isWithinGuesses(codeWord[x])) {
                    message += string(1, codeWord[x]) + " ";
                } else {
                    message += "_ ";
                }
            }
            printCentered(message);
            cout << "\n\n";
        }

        void printIncorrectGuesses() {
            cout << "\n";
            printCentered("Incorrect Guesses: ", incorrectGuessesCount * 2);

            for (int x = 0; x < incorrectGuessesCount; x++) {
                cout << incorrectGuesses[x] << " ";
            }
            cout << endl << endl;
        }

        void generateCodeWord(string* wordList, int wordCount) {
            srand(time(nullptr));
            int index = rand() % wordCount;
            codeWord = wordList[index];
        }

    public:
        void resetGame(string* wordList, int wordCount) {
            lives = 6;
            won = false;
            guessCount = 0;
            incorrectGuessesCount = 0;
            
            for (int x = 0; x < 26; x++) {
                guesses[x] = '\0';
                incorrectGuesses[x] = '\0';
            }

            generateCodeWord(wordList, wordCount);
        }

        void playRound() {
            beginMessage();
            cout << "Codeword " << codeWord << endl;

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

        
};

int main() {
    int wordCount = 0;
    string* wordList = readFromFile(wordCount);
    bool playing = true;
    Man man1;

    while(playing) {
        man1.resetGame(wordList, wordCount);
        man1.playRound();

        playing = playAgain();
    }

    delete [] wordList;
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