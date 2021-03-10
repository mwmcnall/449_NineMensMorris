#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class game : public QObject
{
// variables
public:
    int turn;
private:
    QWidget *w;

// methods
public:
    game();
    void ChoosePlayerTurnGUI();
    int getTurn();
    void setTurn(int _turn);
private:
    void ChooseBlackPieces();
    void ChooseWhitePieces();
    void ChoosePlayerTurnGUIClose();
    void gameLoop();
};

#endif // GAME_H
