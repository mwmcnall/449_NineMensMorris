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
    char turn;
private:
    QWidget *w;

// methods
public:
    game();
    void ChoosePlayerTurnGUI();
    char getTurn();
    void setTurn(char _turn);
private:
    void ChooseBlackPieces();
    void ChooseWhitePieces();
    void ChoosePlayerTurnGUIClose();
};

#endif // GAME_H
