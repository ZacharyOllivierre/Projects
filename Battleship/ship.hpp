#pragma once
#include <string>

class Ship {
private:
    static const int MAXSIZE = 5;
    
    std::string shipName;

    // Coordinates saved in encoded integer notation
    int coordinate[MAXSIZE];
    int hits[MAXSIZE];

    int shipSize;
    int hitCount = 0;
    bool sunk = false;

public:
    // Establishes ship size and name, fills data arrays with -1
    Ship(int size, std::string name);

    // Set ship coordinates, expects array of integer notation coordinates and error flag size
    bool setCoordinates(int* coordinatePtr, int arraySize);

    // Checks if this ship contains integer notation coordinate
    bool containsCoordinate(int index);

    // Returns size of ship
    int getSize();

    // Adds index to hit list and increments hitCount
    void markHit(int index);

    // Checks wether hitCount is less than size of ship
    bool isSunk();

    // Resets coordinates, hits, hitCount, and sunk
    void reset();
};