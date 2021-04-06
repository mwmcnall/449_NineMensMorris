#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "board.h"
#include "mainwindow.h"
#include "game_gui.h"
#include "player_gui.h"
#include "logwindow.h"

class game : public QObject
{
// variables
public:
    Board* b;
    player_GUI* playerOneGUI;
    player_GUI* playerTwoGUI;
    LogWindow *log = new LogWindow();
private:
    int turn = -1;
    player* playerOne;
    player* playerTwo;
    player* activePlayer;
    player_GUI* activePlayer_GUI;
    game_GUI* game_gui;
    bool playerMoving = false;

// methods
public:
    game();
    int getTurn();
    void setTurn(int _turn);
    void gameLoop();
    bool SimulateButtonPress(int x, int y);
private:
    void setActivePlayer(int turn);
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
    bool isHoleFilled(int row, int col, int playerTurn);
    // Remove Piece
    void removePiece(Hole *);
};

#endif // GAME_H
