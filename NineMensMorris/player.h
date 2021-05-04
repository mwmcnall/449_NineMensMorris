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
    int turn = -1;
    int inMill =0;
    bool removing = false;

// methods
public:
    player(int turn_);
    void placePiece();
    void checkPhase();
    //void computerPlacePiece();

};

#endif // PLAYER_H
