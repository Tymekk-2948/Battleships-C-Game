#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

Board::Board() : shipCount(0) {  // function that creates dots on boards
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            grid[i][j] = '.';
        }
    }
}

bool Board::placeShip(Ship* ship) {  // function used to place any ship on board
    int startX = ship->getStartX();
    int startY = ship->getStartY();
    int size = ship->getSize();
    bool horizontal = ship->isHorizontal();

    for (int i = 0; i < size; ++i) {
        int x = horizontal ? startX + i : startX;
        int y = horizontal ? startY : startY + i;

        if (x < 0 || x >= 10 || y < 0 || y >= 10 || grid[y][x] != '.') {
            return false;
        }
    }

    for (int i = -1; i <= size; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int checkX = horizontal ? startX + i : startX + j;
            int checkY = horizontal ? startY + j : startY + i;
            if (checkX >= 0 && checkX < 10 && checkY >= 0 && checkY < 10) {
                if (grid[checkY][checkX] == 'S') {
                    if (i != size && (checkX != startX || checkY != startY)) {
                        return false;
                    }
                }
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        int x = horizontal ? startX + i : startX;
        int y = horizontal ? startY : startY + i;
        grid[y][x] = 'S';
    }

    ships[shipCount++] = ship;
    return true;
}


bool Board::attack(int x, int y) {  // function that is checking if attack on other player board can happen and if the values are correct, also returns the correct comment
    if (x < 0 || x >= 10 || y < 0 || y >= 10) {
        cout << "Coordinates out of bounds!" << endl;
        return false;
    }

    if (grid[y][x] == 'O' || grid[y][x] == 'X') {
        cout << "This position has already been attacked!" << endl;
        return false;
    }

    if (grid[y][x] == 'S') {
        grid[y][x] = 'X'; 
        cout << "Hit!" << endl;

        for (int i = 0; i < shipCount; ++i) {
            Ship* ship = ships[i];
            int startX = ship->getStartX();
            int startY = ship->getStartY();
            int size = ship->getSize();
            bool horizontal = ship->isHorizontal();

            for (int j = 0; j < size; ++j) {
                int shipX = horizontal ? startX + j : startX;
                int shipY = horizontal ? startY : startY + j;
                if (shipX == x && shipY == y) {
                    ship->hit();
                    if (ship->isSunk()) {
                        cout << "You sunk a ship of size " << size << "!" << endl;
                    }
                    return true;
                }
            }
        }

        cerr << "Error: Ship segment not linked to any ship!" << endl;
        return false;
    } else {
        grid[y][x] = 'O';
        cout << "Miss!" << endl;
        return false;
    }
}

void Board::print(bool showShips) const {  // function used to print any board
    cout << "  0 1 2 3 4 5 6 7 8 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << i << " ";
        for (int j = 0; j < 10; ++j) {
            char c = grid[i][j];
            if (c == 'S' && !showShips) {
                cout << ". ";
            } else {
                cout << c << ' ';
            }
        }
        cout << endl;
    }
}

bool Board::allShipsSunk() const { // function that is checking if all ships are suked to end the game
    for (int i = 0; i < shipCount; ++i) {
        if (!ships[i]->isSunk()) { 
            return false;
        }
    }
    return true;
}

void Board::clearScreen() const { // function that first clears the terminal and then awaits confirmaton
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear"); 
    #endif

    cout << "Press ENTER when you're ready..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Board::confirmAndClear() { // function that first awaits confirmation and then clears the terminal
    cout << "Press ENTER when you're ready..." << endl;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cin.get();

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}