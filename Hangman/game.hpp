#pragma once
#include <string>

class Game {
private:
    std::string codeWord;
    int lives;
    bool won;

    char guesses[26];
    int guessCount;
    char incorrectGuesses[26];
    int incorrectGuessesCount;

    const int width = GAME_WIDTH;

    bool isWithinGuesses(char letter);
    bool isWithinWord(char letter);
    void beginMessage();
    void endMessage(bool hasWon);
    void winCheck();
    void guessLetter();
    void printManState();
    void printWordState();
    void printIncorrectGuesses();
    void generateCodeWord(std::string* wordList, int wordCount);

public:
    Game();
    void resetGame(std::string* wordList, int wordCount);
    void playRound();
};