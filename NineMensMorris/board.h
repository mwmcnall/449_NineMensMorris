#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QPushButton>
#include <QGridLayout>
#include "hole.h"

#define BUTTON_WIDTH 1
#define BUTTON_HEIGHT 1
#define BOARD_WIDTH 7
// 3 for this case
#define HALF_BOARD_WIDTH int((BOARD_WIDTH -1) / 2)
#define BOARD_HEIGHT 7
// 3 for this case
#define HALF_BOARD_HEIGHT int((BOARD_HEIGHT -1) / 2)
// 24 for this case
#define BOARD_ELEMENTS int(((BOARD_WIDTH * BOARD_HEIGHT)-1)/2)

class Board : public QWidget
{
    Q_OBJECT
public:
    // Variables
    QVector<Hole*> buttons;
    QWidget *w;
    // Methods
    explicit Board(QWidget *parent = nullptr);

    QWidget* CreateBoardGUI(bool showButtons = false);

private:
    void CreateButtons();
    void AddButtonsToBoard(QGridLayout*);
    void AddButtonToGridLayout(QGridLayout*, Hole*, int row, int col, int &buttonCount);
    void HideButtons();
};

#endif // BOARD_H
