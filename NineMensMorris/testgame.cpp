#include "testgame.h"
#include "game.h"
#include <QThread>

void testGame::init()
{

}

void testGame::testChooseFirstTurn()
{
    char testTurn = 'B';

    // Create game
    game g;

    g.setTurn(testTurn);
    QCOMPARE(testTurn, g.getTurn());
}
