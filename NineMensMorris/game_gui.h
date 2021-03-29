#ifndef GAME_GUI_H
#define GAME_GUI_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class game_GUI : public QObject
{
public:
    game_GUI();
    void ChoosePlayerTurnGUI();
    int getTurn();
    void setTurn(int _turn);
private:
    QWidget *w;
    int turn;

    void ChooseBlackPieces();
    void ChooseWhitePieces();
    void ChoosePlayerTurnGUIClose();
};

#endif // GAME_GUI_H
