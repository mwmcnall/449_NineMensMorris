#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "board.h"
#include "game.h"
#include "player_gui.h"
#include "logwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_human_button_clicked();

    void on_computer_button_clicked();

    void on_black_button_clicked();

    void on_white_button_clicked();

private:
    Ui::MainWindow *ui;
    void activateColorScene();
    void activateGameScene();
};
#endif // MAINWINDOW_H
