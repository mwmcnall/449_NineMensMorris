#include "board.h"
#include <QMessageBox>

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

// Initializer
Board::Board(QWidget *parent) : QWidget(parent)
{
}

// Board GUI is created
QWidget* Board::CreateBoardGUI(bool showButtons) {
    // Create a new Grid Layout
    QGridLayout *gridLayout = new QGridLayout;

    CreateButtons();

    AddButtonsToBoard(gridLayout);

    ConnectButtons();

    // NOTE: Set all buttons to be invisible, comment out to see button layout
    if (showButtons == false)
        HideButtons();

    // Create a widget
    w = new QWidget();

    // Set the grid layout as a main layout
    w->setLayout(gridLayout);

    // TODO: Can re-name / remove
    //w->setWindowTitle("Board Test");

    // Set Size
    w->setFixedSize(500,500);

    // Set background to be stretched to the size of the widget / Fixed Sized of the layout if set
    // TODO: Replace temporary image with a final one
    w->setStyleSheet(".QWidget {border-image:url(:/img/img/board.jpg) 0 0 0 0 stretch stretch}");

    return w;
}

// -- void HideButtons()
// -- Sets all buttons to be transparent on the board
void Board::HideButtons() {
    for(auto b : buttons) {
        b->setStyleSheet("QPushButton {background-color: transparent;border: 0px}");
    }
}

// -- void CreateButtons()
// -- Creates all necessary buttons for Nine Men's Morris and adds them to a privately created vector in Board
void Board::CreateButtons() {

    for (int i = 0; i < BOARD_ELEMENTS; i++)
        buttons.append( new Button );
}

// -- void AddButtonsToBoard(QGridLayout*)
// -- Adds all buttons in local vector to the gridLayout specified
void Board::AddButtonsToBoard(QGridLayout* gridLayout) {
    int buttonCount = 0;
    int distance = HALF_BOARD_WIDTH;

    // Top and Bottom half
    for (int row = 0; row < HALF_BOARD_HEIGHT; row++) {
        // 0 - 2
        for (int col = row; col <= (row + (distance * 2)); col += distance) {
            // 0 and 6
                // 0, 3, 6
            // 1 and 5
                // 1, 3, 5
            // 2 and 4
                // 2, 3, 4
            AddButtonToGridLayout(gridLayout, buttons[buttonCount], row, col, buttonCount);
            AddButtonToGridLayout(gridLayout, buttons[buttonCount], BOARD_HEIGHT - row, col, buttonCount);
        }

        distance -= 1;
    }

    // Middle row
    for (int col = 0; col < BOARD_WIDTH; col++) {
        if (col != HALF_BOARD_WIDTH) {
            AddButtonToGridLayout(gridLayout, buttons[buttonCount], HALF_BOARD_HEIGHT, col, buttonCount);
        }
    }
}

// -- addButtonToGridLayout()
// Adds a button to the grid layout
// Sets the co-ordinates of the button and also increments button count
void Board::AddButtonToGridLayout(QGridLayout* gridLayout, Button* button, int row, int col, int &buttonCount) {
    // addWidget(*Widget, row, column, rowspan, colspan)
    gridLayout->addWidget(button, row, col, BUTTON_WIDTH, BUTTON_HEIGHT);
    button->setCoords(row, col);
    buttonCount++;
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
        connect(b, &Button::clicked, this, &Board::ButtonPress);
}
