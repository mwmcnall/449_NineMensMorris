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

// Helper function
private:
    void gameMoveState(game *);
    void gameFlyState(game *);
    game* setupGame();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testPlacePiece();
    void testDoNOTPlacePiece1();
    void testDoNOTPlacePiece2();
    void testChooseFirstTurn1();
    void testChooseFirstTurn2();
    // Mill Check tests
    void testMillHorizontal1();
    void testMillHorizontal2();
    void testMillHorizontal3();
    void testMillVertical1();
    void testMillVertical2();
    void testMillVertical3();
    // Move Tests
    void testNoValidMove();
    void testOneValidMove();
    void testTwoValidMoves();
    void testThreeValidMoves();
    void testValidMoveOnlyUp();
    void testValidMoveOnlyDown();
    void testValidMoveOnlyLeft();
    void testValidMoveOnlyRight();
    void testClickValidMove();
    void testClickInvalidMove();
    void testMoveMillRemove();
    void testClickInvalidMoveFar();
    // Fly Tests
    void testFlyPiece();
    void testInvalidFlyPiece();
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

game* tests::setupGame() {
    game *g = new game(true);
    g->b->CreateBoardGUI();
    g->ConnectButtons();

    return g;
}

// AC - 3.1
// Successfully placing a piece
void tests::testPlacePiece()
{
    game *g = setupGame();

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
    game *g = setupGame();

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
    game *g = setupGame();

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

    game *g = setupGame();

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

    game *g = setupGame();

    g->setTurn(testTurn);
    player* p = g->getActivePlayer();
    QCOMPARE(testTurn, g->getTurn());
    QCOMPARE(p->turn, 2);
}


