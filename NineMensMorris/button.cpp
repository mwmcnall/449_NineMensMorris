#include "button.h"

Button::Button()
{

}

Button::Button(int row, int column) {
    this->coords.row = row;
    this->coords.column = column;
}

void Button::setCoords(int row, int column) {
    this->coords.row = row;
    this->coords.column = column;
}


int Button::getRow() {
    return this->coords.row;
}

int Button::getCol() {
    return this->coords.column;
}

void Button::emptyHole() {
    this->filled = 0;
}

void Button::fillHole(int player) {
    this->filled = 1;
    this->playerOwned = player;
}


