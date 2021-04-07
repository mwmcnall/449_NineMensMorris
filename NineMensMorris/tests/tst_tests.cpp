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
    void testDoNOTPlacePiece();
    void testChooseFirstTurn();
    void testBoardGUI();
    void testMill();
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

void tests::testPlacePiece()
{
    game *g = new game;
    g->b->CreateBoardGUI();
    // TODO: Currenty this just connects the buttson to the correct method
    // Will likely break as game is expanded
    g->ConnectButtons();

    g->setTurn(1);
    g->SimulateButtonPress(0, 0);

    Hole* button = &g->b->buttons[0][0];

    QCOMPARE(button->filled, true);
    QCOMPARE(button->playerOwned, 1);
}

void tests::testDoNOTPlacePiece() {
    game *g = new game;
    g->b->CreateBoardGUI();
    // TODO: Currenty this just connects the buttson to the correct method
    // Will likely break as game is expanded
    g->ConnectButtons();

    g->setTurn(1);
    // Click the same button twice
    g->SimulateButtonPress(0, 0);
    g->SimulateButtonPress(0, 0);

    Hole* button = g->getHole(0, 0);

    // Make sure the button is filled
    QCOMPARE(button->filled, true);
    // Make sure ownership didn't change after being clicked a second time
    QCOMPARE(button->playerOwned, 1);
}

void tests::testChooseFirstTurn()
{
    int testTurn = 1;

    game *g = new game;

    g->setTurn(testTurn);
    QCOMPARE(testTurn, g->getTurn());
}

void tests::testBoardGUI()
{
    Board *board = new Board();

    // Set to show buttons for debugging purposes
    board->CreateBoardGUI(true)->show();

    // GUI disappears too quickly w/out a sleep command
    QThread::sleep(4);

    board->w->close();
}

//Test Mill
void tests::testMill()
{
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

//Test Remove

QTEST_MAIN(tests)
#include "tst_tests.moc"
