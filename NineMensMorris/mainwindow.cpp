#include "mainwindow.h"
#include "ui_mainwindow.h"
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
void MainWindow::on_pushButton_clicked()
{
    // Set stackedWidget to display game state
    ui->stackedWidget->setCurrentIndex(GAME_PAGE);

}
