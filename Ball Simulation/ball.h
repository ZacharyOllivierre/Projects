class Ball {
public:
    Ball(int xPosition, int yPosition, int xVelocity, int yVelocity, int xScreenStart, int yScreenStart, int xScreenEnd, int yScreenEnd);
    
    void updateBall();
    int getXPos();
    int getYPos();
    int getXPrev();
    int getYPrev();
    double getXVelocity();
    double getYVelocity();
    bool getXMoving();
    bool getYMoving();
    
private:   
    const float gravity = 1;

    // Dampens y axis output to make up for difference in field width and height
    const float yScale = 1.4;
    const float xScale = 3;

    int xScreenS;
    int yScreenS;
    int xScreenE;
    int yScreenE;

    float xPos;
    float yPos;

    float xPrev;
    float yPrev;

    double xVel;
    double yVel;

    bool yMoving = true;
    bool xMoving = true;

    double bounceCoefficient(double velocity); 
    double frictionCoefficient(double velocity);
};

    

