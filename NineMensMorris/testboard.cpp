#include "testboard.h"
#include <QThread>

void testBoard::init()
{

}

/* Example on how to dynamically create a Horizontal Box Layout
    Board *board1 = new Board();
    Board *board2 = new Board();

    QWidget *window = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(window);

    hLayout->addWidget(board1->CreateBoardGUI());
    hLayout->addWidget(board2->CreateBoardGUI());

    ui->stackedWidget->insertWidget(2, window);
    ui->stackedWidget->setCurrentIndex(2);
*/

void testBoard::testBoardGUI()
{
    Board *board = new Board();

    board->CreateBoardGUI()->show();

    // GUI disappears too quickly w/out a sleep command
    QThread::sleep(4);
}
