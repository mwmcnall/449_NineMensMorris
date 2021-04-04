#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "board.h"
#include "game.h"
#include "player_gui.h"
#include "logwindow.h"
#include <QLabel>
#include <QPixmap>

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

#define HOME_PAGE 0
#define GAME_PAGE 1

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    this->setFixedSize(800,650);
    //this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    ui->stackedWidget->setFixedSize(775,600);
    //ui->stackedWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

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

    QHBoxLayout *horizontalGameLayout = new QHBoxLayout();
    QVBoxLayout *verticalGameLayout = new QVBoxLayout();

    horizontalGameLayout->addWidget(g->playerOneGUI->CreatePlayerGUI(1));
    horizontalGameLayout->addWidget(g->b->CreateBoardGUI());
    horizontalGameLayout->addWidget(g->playerTwoGUI->CreatePlayerGUI(2));

    // Create a widget
    QWidget* w = new QWidget();

    // Set the grid layout as a main layout
    w->setLayout(horizontalGameLayout);

    verticalGameLayout->addWidget(w);
    verticalGameLayout->addWidget(g->log);

    QWidget* main = new QWidget();

    main->setLayout(verticalGameLayout);
    //main->setFixedSize(800,700);
    //main->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    ui->stackedWidget->insertWidget(GAME_PAGE, main);
    //ui->stackedWidget->insertWidget(GAME_PAGE, g->b->CreateBoardGUI());
    ui->stackedWidget->setCurrentIndex(GAME_PAGE);
    ui->stackedWidget->show();

    g->gameLoop();
}















