#ifndef TESTGAME_H
#define TESTGAME_H

#include <QtTest/QtTest>
#include "game.h"

class testGame : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    // setup / cleanup
    void init();
    void testChooseFirstTurn();
    void testChoosePlayerTurnGUI();
};

#endif // TESTGAME_H
