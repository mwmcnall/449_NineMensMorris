#include "mainwindow.h"
#include "testboard.h"
#include "testgame.h"

#include <QApplication>

#define TESTING 0
#define PRODUCTION 1

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // NOTE: Set to TESTING to do all unit tests,
    // set to PRODUCTION to just run game
    int status = TESTING;

    if (status == TESTING) {
    {
        testBoard tb;
        status |= QTest::qExec(&tb);
    }
    {
        testGame tg;
        status |= QTest::qExec(&tg);
    }
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
