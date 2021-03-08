#include "game.h"

game::game()
{

}

void game::setTurn(char _turn) {
    this->turn = _turn;
}

char game::getTurn() {
    return this->turn;
}

void game::ChoosePlayerTurnGUI() {

    w = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(w);
    QPushButton *blackButton = new QPushButton("Black");
    QPushButton *whiteBUtton = new QPushButton("White");

    connect(blackButton, &QPushButton::clicked, this, &game::ChooseBlackPieces);
    connect(whiteBUtton, &QPushButton::clicked, this, &game::ChooseWhitePieces);

    hLayout->addWidget(blackButton);
    hLayout->addWidget(whiteBUtton);

    w->setLayout(hLayout);
    w->setFixedSize(400,200);
    w->setWindowTitle("Choose Piece Color");

    w->show();

}


void game::ChooseBlackPieces() {
    this->setTurn('B');

    ChoosePlayerTurnGUIClose();
}

void game::ChooseWhitePieces() {
    this->setTurn('W');

    ChoosePlayerTurnGUIClose();
}

void game::ChoosePlayerTurnGUIClose() {
    w->close();
}










