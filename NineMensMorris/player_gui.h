#ifndef PLAYER_GUI_H
#define PLAYER_GUI_H

#include <QObject>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>

class player_GUI : public QWidget
{
public:
    QWidget *w;
    QLabel *pieces;
    player_GUI();
    QWidget* CreatePlayerGUI(int player_color);
    void UpdatePlayerGUI(int numPieces);
};

#endif // PLAYER_GUI_H
