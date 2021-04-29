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
    if (numPieces == 0){
        playerPhase = 2;
    }
    if (this->totalPieces == 3) {
        playerPhase = 3;
    }
}

void player::computerPlacePiece(){

}
