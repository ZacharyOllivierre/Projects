#include "hangman.h"

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
