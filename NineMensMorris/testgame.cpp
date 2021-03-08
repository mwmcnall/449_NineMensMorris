#include "testgame.h"
#include <QThread>

void testGame::init()
{

}

void testGame::testChooseFirstTurn()
{
    char testTurn = 'B';

    game *g = new game;

    g->setTurn(testTurn);
    QCOMPARE(testTurn, g->getTurn());
}

void testGame::testChoosePlayerTurnGUI() {

    game *g = new game;

    g->ChoosePlayerTurnGUI();

    // GUI disappears too quickly w/out a sleep command
    QThread::sleep(4);
}
