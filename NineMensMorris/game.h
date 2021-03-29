#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "board.h"
#include "mainwindow.h"
#include "game_gui.h"
#include "player_gui.h"

class game : public QObject
{
// variables
public:
    Board* b;
private:
    int turn = -1;
    player* playerOne;
    player* playerTwo;
    game_GUI* game_gui;

// methods
public:
    game();
    int getTurn();
    void setTurn(int _turn);
    void gameLoop();
    bool SimulateButtonPress(int x, int y);
private:
    void ButtonPress();
    void ConnectButtons();
    void incrementTurn();
    // Mill stuff
    bool checkMill(Hole *);
    bool checkVerticalMill(Hole *);
    bool checkHorizontalMill(Hole *);
    // Is valid checks
    bool isValidHoleMoveUp(int, int);
    bool isValidHoleMoveDown(int, int);
    bool isValidHoleMoveLeft(int, int);
    bool isValidHoleMoveRight(int, int);
    bool isHoleFilled(int row, int col);
};

#endif // GAME_H
