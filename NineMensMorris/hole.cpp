#include "hole.h"

hole::hole()
{

}

void hole::emptyHole() {
    this->filled = 0;
}

void hole::fillHole(int player) {
    this->filled = 1;
    this->playerOwned = player;
}
