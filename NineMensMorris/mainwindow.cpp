#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "board.h"
#include "game.h"
#include <QLabel>
#include <QPixmap>

#define HOME_PAGE 0
#define GAME_PAGE 1

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // Make sure the default state of the stackedWidget is on the 'home page'
    ui->stackedWidget->setCurrentIndex(HOME_PAGE);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 'New Game' Button
// TODO: Temporary method, attached to 'New Game' button in layout
// Board is completely un-used atm, it's just there to create a
// test UI for board and auto-generated button layout
void MainWindow::on_pushButton_clicked()
{

    game *g = new game();

    g->ChoosePlayerTurnGUI();

    //Board *board = new Board();

    ui->stackedWidget->insertWidget(GAME_PAGE, g->b->CreateBoardGUI());
    ui->stackedWidget->setCurrentIndex(GAME_PAGE);
    ui->stackedWidget->show();

    g->gameLoop();
}















