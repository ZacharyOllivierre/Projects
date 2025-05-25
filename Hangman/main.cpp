#include "hangman.hpp"
#include "game.hpp"

int main() {
    int wordCount = 0;
    string* wordList = readFromFile(wordCount);
    bool playing = true;
    Game game1;

    // Game loop
    while(playing) {
        game1.resetGame(wordList, wordCount);
        game1.playRound();

        playing = playAgain();
    }

    // Free memory
    delete [] wordList;
    return 0;
}
