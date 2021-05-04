#include "player.h"

player::player(int turn_)
{
    this->turn = turn_;
}

void player::placePiece() {
    //if (valid move) TODO: write check for valid move
    this->numPieces -= 1;
}

void player::checkPhase() {
    if (this->numPieces == 0){
        this->playerPhase = 2;
    }
    if (this->totalPieces == 3) {
        this->playerPhase = 3;
    }
}

//void player::computerPlacePiece(){

//}
