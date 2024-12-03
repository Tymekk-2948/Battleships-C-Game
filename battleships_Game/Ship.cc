#include "Ship.h"

Ship::Ship(int size, int startX, int startY, bool horizontal)
    : size(size), startX(startX), startY(startY), horizontal(horizontal), hits(0) {}

void Ship::hit() {
    if (hits < size) {
        hits++;
    }
}

bool Ship::isSunk() const {
    return hits >= size; 
}

int Ship::getSize() const {
    return size;
}

int Ship::getStartX() const {
    return startX;
}

int Ship::getStartY() const {
    return startY;
}

bool Ship::isHorizontal() const {
    return horizontal;
}
