#include "board.h"
#include <QMessageBox>

Board::Board(QObject *parent) : QObject(parent)
{
    // Create a new Grid Layout
    QGridLayout *gridLayout = new QGridLayout;

    CreateButtons();

    AddButtonsToBoard(gridLayout);

    ConnectButtons();

    // NOTE: Set all buttons to be invisible, comment out to see button layout
    HideButtons();

    // Create a widget
    QWidget *w = new QWidget();

    // Set the grid layout as a main layout
    w->setLayout(gridLayout);

    // TODO: Can re-name / remove
    w->setWindowTitle("Board Test");

    // Set Size
    w->setFixedSize(500,500);

    // Set background
    // TODO: Replace temporary image with a final one
    QPixmap pixmap;
    pixmap.load(":/img/img/board.jpg");
    pixmap = pixmap.scaled(w->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QPalette palette;
    palette.setBrush(QPalette::Window, pixmap);
    w->setPalette(palette);

    // Display
    w->show();
}

// -- void CreateButtons()
// -- Creates all necessary buttons for Nine Men's Morris and adds them to a privately stored vector in Board
// TODO: Can probably be done programatically
// The names were chosen to help me debug positioning, might be useful for future debugging to keep names?
void Board::CreateButtons() {
// Create all buttons necessary for the board
// Adds them to the QVector as well
    QPushButton *a7 = new QPushButton("");
    buttons.append(a7);
    QPushButton *d7 = new QPushButton("");
    buttons.append(d7);
    QPushButton *g7 = new QPushButton("");
    buttons.append(g7);
    QPushButton *b6 = new QPushButton("");
    buttons.append(b6);
    QPushButton *d6 = new QPushButton("");
    buttons.append(d6);
    QPushButton *f6 = new QPushButton("");
    buttons.append(f6);
    QPushButton *c5 = new QPushButton("");
    buttons.append(c5);
    QPushButton *d5 = new QPushButton("");
    buttons.append(d5);
    QPushButton *e5 = new QPushButton("");
    buttons.append(e5);
    QPushButton *a4 = new QPushButton("");
    buttons.append(a4);
    QPushButton *b4 = new QPushButton("");
    buttons.append(b4);
    QPushButton *c4 = new QPushButton("");
    buttons.append(c4);
    QPushButton *e4 = new QPushButton("");
    buttons.append(e4);
    QPushButton *f4 = new QPushButton("");
    buttons.append(f4);
    QPushButton *g4 = new QPushButton("");
    buttons.append(g4);
    QPushButton *c3 = new QPushButton("");
    buttons.append(c3);
    QPushButton *d3 = new QPushButton("");
    buttons.append(d3);
    QPushButton *e3 = new QPushButton("");
    buttons.append(e3);
    QPushButton *b2 = new QPushButton("");
    buttons.append(b2);
    QPushButton *d2 = new QPushButton("");
    buttons.append(d2);
    QPushButton *f2 = new QPushButton("");
    buttons.append(f2);
    QPushButton *a1 = new QPushButton("");
    buttons.append(a1);
    QPushButton *d1 = new QPushButton("");
    buttons.append(d1);
    QPushButton *g1 = new QPushButton("");
    buttons.append(g1);
}

// -- void AddButtonsToBoard(QGridLayout*)
// -- Adds all buttons in local vector to the gridLayout specified
// TODO: Can definitely be done programatically, these were the correct positions
// I found through debugging one row at a time
void Board::AddButtonsToBoard(QGridLayout* gridLayout) {
// Add all buttons created to the board in their correct positions
    // addWidget(*Widget, row, column, rowspan, colspan)
    // Row 7
    gridLayout->addWidget(buttons[0], 0, 0, 1, 1);
    gridLayout->addWidget(buttons[1], 0, 3, 1, 1);
    gridLayout->addWidget(buttons[2], 0, 6, 1, 1);
    // Row 6
    gridLayout->addWidget(buttons[3], 1, 1, 1, 1);
    gridLayout->addWidget(buttons[4], 1, 3, 1, 1);
    gridLayout->addWidget(buttons[5], 1, 5, 1, 1);
    // Row 5
    gridLayout->addWidget(buttons[6], 2, 2, 1, 1);
    gridLayout->addWidget(buttons[7], 2, 3, 1, 1);
    gridLayout->addWidget(buttons[8], 2, 4, 1, 1);
    // Row 4
    gridLayout->addWidget(buttons[9], 3, 0, 1, 1);
    gridLayout->addWidget(buttons[10], 3, 1, 1, 1);
    gridLayout->addWidget(buttons[11], 3, 2, 1, 1);
    gridLayout->addWidget(buttons[12], 3, 4, 1, 1);
    gridLayout->addWidget(buttons[13], 3, 5, 1, 1);
    gridLayout->addWidget(buttons[14], 3, 6, 1, 1);
    // Row 3
    gridLayout->addWidget(buttons[15], 4, 2, 1, 1);
    gridLayout->addWidget(buttons[16], 4, 3, 1, 1);
    gridLayout->addWidget(buttons[17], 4, 4, 1, 1);
    // Row 2
    gridLayout->addWidget(buttons[18], 5, 1, 1, 1);
    gridLayout->addWidget(buttons[19], 5, 3, 1, 1);
    gridLayout->addWidget(buttons[20], 5, 5, 1, 1);
    // Row 1
    gridLayout->addWidget(buttons[21], 6, 0, 1, 1);
    gridLayout->addWidget(buttons[22], 6, 3, 1, 1);
    gridLayout->addWidget(buttons[23], 6, 6, 1, 1);
}

// -- void HideButtons()
// -- Sets all buttons to be transparent on the board
void Board::HideButtons() {
    for(auto b : buttons) {
        b->setStyleSheet("QPushButton {background-color: transparent;border: 0px}");
    }
}

// TODO: Temporary function to test functionality and connect to buttons
// Should probably be encapsulated in a Button class
// TODO: Needs correct Button functionality
void Board::ButtonPress() {
    QMessageBox msgbox;
    msgbox.setText("Button Pressed");
    msgbox.exec();
}

// -- void ConnectButtons()
// -- Connects all buttons stored locally to a function
// TODO: Should probably take a function in as an argument to assign (if possible)
// Otherwise we can hard code a function when it's designed
void Board::ConnectButtons() {
    for (auto b: buttons)
        connect(b, &QPushButton::clicked, this, &Board::ButtonPress);
}
