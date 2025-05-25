#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <iomanip>

const int GAME_WIDTH = 60;

string* readFromFile(int& wordCount);
void printLines(int num);
bool playAgain();
void printCentered(const string& text, int extra = 0, int width = GAME_WIDTH); // Extra = additive length of text
void printCenteredMultiline(const string& text, int width = GAME_WIDTH);

class Man;

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