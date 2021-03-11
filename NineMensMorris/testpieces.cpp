#include "testpieces.h"

void testPieces::init()
{

}

// NOTE: For these testing functions a 'CreateGUI' function is called
// However, the QWidget created is not assigned anywhere, meaning there is no visual element to these tests

void testPieces::testPlacePiece() {
    game *g = new game;
    g->b->CreateBoardGUI();
    // TODO: Currenty this just connects the buttson to the correct method
    // Will likely break as game is expanded
    g->gameLoop();

    g->setTurn(1);
    g->SimulateButtonPress(0, 0);

    Hole* button = &g->b->buttons[0][0];

    QCOMPARE(button->filled, true);
    QCOMPARE(button->playerOwned, 1);
}

void testPieces::testDoNOTPlacePiece() {
    game *g = new game;
    g->b->CreateBoardGUI();
    // TODO: Currenty this just connects the buttson to the correct method
    // Will likely break as game is expanded
    g->gameLoop();

    g->setTurn(1);
    g->SimulateButtonPress(0, 0);

    // Make sure Hole agreed it wasn't clicked
    QCOMPARE(g->SimulateButtonPress(0, 0), false);

    Hole* button = &g->b->buttons[0][0];

    QCOMPARE(button->filled, true);
    // Make sure ownership didn't change after being clicked a second time
    QCOMPARE(button->playerOwned, 1);
}







