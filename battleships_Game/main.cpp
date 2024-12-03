#include <iostream>
#include "Player.h"
#include <cstdlib>
#include <limits>
using namespace std;

int main() {
    Player player1, player2;
    Board board;

        cout << "Player 1 place your ships" <<endl;
    player1.placeFleet();
    board.clearScreen();

        cout << "Player 2 place your ships"<< endl;
    player2.placeFleet();
    board.clearScreen();

    bool gameOver = false;
    while (!gameOver) {
        cout << "Player 1 turn: "<< endl;
        if (player1.takeShot(player2)) {
            if (player2.board.allShipsSunk()) {
                cout << "Player 1 wins!"<< endl;;
                gameOver = true;
            }
            board.confirmAndClear();
            board.clearScreen();
        }

        if (!gameOver) {
            cout << "Player 2 turn: " << endl;
            if (player2.takeShot(player1)) {
                if (player1.board.allShipsSunk()) {
                    cout << "Player 2 wins!"<< endl;
                    gameOver = true;
                }
            }
            board.confirmAndClear();
            board.clearScreen();
        }
    }

    return 0;
}
