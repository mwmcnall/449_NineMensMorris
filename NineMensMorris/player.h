#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class player : QObject
{
// variables
public:
    int playerPhase = 1;
    int numPieces = 9;
    int totalPieces = 9;
    bool flyStatus = false;

// methods
public:
    player();
    void placePiece();
    void checkPhase();

};

#endif // PLAYER_H
