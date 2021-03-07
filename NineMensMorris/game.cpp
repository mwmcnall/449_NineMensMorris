#include "game.h"

game::game()
{

}

void game::setTurn(char _turn) {
    this->turn = _turn;
}

char game::getTurn() {
    return this->turn;
}
