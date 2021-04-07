#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "hole.h"
#include "game.h"

class tests : public QObject
{
    Q_OBJECT

public:
    tests();
    ~tests();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testPlacePiece();
    void testDoNOTPlacePiece1();
    void testDoNOTPlacePiece2();
    void testChooseFirstTurn1();
    void testChooseFirstTurn2();
    void testMillHorizontal1();
    void testMillHorizontal2();
    void testMillHorizontal3();
    void testMillVertical1();
    void testMillVertical2();
    void testMillVertical3();
};

tests::tests()
{

}

tests::~tests()
{

}


void tests::initTestCase()
{

}

void tests::cleanupTestCase()
{

}

// AC - 3.1
// Successfully placing a piece
void tests::testPlacePiece()
{
    game *g = new game;
    g->b->CreateBoardGUI();
    g->ConnectButtons();

    g->setTurn(1);
    g->SimulateButtonPress(0, 0);

    Hole* button = g->getHole(0, 0);
    g->setTurn(1);
    player* p = g->getActivePlayer();

    QCOMPARE(button->filled, true);
    QCOMPARE(button->playerOwned, 1);
    QCOMPARE(p->numPieces, 8);
}

// AC - 3.2
// Space is already filled by another player
void tests::testDoNOTPlacePiece1() {
    game *g = new game;
    g->b->CreateBoardGUI();
    g->ConnectButtons();

    g->setTurn(1);
    // Click the same button twice
    g->SimulateButtonPress(0, 0);
    g->SimulateButtonPress(0, 0);

    Hole* button = g->getHole(0, 0);
    g->setTurn(2);
    player* p = g->getActivePlayer();

    // Make sure the button is filled
    QCOMPARE(button->filled, true);
    // Make sure ownership didn't change after being clicked a second time
    QCOMPARE(button->playerOwned, 1);
    QCOMPARE(p->numPieces, 9);
}

// AC - 3.3
// Player has no pieces left to place
void tests::testDoNOTPlacePiece2() {
    game *g = new game;
    g->b->CreateBoardGUI();
    g->ConnectButtons();

    g->setTurn(1);
    player* p = g->getActivePlayer();

    // Careful placement to avoid mills!
    g->setTurn(1);
    g->SimulateButtonPress(3, 0);
    g->setTurn(1);
    g->SimulateButtonPress(3, 1);
    g->setTurn(1);
    g->SimulateButtonPress(0, 0);
    g->setTurn(1);
    g->SimulateButtonPress(3, 4);
    g->setTurn(1);
    g->SimulateButtonPress(3, 5);
    g->setTurn(1);
    g->SimulateButtonPress(6, 6);
    g->setTurn(1);
    g->SimulateButtonPress(1, 1);
    g->setTurn(1);
    g->SimulateButtonPress(0, 3);
    g->setTurn(1);
    g->SimulateButtonPress(6, 3);

    g->setTurn(1);
    g->SimulateButtonPress(1, 3);

    Hole* button = g->getHole(1, 3);


    // Make sure the button is NOT filled
    QCOMPARE(button->filled, false);
    QCOMPARE(p->numPieces, 0);
}


// AC - 1.1
// Choosing black as the starting color
void tests::testChooseFirstTurn1()
{
    int testTurn = 1;

    game *g = new game;

    g->setTurn(testTurn);
    player* p = g->getActivePlayer();
    QCOMPARE(testTurn, g->getTurn());
    QCOMPARE(p->turn, 1);
}

// AC - 1.2
// Choosing white as the starting color
void tests::testChooseFirstTurn2()
{
    int testTurn = 2;

    game *g = new game;

    g->setTurn(testTurn);
    player* p = g->getActivePlayer();
    QCOMPARE(testTurn, g->getTurn());
    QCOMPARE(p->turn, 2);
}


// AC - 8.1
// Successful horizontal mill detected
void tests::testMillHorizontal1() {
    game *g = new game;
    g->b->CreateBoardGUI();
    g->ConnectButtons();
    // Make sure all moves are by same player
    g->setTurn(1);
    g->SimulateButtonPress(0, 0);
    g->setTurn(1);
    g->SimulateButtonPress(3, 0);
    g->setTurn(1);
    g->SimulateButtonPress(6, 0);
    g->setTurn(1);
    player* p = g->getActivePlayer();

    // Does player think they got a mill?
    QCOMPARE(p->inMill, true);
}

// AC - 8.3
// Horizontal mill NOT detected
// Because of different player owning the pieces
void tests::testMillHorizontal2() {
    game *g = new game;
    g->b->CreateBoardGUI();
    g->ConnectButtons();
    // Make sure all moves are by same player
    g->setTurn(1);
    g->SimulateButtonPress(0, 0);
    g->setTurn(2);
    g->SimulateButtonPress(3, 0);
    g->setTurn(1);
    g->SimulateButtonPress(6, 0);
    g->setTurn(1);
    player* p = g->getActivePlayer();

    // Does player think they got a mill?
    QCOMPARE(p->inMill, false);
}

// AC - 8.4
// Horizontal mill NOT detected
// Because three pieces not placed
void tests::testMillHorizontal3() {
    game *g = new game;
    g->b->CreateBoardGUI();
    g->ConnectButtons();
    // Make sure all moves are by same player
    g->setTurn(1);
    g->SimulateButtonPress(0, 0);
    g->setTurn(1);
    g->SimulateButtonPress(3, 0);
    g->setTurn(1);
    player* p = g->getActivePlayer();

    // Does player think they got a mill?
    QCOMPARE(p->inMill, false);
}

// AC - 8.2
// Successful vertical mill detected
void tests::testMillVertical1() {
    game *g = new game;
    g->b->CreateBoardGUI();
    g->ConnectButtons();
    // Make sure all moves are by same player
    g->setTurn(1);
    g->SimulateButtonPress(0, 0);
    g->setTurn(1);
    g->SimulateButtonPress(0, 3);
    g->setTurn(1);
    g->SimulateButtonPress(0, 6);
    g->setTurn(1);
    player* p = g->getActivePlayer();

    // Does player think they got a mill?
    QCOMPARE(p->inMill, true);
}

// AC - 8.5
// Vertical mill NOT detected
// Because three pieces not placed
void tests::testMillVertical2() {
    game *g = new game;
    g->b->CreateBoardGUI();
    g->ConnectButtons();
    // Make sure all moves are by same player
    g->setTurn(1);
    g->SimulateButtonPress(0, 0);
    g->setTurn(2);
    g->SimulateButtonPress(0, 3);
    g->setTurn(1);
    g->SimulateButtonPress(0, 6);
    g->setTurn(1);
    player* p = g->getActivePlayer();

    // Does player think they got a mill?
    QCOMPARE(p->inMill, false);
}

// AC - 8.6
// Vertical mill NOT detected
// Because three pieces not placed
void tests::testMillVertical3() {
    game *g = new game;
    g->b->CreateBoardGUI();
    g->ConnectButtons();
    // Make sure all moves are by same player
    g->setTurn(1);
    g->SimulateButtonPress(0, 0);
    g->setTurn(1);
    g->SimulateButtonPress(0, 3);
    g->setTurn(1);
    player* p = g->getActivePlayer();

    // Does player think they got a mill?
    QCOMPARE(p->inMill, false);
}


//Test Remove

QTEST_MAIN(tests)
#include "tst_tests.moc"
