#include "game_gui.h"
#include<QDebug>

game_GUI::game_GUI()
{

}

// -- void ChoosePlayerTurnGUI()
// -- Opens a window that asks the player to choose what color pieces they want
// NOTE: 3/11, this is how we decide who goes first
void game_GUI::ChoosePlayerTurnGUI() {

    w = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(w);
    QPushButton *blackButton = new QPushButton("Black");
    QPushButton *whiteBUtton = new QPushButton("White");

    connect(blackButton, &QPushButton::clicked, this, &game_GUI::ChooseBlackPieces);
    connect(whiteBUtton, &QPushButton::clicked, this, &game_GUI::ChooseWhitePieces);

    hLayout->addWidget(blackButton);
    hLayout->addWidget(whiteBUtton);

    w->setLayout(hLayout);
    w->setFixedSize(400,200);
    w->setWindowTitle("Choose Piece Color");

    w->show();

}

void game_GUI::ChooseBlackPieces() {
    this->setTurn(1);

    ChoosePlayerTurnGUIClose();

}

void game_GUI::ChooseWhitePieces() {
    this->setTurn(2);

    ChoosePlayerTurnGUIClose();
}

void game_GUI::ChoosePlayerTurnGUIClose() {
    w->close();
}

void game_GUI::setTurn(int _turn) {
    this->turn = _turn;
}

int game_GUI::getTurn() {
    return this->turn;
}
