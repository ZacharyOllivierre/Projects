#include "hangman.hpp"
#include "game.hpp"
#include <string>
using namespace std;

// Constructor
Game::Game() {
    lives = 6;
    won = false;
    guessCount = 0;
    incorrectGuessesCount = 0;

    for (int x = 0; x < 26; x++) {
        guesses[x] = '\0';
        incorrectGuesses[x] = '\0';
    }
}

// Public
// Reset Game to default values | Sets arrays to null
void Game::resetGame(string* wordList, int wordCount) {
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

// Main Round function | Calls other neccessary functions for drawing and processing
void Game::playRound() {
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

// Private
// Returns whether a letter is within player guesses
bool Game::isWithinGuesses(char letter) {
    for (int x = 0; x < guessCount; x++) {
        if (letter == guesses[x]) {
            return true;
        }
    }
    return false;
}

// Returns whether a letter is within game word
bool Game::isWithinWord(char letter) {
    for (int x = 0; x < codeWord.length(); x++) {
        if (letter == codeWord[x]) {
            return true;
        }
    }
    return false;
}

// Top title header
void Game::beginMessage() {
    printCentered("Welcome to Hangman");
    cout << endl;
    printLines(width);
    cout << endl;
}

// Outputs Score and Word dependent on bool hasWon
void Game::endMessage(bool hasWon) {
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

    message = "The word was " + codeWord;
    printCentered(message);
    cout << "\n";
}

// Check if all letters in codeWord are within player guesses
void Game::winCheck() {
    won = true;
    for(int x = 0; x < codeWord.length(); x++) {
        if (!isWithinGuesses(codeWord[x])) {
            won = false;
            break;
        }
    }
}

// Guessing functionality | Decrements lives | Adds to guesses | Full input validation
void Game::guessLetter() {
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

// Print Galley dependent on state (inverse lives)
void Game::printManState() {
    printCenteredMultiline(HANGMAN_STATES[6 - lives]);
    cout << endl;
    printLines(width);
}

// Print state of word to guess | Places blank if letter is not within guesses
void Game::printWordState() {
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

// Prints incorrect guesses | predominant use of "extra" parameter in single line center printing
void Game::printIncorrectGuesses() {
    cout << "\n";
    printCentered("Incorrect Guesses: ", incorrectGuessesCount * 2);
    for (int x = 0; x < incorrectGuessesCount; x++) {
        cout << incorrectGuesses[x] << " ";
    }
    cout << endl << endl;
}

// Chooses codeword from wordList psuedorandomly
void Game::generateCodeWord(string* wordList, int wordCount) {
    srand(time(nullptr));
    int index = rand() % wordCount;
    codeWord = wordList[index];
}