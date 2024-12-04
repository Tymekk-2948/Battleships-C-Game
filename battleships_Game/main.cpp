#include <iostream>
#include "Player.h"
#include <cstdlib>
#include <limits>
using namespace std;

int main() {
    Player player1, player2;

    cout << "Player 1, place your ships:" << endl;
    player1.placeFleet();
    player1.board.clearScreen();

    cout << "Player 2, place your ships:" << endl;
    player2.placeFleet();
    player1.board.clearScreen();

    bool gameOver = false;
    while (!gameOver) {
        cout << "Player 1's turn:" << endl;
        if (player1.takeShot(player2)) {
            if (player2.board.allShipsSunk()) {
                cout << "Player 1 wins!" << endl;
                gameOver = true;
            }
        }
        if (!gameOver) {
            player1.board.confirmAndClear();
            player1.board.clearScreen();
        }

        if (gameOver) {
            player1.board.confirmAndClear();
            break;
        }

        cout << "Player 2's turn:" << endl;
        if (player2.takeShot(player1)) {
            if (player1.board.allShipsSunk()) {
                cout << "Player 2 wins!" << endl;
                gameOver = true;
            }
        }
        if (!gameOver) {
            player2.board.confirmAndClear();
            player1.board.clearScreen();
        }
    }

    return 0;
}
