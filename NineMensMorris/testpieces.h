#ifndef TESTPIECES_H
#define TESTPIECES_H

#include "game.h"
#include <QtTest/QtTest>

class testPieces : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void init();
    void testPlacePiece();
    void testDoNOTPlacePiece();
};

#endif // TESTPIECES_H
