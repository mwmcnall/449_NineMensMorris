#include "game.h"
#include "board.h"
#include "player.h"

game::game()
{
    this->playerOne = new player;
    this->playerTwo = new player;
    this->b = new Board;
}

void game::setTurn(int _turn) {
    this->turn = _turn;
}

int game::getTurn() {
    return this->turn;
}

// -- void ChoosePlayerTurnGUI()
// -- Opens a window that asks the player to choose what color pieces they want
// NOTE: 3/11, this is how we decide who goes first
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

    /*while (setTurn == 1) {
        if (Board.ButtonPress() == 1) {

        }
    }
    */

}

void game::ChooseWhitePieces() {
    this->setTurn(2);

    ChoosePlayerTurnGUIClose();
}

void game::ChoosePlayerTurnGUIClose() {
    w->close();
}

// TODO: Only a placeholder function for now, logic needs to be implemented
void game::gameLoop() {

    this->ConnectButtons();

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

// -- ButtonPress()
// -- This is what activates what any Hole is clicked on the board
void game::ButtonPress() {
    Hole *button = qobject_cast<Hole*>(sender());
    playerOne->checkPhase();
    playerTwo->checkPhase();
    //TODO logic should allow for moving pieces when there is no more pieces


       //IF PLAYER IS STILL IN PHASE 1
    if((getTurn() == 1 && playerOne->playerPhase == 1) || (getTurn() == 2 && playerTwo->playerPhase == 1)){


        if (button->filled == false) {
            //places piece from player one pool
            if(getTurn() == 1 && playerOne->numPieces >= 1){
                playerOne->placePiece();
                playerOne->checkPhase();
                button->fillHole(this->turn);
                //check for mill here

            }

            //places piece from player two pool
            if(getTurn() == 2 && playerTwo->numPieces >= 1){
                playerTwo->placePiece();
                playerTwo->checkPhase();
                button->fillHole(this->turn);
                //check for mill here

            }



            this->incrementTurn();
        }
    }


    //PHASE 2 CHECKS
   if((getTurn() == 1 && playerOne->playerPhase == 2) || (getTurn() == 2 && playerTwo->playerPhase == 2)){
        //TODO phase 2 moving pieces
   }

   //PHASE 3 CHECKS
   if((getTurn() == 1 && playerOne->playerPhase == 3) || (getTurn() == 2 && playerTwo->playerPhase == 3)){
        //TODO phase 3 fly
   }

}

// -- SimualteButtonPress(int, int)
// -- Can simulate a button press based on a co-ordinate
// -- returns true if 'pressed', false if not
bool game::SimulateButtonPress(int x, int y) {
    Hole *button = &this->b->buttons[x][y];

    if (button->filled == false) {
        button->fillHole(this->turn);
        this->incrementTurn();
        return true;
    }

    return false;
}


// -- void ConnectButtons()
// -- Connects all buttons stored locally to a function
void game::ConnectButtons() {
    for (auto b: this->b->buttons)
        connect(b, &Hole::clicked, this, &game::ButtonPress);
}

// -- incrementTurn()
// -- Changes from one player's turn to another
void game::incrementTurn() {
    if (this->turn == 1)
        this->turn = 2;
    else
        this->turn = 1;
}

bool game::checkMill(int x, int y){
    //pass in button col and row
        //function for check row and check col
    //check surrounding few for 3 in a row
    //return if mill or not
    return false;
}





