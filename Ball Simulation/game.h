#include "ball.h"

class Game {
    
public:
    
    void gameLoop();
    void drawBall(int ballNum);
    void reset();

private:
    
    int waitMilliseconds;
    int frames;
    
    Ball** ptrBallArray = nullptr;
    int balls;

    float* xVelocityStart = nullptr;
    float* yVelocityStart = nullptr;
    
    int screenWidth;
    int screenHeight;

    int xScreenStartPosition;
    int yScreenStartPosition;

    int xScreenEndPosition;
    int yScreenEndPosition;

    void printBall(int xPosition, int yPosition);
    void clearBall(int xPosition, int yPosition);
    void printBox(int startX, int startY, int endX, int endY);
    void getInput();
    void clearScreen();
    void printStats(int ballNum);
};