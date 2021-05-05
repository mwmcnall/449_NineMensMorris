#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

#define HOME_PAGE 0
#define GAME_PAGE 1
#define OPP_PAGE 2
#define COLOR_PAGE 3

#define HUMAN_PLAYER false
#define COMPUTER_PLAYER true

#define WHITE_PIECES 2
#define BLACK_PIECES 1

// Variables to control UI
int opponent;
int human_color;
game *g;

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

    g = new game(false);

    ui->stackedWidget->setCurrentIndex(OPP_PAGE);
    ui->stackedWidget->show();
}

void MainWindow::activateColorScene() {
    ui->stackedWidget->setCurrentIndex(COLOR_PAGE);
    ui->stackedWidget->show();
}

void MainWindow::on_human_button_clicked()
{
    opponent = HUMAN_PLAYER;

    // Change scene
    activateColorScene();
}


void MainWindow::on_computer_button_clicked()
{
    opponent = COMPUTER_PLAYER;

    // Change scene
    activateColorScene();
}

void MainWindow::activateGameScene() {

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
    // Adds log to below game for information display
    verticalGameLayout->addWidget(g->log);

    QWidget* main = new QWidget();

    main->setLayout(verticalGameLayout);

    g->setActivePlayer(human_color);
    if (opponent == COMPUTER_PLAYER)
        g->setComputerPlayer(!human_color);

    ui->stackedWidget->insertWidget(GAME_PAGE, main);
    ui->stackedWidget->setCurrentIndex(GAME_PAGE);
    ui->stackedWidget->show();

    g->ConnectButtons();
}

void MainWindow::on_black_button_clicked()
{
    human_color = BLACK_PIECES;

    // Change scene
    activateGameScene();
}

void MainWindow::on_white_button_clicked()
{
    human_color = WHITE_PIECES;

    // Change scene
    activateGameScene();
}
