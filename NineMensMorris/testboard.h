#ifndef TESTBOARD_H
#define TESTBOARD_H

#include "board.h"
#include <QtTest/QtTest>

class testBoard : public QObject
{
    Q_OBJECT

private slots:
    // setup / cleanup
    void init();
    void testBoardGUI();
};

#endif // TESTBOARD_H
