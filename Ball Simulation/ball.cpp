#include "ball.h"
#include <cmath>
#include <iostream>

// Public

// Ball constructor | must start within screen | Set Start velocity | Saves local copy of screen coords
Ball::Ball(int xPosition, int yPosition, int xVelocity, int yVelocity, int xScreenStart, int yScreenStart, int xScreenEnd, int yScreenEnd) {

    xPos = xPosition;
    yPos = yPosition;

    xVel = xVelocity;
    yVel = yVelocity;

    xScreenS = xScreenStart;
    yScreenS = yScreenStart;
    xScreenE = xScreenEnd;
    yScreenE = yScreenEnd;
}

void Ball::updateBall() {

    yPrev = yPos;
    xPrev = xPos;

    if (std::abs(xVel) < 0.09) {
        xVel = 0;
        xMoving = false;

    }
    else {
        xMoving = true;
    }

    if (yMoving) {
        yVel += gravity;
    }

    yPos += yVel * yScale;
    xPos += xVel * xScale;


    // Check Left Wall
    if (xPos <= xScreenS) {

        xVel = -bounceCoefficient(xVel);
        yVel = frictionCoefficient(yVel);

        xPos = xScreenS + 1;
    }

    // Check Right Wall
    if (xPos >= xScreenE) {

        xVel = -bounceCoefficient(xVel);
        yVel = frictionCoefficient(yVel);

        xPos = xScreenE - 1;
    }

    // Check Top Wall
    if (yPos <= yScreenS) {
        
        yVel = -bounceCoefficient(yVel);
        xVel = frictionCoefficient(xVel);

        yPos = yScreenS + 1;
    }

    // Check Bottom Wall
    if (yPos >= yScreenE) {

        yVel = -bounceCoefficient(yVel);
        xVel = frictionCoefficient(xVel);

        yPos = yScreenE - 1;
    }

    // If rolling
    if (!yMoving) {
        xVel = frictionCoefficient(xVel);
    }

    if (static_cast<int>(xPrev) == static_cast<int>(xPos)) {
        yVel = 0;
        yMoving = false;

    } else {
        yMoving = true;
    }
}

int Ball::getXPos() {
    return static_cast<int>(xPos);
}

int Ball::getYPos() {
    return static_cast<int>(yPos);
}

int Ball::getXPrev() {
    return static_cast<int>(xPrev);
}

int Ball::getYPrev() {
    return static_cast<int>(yPrev);
}

double Ball::getXVelocity() {
    return xVel;
}

double Ball::getYVelocity() {
    return yVel;
}

bool Ball::getXMoving() {
    return xMoving;
}

bool Ball::getYMoving() {
    return yMoving;
}

// Private

// Returns velocity after bounce 79%
double Ball::bounceCoefficient(double velocity) {
    return velocity * (7.9 / 10.0);
}

double Ball::frictionCoefficient(double velocity) {
    return velocity * (9.5 / 10.0);
}
