#include "button.h"

//virtual ~Button() = default;

Button::Button()
{
    //connect(this, SIGNAL(clicked()), this, SLOT(fillHole()));
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

void Button::activateImage(int player) {
    if (player == 1) {
        this->setIcon(QIcon(":/img/img/black dot.jpg"));

    } else if (player == 2) {
        this->setIcon(QIcon(":/img/img/white dot.jpg"));
    }

    //this->setIconSize(QSize(35,35));
}
























