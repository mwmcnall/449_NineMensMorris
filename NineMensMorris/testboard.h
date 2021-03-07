#ifndef TESTBOARD_H
#define TESTBOARD_H

#include "board.h"
#include <QtTest/QtTest>

class testBoard : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    // setup / cleanup
    void init();
    void testBoardGUI();
};

#endif // TESTBOARD_H
