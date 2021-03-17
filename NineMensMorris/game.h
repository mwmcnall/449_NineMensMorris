#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

#include "player.h"
#include "board.h"
#include "mainwindow.h"

class game : public QObject
{
// variables
public:
    int turn = 1;
    Board* b;
private:
    QWidget *w;
    player* playerOne;
    player* playerTwo;

// methods
public:
    game();
    void ChoosePlayerTurnGUI();
    int getTurn();
    void setTurn(int _turn);
    void gameLoop();
    bool SimulateButtonPress(int x, int y);
private:
    void ChooseBlackPieces();
    void ChooseWhitePieces();
    void ChoosePlayerTurnGUIClose();
    void ButtonPress();
    void ConnectButtons();
    void incrementTurn();
    bool checkMill(int x, int y);
};

#endif // GAME_H
