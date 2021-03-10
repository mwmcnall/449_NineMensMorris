#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QPushButton>
#include <QGridLayout>
#include "button.h"

class Board : public QWidget
{
    Q_OBJECT
public:
    // Variables
    QVector<Button*> buttons;
    QWidget *w;
    // Methods
    explicit Board(QWidget *parent = nullptr);

    QWidget* CreateBoardGUI(bool showButtons = false);

private:
    void CreateButtons();
    void AddButtonsToBoard(QGridLayout*);
    void AddButtonToGridLayout(QGridLayout*, Button*, int row, int col, int &buttonCount);
    void HideButtons();
};

#endif // BOARD_H
