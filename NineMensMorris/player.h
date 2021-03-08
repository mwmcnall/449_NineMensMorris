#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class player : QObject
{
// variables
public:
    int numPieces = 9;
    bool flyStatus = false;

// methods
public:
    player();
    void placePiece();
    void checkFly();
};

#endif // PLAYER_H