// AC - 8.1
// Successful horizontal mill detected
void tests::testMillHorizontal1() {
    game *g = setupGame();
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
    game *g = setupGame();
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
    game *g = setupGame();
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
    game *g = setupGame();
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
    game *g = setupGame();
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
    game *g = setupGame();
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

// Used to help test various Move test ACs
// Re-creates an image posted to the Github
void tests::gameMoveState(game *g) {
    g->setTurn(1);
    // Black turn
    g->SimulateButtonPress(0, 6);
    // White turn
    g->SimulateButtonPress(0, 0);
    // Black turn
    g->SimulateButtonPress(3, 6);
    // White turn
    g->SimulateButtonPress(3, 0);
    // Black turn
    g->SimulateButtonPress(6, 0);
    // White turn
    g->SimulateButtonPress(6, 6);
    // Black turn
    g->SimulateButtonPress(1, 5);
    // White turn
    g->SimulateButtonPress(1, 1);
    // Black turn
    g->SimulateButtonPress(5, 5);
    // White turn
    g->SimulateButtonPress(5, 1);
    // Black turn
    g->SimulateButtonPress(2, 4);
    // White turn
    g->SimulateButtonPress(2, 2);
    // Black turn
    g->SimulateButtonPress(3, 4);
    // White turn
    g->SimulateButtonPress(3, 2);
    // Black turn
    g->SimulateButtonPress(2, 3);
    // White turn
    g->SimulateButtonPress(0, 3);
    // Black turn
    g->SimulateButtonPress(6, 3);
    // White turn
    g->SimulateButtonPress(4, 3);
}

// Sets game up from a blank slate to a Fly state
// i.e. three total pieces left
void tests::gameFlyState(game *g) {
    gameMoveState(g);
    g->setTurn(1);

    // Form a black mill
    g->SimulateButtonPress(3,6);
    g->SimulateButtonPress(3,5);
    // Remove white piece
    g->SimulateButtonPress(6,6);
    // Form a white mill
    g->SimulateButtonPress(3,0);
    g->SimulateButtonPress(3,1);
    // Remove black piece
    g->SimulateButtonPress(6,0);
    // Move black piece
    g->SimulateButtonPress(3,5);
    g->SimulateButtonPress(3,6);
    // Move white piece
    g->SimulateButtonPress(3,1);
    g->SimulateButtonPress(3,0);

    // Form a black mill
    g->SimulateButtonPress(3,6);
    g->SimulateButtonPress(3,5);
    // Remove white piece
    g->SimulateButtonPress(0,3);
    // Form a white mill
    g->SimulateButtonPress(3,0);
    g->SimulateButtonPress(3,1);
    // Remove black piece
    g->SimulateButtonPress(6,3);
    // Move black piece
    g->SimulateButtonPress(3,5);
    g->SimulateButtonPress(3,6);
    // Move white piece
    g->SimulateButtonPress(3,1);
    g->SimulateButtonPress(3,0);

    // Form a black mill
    g->SimulateButtonPress(3,6);
    g->SimulateButtonPress(3,5);
    // Remove white piece
    g->SimulateButtonPress(0,0);
    // Form a white mill
    g->SimulateButtonPress(3,0);
    g->SimulateButtonPress(3,1);
    // Remove black piece
    g->SimulateButtonPress(0,6);
    // Move black piece
    g->SimulateButtonPress(3,5);
    g->SimulateButtonPress(3,6);
    // Move white piece
    g->SimulateButtonPress(3,1);
    g->SimulateButtonPress(3,0);

    // Form a black mill
    g->SimulateButtonPress(3,6);
    g->SimulateButtonPress(3,5);
    // Remove white piece
    g->SimulateButtonPress(4,3);
    // Form a white mill
    g->SimulateButtonPress(3,0);
    g->SimulateButtonPress(3,1);
    // Remove black piece
    g->SimulateButtonPress(3,4);
    // Move black piece
    g->SimulateButtonPress(3,5);
    g->SimulateButtonPress(3,6);
    // Move white piece
    g->SimulateButtonPress(3,1);
    g->SimulateButtonPress(3,0);

    // Form a black mill
    g->SimulateButtonPress(3,6);
    g->SimulateButtonPress(3,5);
    // Remove white piece
    g->SimulateButtonPress(2,2);
    // Form a white mill
    g->SimulateButtonPress(3,0);
    g->SimulateButtonPress(3,1);
    // Remove black piece
    g->SimulateButtonPress(2,3);
    // Move black piece
    g->SimulateButtonPress(3,5);
    g->SimulateButtonPress(3,6);
    // Move white piece
    g->SimulateButtonPress(3,1);
    g->SimulateButtonPress(3,0);

    // Form a black mill
    g->SimulateButtonPress(3,6);
    g->SimulateButtonPress(3,5);
    // Remove white piece
    g->SimulateButtonPress(3,2);

    // Move white piece
    g->SimulateButtonPress(3,0);
    g->SimulateButtonPress(6,0);
    // Move black piece
    g->SimulateButtonPress(3,5);
    g->SimulateButtonPress(3,6);
    // Move white piece
    g->SimulateButtonPress(6,0);
    g->SimulateButtonPress(3,0);
    // Move black piece
    g->SimulateButtonPress(3,6);
    g->SimulateButtonPress(0,6);
    // Move white piece
    g->SimulateButtonPress(3,0);
    g->SimulateButtonPress(3,1);
    // Remove black piece
    g->SimulateButtonPress(2,4);

}

// AC - 4.10
void tests::testNoValidMove() {
    game *g = setupGame();
    gameMoveState(g);

    g->setTurn(1);
    // Click a button with no valid move state so the moveState flag is never set to valid
    g->SimulateButtonPress(2, 4);
    Hole* hole = g->getHole(2, 4);
    QCOMPARE(hole->moveState, false);
}

// AC - 4.7
void tests::testOneValidMove() {
    game *g = setupGame();
    gameMoveState(g);

    g->setTurn(1);
    // Click a button with one valid move state
    g->SimulateButtonPress(3, 6);
    Hole* hole = g->getHole(3, 6);
    QCOMPARE(hole->moveState, true);
}

// AC - 4.8
void tests::testTwoValidMoves() {
    game *g = setupGame();
    gameMoveState(g);

    g->setTurn(1);
    // Click a button with two valid move state
    g->SimulateButtonPress(1, 5);
    Hole* hole = g->getHole(1, 5);
    QCOMPARE(hole->moveState, true);
}

// AC - 4.9
void tests::testThreeValidMoves() {
    game *g = setupGame();
    gameMoveState(g);

    g->setTurn(2);
    // Click a button with three valid move state
    g->SimulateButtonPress(4, 3);
    Hole* hole = g->getHole(4, 3);
    QCOMPARE(hole->moveState, true);
}

// AC - 4.3
void tests::testValidMoveOnlyUp() {
    game *g = setupGame();

    g->setTurn(1);
    // Black turn
    g->SimulateButtonPress(0, 6);
    // White turn
    g->SimulateButtonPress(0, 0);
    // Black turn
    g->SimulateButtonPress(3, 6);
    // White turn
    g->SimulateButtonPress(3, 0);
    // Black turn
    g->SimulateButtonPress(6, 0);
    // White turn
    g->SimulateButtonPress(6, 6);
    // Black turn
    g->SimulateButtonPress(1, 5);
    // White turn
    g->SimulateButtonPress(1, 1);
    // Black turn
    g->SimulateButtonPress(5, 5);
    // White turn
    g->SimulateButtonPress(5, 1);
    // Black turn
    g->SimulateButtonPress(2, 4);
    // White turn
    g->SimulateButtonPress(2, 2);
    // Black turn
    g->SimulateButtonPress(3, 4);
    // White turn
    g->SimulateButtonPress(3, 2);
    // Black turn
    g->SimulateButtonPress(2, 3);
    // White turn
    g->SimulateButtonPress(0, 3);
    // Black turn
    g->SimulateButtonPress(5, 3);
    // White turn
    g->SimulateButtonPress(4, 3);

    g->setTurn(1);
    // Click a button with only a valid move up
    g->SimulateButtonPress(5, 5);
    Hole* hole = g->getHole(5, 5);
    QCOMPARE(hole->moveState, true);
}

// AC - 4.4
void tests::testValidMoveOnlyDown() {
    game *g = setupGame();

    g->setTurn(1);
    // Black turn
    g->SimulateButtonPress(0, 6);
    // White turn
    g->SimulateButtonPress(0, 0);
    // Black turn
    g->SimulateButtonPress(3, 6);
    // White turn
    g->SimulateButtonPress(3, 0);
    // Black turn
    g->SimulateButtonPress(6, 0);
    // White turn
    g->SimulateButtonPress(6, 6);
    // Black turn
    g->SimulateButtonPress(1, 5);
    // White turn
    g->SimulateButtonPress(1, 1);
    // Black turn
    g->SimulateButtonPress(5, 5);
    // White turn
    g->SimulateButtonPress(5, 1);
    // Black turn
    g->SimulateButtonPress(2, 4);
    // White turn
    g->SimulateButtonPress(2, 2);
    // Black turn
    g->SimulateButtonPress(3, 4);
    // White turn
    g->SimulateButtonPress(3, 2);
    // Black turn
    g->SimulateButtonPress(2, 3);
    // White turn
    g->SimulateButtonPress(1, 3);
    // Black turn
    g->SimulateButtonPress(6, 3);
    // White turn
    g->SimulateButtonPress(4, 3);

    g->setTurn(1);
    // Click a button with only a valid move up
    g->SimulateButtonPress(1, 5);
    Hole* hole = g->getHole(1, 5);
    QCOMPARE(hole->moveState, true);
}

// AC - 4.5
void tests::testValidMoveOnlyLeft() {
    game *g = setupGame();
    gameMoveState(g);
    // Click a button with only a valid move up
    g->SimulateButtonPress(3, 6);
    Hole* hole = g->getHole(3, 6);
    QCOMPARE(hole->moveState, true);
}

// AC - 4.6
void tests::testValidMoveOnlyRight() {
    game *g = setupGame();

    g->setTurn(1);
    // Black turn
    g->SimulateButtonPress(0, 6);
    // White turn
    g->SimulateButtonPress(0, 0);
    // Black turn
    g->SimulateButtonPress(3, 6);
    // White turn
    g->SimulateButtonPress(3, 0);
    // Black turn
    g->SimulateButtonPress(6, 0);
    // White turn
    g->SimulateButtonPress(6, 6);
    // Black turn
    g->SimulateButtonPress(1, 5);
    // White turn
    g->SimulateButtonPress(1, 1);
    // Black turn
    g->SimulateButtonPress(5, 5);
    // White turn
    g->SimulateButtonPress(5, 3);
    // Black turn
    g->SimulateButtonPress(2, 4);
    // White turn
    g->SimulateButtonPress(2, 2);
    // Black turn
    g->SimulateButtonPress(3, 4);
    // White turn
    g->SimulateButtonPress(4, 2);
    // Black turn
    g->SimulateButtonPress(2, 3);
    // White turn
    g->SimulateButtonPress(0, 3);
    // Black turn
    g->SimulateButtonPress(6, 3);
    // White turn
    g->SimulateButtonPress(4, 3);

    g->setTurn(2);
    // Click a button with only a valid move up
    g->SimulateButtonPress(4, 3);
    Hole* hole = g->getHole(4, 3);
    QCOMPARE(hole->moveState, true);
}

// AC - 4.1
void tests::testClickValidMove() {
    game *g = setupGame();
    gameMoveState(g);

    g->setTurn(2);
    // Click a button with three valid move state
    g->SimulateButtonPress(4, 3);
    // 'Move' piece to new position
    g->SimulateButtonPress(5, 3);

    g->setTurn(2);

    Hole* oldHole = g->getHole(4, 3);
    Hole* newHole = g->getHole(5, 3);
    QCOMPARE(oldHole->moveState, false);
    QCOMPARE(oldHole->filled, false);
    QCOMPARE(newHole->moveState, false);
    QCOMPARE(newHole->filled, true);
    QCOMPARE(newHole->playerOwned, g->getActivePlayer()->turn);
}

// AC - 4.2
void tests::testClickInvalidMove() {
    game *g = setupGame();
    gameMoveState(g);

    g->setTurn(1);
    // Click a button with one valid move state
    g->SimulateButtonPress(3, 6);
    // Click invalid move spot
    g->SimulateButtonPress(0, 6);

    g->setTurn(1);

    Hole* oldHole = g->getHole(3, 6);
    Hole* newHole = g->getHole(0, 6);
    QCOMPARE(oldHole->moveState, true);
    QCOMPARE(oldHole->filled, true);
    QCOMPARE(newHole->moveState, false);
    QCOMPARE(newHole->filled, true);
}

void tests::testMoveMillRemove() {
    game *g = setupGame();
    gameMoveState(g);

    g->setTurn(1);
    g->SimulateButtonPress(3, 6);
    // Form a mill with this move
    g->SimulateButtonPress(3, 5);

    // Attempt to remove a white piece
    g->SimulateButtonPress(6,6);

    // Check if it's removed
    Hole* hole = g->getHole(6, 6);
    QCOMPARE(hole->filled, false);
    // Check if it's been set to white's turn
    QCOMPARE(g->getActivePlayer()->turn, 2);
}

void tests::testClickInvalidMoveFar() {
    game *g = setupGame();
    gameMoveState(g);

    g->setTurn(1);
    // Click a button with one valid move state
    g->SimulateButtonPress(3, 6);
    // Click invalid move spot
    g->SimulateButtonPress(3, 1);

    // Check if clicked hole is filled
    Hole* hole = g->getHole(3, 1);
    QCOMPARE(hole->filled, true);
    // Check if turn is still Black's, indicating an invalid destination was chosen
    QCOMPARE(g->getActivePlayer()->turn, 2);
}

void tests::testFlyPiece() {
    game *g = setupGame();
    gameFlyState(g);

    // Fly State assertions, only needed in one of any fly tests function
    Hole* hole = g->getHole(1, 1);
    QCOMPARE(hole->filled, true);
    QCOMPARE(hole->playerOwned, 2);
    hole = g->getHole(3, 1);
    QCOMPARE(hole->filled, true);
    QCOMPARE(hole->playerOwned, 2);
    hole = g->getHole(5, 1);
    QCOMPARE(hole->filled, true);
    QCOMPARE(hole->playerOwned, 2);

    hole = g->getHole(0, 6);
    QCOMPARE(hole->filled, true);
    QCOMPARE(hole->playerOwned, 1);
    hole = g->getHole(1, 5);
    QCOMPARE(hole->filled, true);
    QCOMPARE(hole->playerOwned, 1);
    hole = g->getHole(5, 5);
    QCOMPARE(hole->filled, true);
    QCOMPARE(hole->playerOwned, 1);

    // Actual fly piece test
    // TODO: Still needs to be implemented, test will fail until then
    // NOTE: It is currently black's turn

    // Attempt to fly piece
    g->SimulateButtonPress(0, 6);
    g->SimulateButtonPress(6, 0);
    hole = g->getHole(6, 0);

    QCOMPARE(hole->filled, true);
    QCOMPARE(hole->playerOwned, 1);
    QCOMPARE(g->getActivePlayer()->turn, 2);

}

void tests::testInvalidFlyPiece() {
    game *g = setupGame();
    gameFlyState(g);

    // NOTE: It is currently black's turn
    // Attempt to fly a piece into a filled spot
    g->SimulateButtonPress(0, 6);
    g->SimulateButtonPress(3, 1);
    Hole* hole = g->getHole(3, 1);

    QCOMPARE(hole->filled, true);
    QCOMPARE(hole->playerOwned, 2);
}

//Test Remove

QTEST_MAIN(tests)
#include "tst_tests.moc"













