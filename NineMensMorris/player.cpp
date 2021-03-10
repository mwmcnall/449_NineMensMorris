#include "player.h"

player::player()
{

}

void player::placePiece() {
    //if (valid move) TODO: write check for valid move
    this->numPieces -= 1;
}

void player::checkFly() {
    if (this->numPieces == 3) {
        this->flyStatus = true;
    }
}
