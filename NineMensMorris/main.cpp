#include "mainwindow.h"
#include "testboard.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

//QTEST_MAIN(testBoard);
