#include "ship.hpp"
#include "util.hpp"
#include <string>
#include <iostream>

// Private

// Public
Ship::Ship(int size, std::string name) {
    shipSize = size;
    shipName = name;

    for (int x = 0; x < MAXSIZE; x++) {
        coordinate[x] = -1;
        hits[x] = -1;
    }
}

bool Ship::setCoordinates(int* coordinatePtr, int arraySize) {
    // Check that array size and established ship size are equivalent
    if (arraySize != shipSize) {
        std::cerr << "ERROR | Ship size does not match coordinate array size";
        return false;
    }

    for (int x = 0; x < shipSize; x++) {
        coordinate[x] = coordinatePtr[x];
    }
    return true;
}

bool Ship::containsCoordinate(int index) {
    for (int x = 0; x < shipSize; x++) {
        if (coordinate[x] == index) {
            return true;
        }
    }
    return false;
}

int Ship::getSize() {
    return shipSize;
}

void Ship::markHit(int index) {
    hits[hitCount] = index;
    hitCount++;
}

bool Ship::isSunk() {
    if (hitCount < shipSize) {
        return false;
    }
    
    sunk = true;
    return true;
}

void Ship::reset() {
    for (int x = 0; x < MAXSIZE; x++) {
        coordinate[x] = -1;
        hits[x] = -1;
    }

    hitCount = 0;
    sunk = false;
}

