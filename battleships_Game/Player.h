#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

class Player {
public:
    Board board;
    void placeFleet();
    bool takeShot(Player& opponent);
};

#endif
