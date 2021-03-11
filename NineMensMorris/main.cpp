#include "mainwindow.h"
#include "testboard.h"
#include "testgame.h"
#include "testpieces.h"

#include <QApplication>

#define TESTING 0
#define PRODUCTION 1

int testGameMethods();
int testBoardMethods();
int testPiecesMethods();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // NOTE: Set to TESTING to do all unit tests,
    // set to PRODUCTION to just run game
    int status = PRODUCTION;

    if (status == TESTING) {
        // NOTE: Only one GUI test seems to run properly at once, I'm unsure why
        // Comment out all but one to test a GUI element

        //status = testBoardMethods();
        //status = testGameMethods();
        status = testPiecesMethods();
        return status;
// Game logic here
    } else if (status == PRODUCTION) {
        MainWindow w;
        w.show();
        return a.exec();
    } else {
        return -1;
    }

}

int testGameMethods() {
    testGame tg;
    return QTest::qExec(&tg);
}

int testBoardMethods() {
    testBoard tb;
    return QTest::qExec(&tb);
}

int testPiecesMethods() {
    testPieces tp;
    return QTest::qExec(&tp);
}





