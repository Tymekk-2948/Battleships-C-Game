#include "Player.h"
#include <limits>
#include <iostream>
using namespace std;

int getValidatedInput(const string& prompt, int minValue, int maxValue) { // function that checks whether the player enters the correct value
    int input;
    while (true) {
        cout << prompt;
        cin >> input;

        
        if (cin.fail() || input < minValue || input > maxValue) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Incorrect! Set correct value " << minValue << " - " << maxValue << endl;;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return input;
        }
    }
}

void Player::placeFleet() { // function used to place all ships
    int sizes[] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    for (int i = 0; i < 10; ++i) {
        int x, y;
        bool horizontal;

        cout << "Your Board:" << endl;
        board.print(true); 

        cout << "Set the ship that has lenght of: " << sizes[i] << endl;

        x = getValidatedInput("Set coordinate X (0-9): ", 0, 9);
        y = getValidatedInput("Set coordinate Y (0-9): ", 0, 9);
        horizontal = getValidatedInput("Set orientation (0 = vertically, 1 = horizontally): ", 0, 1);

       
        Ship* ship = new Ship(sizes[i], x, y, horizontal);
        while (!board.placeShip(ship)) {
            cout << "You can't place ship there! Try again. " << endl;
            delete ship;

            x = getValidatedInput("Set coordinate X (0-9): ", 0, 9);
            y = getValidatedInput("Set coordinate Y (0-9): ", 0, 9);
            horizontal = getValidatedInput("Set orientation (0 = vertically, 1 = horizontally): ", 0, 1);

            ship = new Ship(sizes[i], x, y, horizontal);
        }
    }
}

bool Player::takeShot(Player& opponent) { // function that displays rounds
    int x, y;
    cout << "Your Board: " << endl;
    board.print(true);
    cout << "Opponent's Board (Your hits): "<< endl;
    opponent.board.print(false);

    cout << "Set the coordinates of your hit (x y): "<< endl;
    cin >> x >> y;

    return opponent.board.attack(x, y);
}
