#ifndef BOARD_H
#define BOARD_H

#include "Ship.h"

class Board {
public:
    Board();
    bool placeShip(Ship* ship);
    bool attack(int x, int y);
    void print(bool showShips) const; 
    bool allShipsSunk() const;
    void clearScreen() const;
    void confirmAndClear();

private:
    char grid[10][10];
    Ship* ships[10];
    int shipCount;
};

#endif
