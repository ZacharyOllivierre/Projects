#include "game.h"
#include <iostream>
#include <chrono>
#include <thread>

// Public

void Game::gameLoop() {
    int counter = 0;

    getInput();

    reset();

    while (counter < frames) {

        printBox(xScreenStartPosition, yScreenStartPosition, xScreenEndPosition, yScreenEndPosition);

        for (int x = 0; x < balls; x++) {
            
            ptrBallArray[x]->updateBall();            

            drawBall(x);
            
            if (counter % 2 == 0) {
                printStats(x);
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(waitMilliseconds));
        
        counter++;
    }

    // Delete allocated memory
    for (int x = 0; x < balls; x++) {
        delete ptrBallArray[x];
    }

    delete [] ptrBallArray;
    delete [] xVelocityStart;
    delete [] yVelocityStart;
}

void Game::reset() {
    int horizontalSpacing = 3;

    ptrBallArray = new Ball*[balls];

    for (int x = 0; x < balls; x++) {
        ptrBallArray[x] = new Ball(xScreenStartPosition + 2 + (x * horizontalSpacing), yScreenStartPosition + 1, xVelocityStart[x], yVelocityStart[x], xScreenStartPosition, yScreenStartPosition, xScreenEndPosition, yScreenEndPosition);
    }
}

// Private

void Game::drawBall(int ballNum) {
    
    clearBall(ptrBallArray[ballNum]->getXPrev(), ptrBallArray[ballNum]->getYPrev());

    printBall(ptrBallArray[ballNum]->getXPos(), ptrBallArray[ballNum]->getYPos());
}

void Game::printBall(int xPosition, int yPosition)
{
    std::cout << "\033[" << yPosition << ";" << xPosition << "H" << "*";
}

void Game::clearBall(int xPosition, int yPosition) {
    std::cout << "\033[" << yPosition << ";" << xPosition << "H" << " ";
}

// Start top left of box | end bottom right
void Game::printBox(int startX, int startY, int endX, int endY) {
    int xLength = endX - startX;
    int yLength = endY - startY;
    std::string line;

    for (int x = 0; x <= xLength; x += 1 ) {
        
        if (x == 0 || x == xLength) {
            line = "+";
        }
        else {
            line = "-";
        }

        std::cout << "\033[" + std::to_string(startY) + ";" + std::to_string(startX + x) + "H" << line;
        std::cout << "\033[" + std::to_string(endY) + ";" + std::to_string(startX + x) + "H" << line;
    }

    for (int y = 1; y < yLength; y++ ) {
        std::cout << "\033[" << (startY + y) << ";" << startX << "H" << "|";
        std::cout << "\033[" << (startY + y) << ";" << endX << "H" << "|";
    }
}

void Game::getInput() {
    int defaultValues = 0;

    // Clear and reset to Top Left
    std::cout << "\033[2J\033[H";

    std::cout << "Default Values (1 or 0): ";
    std::cin >> defaultValues;
    
    std::cout << "Enter balls: ";
    std::cin >> balls;

    xVelocityStart = new float [balls];
    yVelocityStart = new float [balls];

    if (defaultValues) {
        
        for (int x = 0; x < balls; x++) {
            xVelocityStart[x] = 5 + x * 5;
            yVelocityStart[x] = 5 + x * 5;
        }
        
        frames = 250;

        waitMilliseconds = 80;
        
        screenWidth = 150;
        screenHeight = 30;
        xScreenStartPosition = 2;
        yScreenStartPosition = 2;
    }
    else {
        for (int x = 0; x < balls; x++) {
            std::cout << "Enter x velocity for ball " << x * 5 + 5 << ": ";
            std::cin >> xVelocityStart[x];

            std::cout << "Enter y velocity for ball " << x * 5 + 5 << ": ";
            std::cin >> yVelocityStart[x];
        }

        std::cout << "Enter number of frames: ";
        std::cin >> frames;

        std::cout << "Enter milliseconds per frame: ";
        std::cin >> waitMilliseconds;

        std::cout << "Enter screen width: ";
        std::cin >> screenWidth;

        std::cout << "Enter screen height: ";
        std::cin >> screenHeight;

        std::cout << "Enter screen start position x: ";
        std::cin >> xScreenStartPosition;
        
        std::cout << "Enter screen start position y: ";
        std::cin >> yScreenStartPosition;
    }

    xScreenEndPosition = xScreenStartPosition + screenWidth;
    yScreenEndPosition = yScreenStartPosition + screenHeight;

    clearScreen();
};

void Game::clearScreen() {
    std::cout << "\033[2J\033[H";
}

void Game::printStats(int ballNum) {
    std::cout << "\033[" << yScreenEndPosition + 2 + ballNum * 2 << ";" << xScreenStartPosition << "H" << "\033[2K"
              << "Ball " << ballNum + 1 << " | " << "X Velocity: " << ptrBallArray[ballNum]->getXVelocity() 
              << " | Y Velocity: " << ptrBallArray[ballNum]->getYVelocity() << " | Y Moving: " << ptrBallArray[ballNum]->getYMoving()
              << " | X Moving: " << ptrBallArray[ballNum]->getXMoving();
}