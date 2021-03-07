#ifndef TESTGAME_H
#define TESTGAME_H

#include <QtTest/QtTest>

class testGame : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    // setup / cleanup
    void init();
    void testChooseFirstTurn();
};

#endif // TESTGAME_H
