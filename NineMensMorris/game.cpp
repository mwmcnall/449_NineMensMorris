#include "game.h"
#include "board.h"
#include "player.h"

game::game()
{
    player* playerOne = new player;
    player* playerTwo = new player;
}

void game::setTurn(int _turn) {
    this->turn = _turn;
}

int game::getTurn() {
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
    this->setTurn(1);

    ChoosePlayerTurnGUIClose();

    while (setTurn == 1) {
        if (Board.ButtonPress() == 1) {

        }
    }

}

void game::ChooseWhitePieces() {
    this->setTurn(2);

    ChoosePlayerTurnGUIClose();
}

void game::ChoosePlayerTurnGUIClose() {
    w->close();
}

void game::gameLoop() {
   /* bool gameOver = false;
    int turnPlayer = this->getTurn();
    while (gameOver != true) {
        //TODO initialize playerOne and playerTwo, add to references
        if(turnPlayer == 1){
            playerOne.playerTurn();
        }
        //TODO add end game check
        //just so it breaks gameplay loop for now
        gameOver = true;
    }
    */


}








