#include "hole.h"

Hole::Hole()
{

}

// Initialize with coordinates set
Hole::Hole(int row, int column) {
    this->coords.row = row;
    this->coords.column = column;
}

// Set coordinates
void Hole::setCoords(int row, int column) {
    this->coords.row = row;
    this->coords.column = column;
}


int Hole::getRow() {
    return this->coords.row;
}

int Hole::getCol() {
    return this->coords.column;
}

// Removes ownership and hides player image
void Hole::emptyHole() {
    this->filled = false;
    this->playerOwned = 0;
    this->setStyleSheet("QPushButton {background-color: transparent;border: 0px}");
}

// Claims hole for player and activates player image
void Hole::fillHole(int player) {
    this->filled = true;
    this->playerOwned = player;
    this->activateImage(player);
}

// Changes button from transparent to visible
void Hole::activateImage(int player) {

    if (player == 1) {
        this->setStyleSheet("border-image: url(:/img/img/black dot.jpg) 0 0 0 0 stretch stretch");

    } else if (player == 2) {
        this->setStyleSheet("border-image: url(:/img/img/white dot.jpg) 0 0 0 0 stretch stretch");
    }

}























