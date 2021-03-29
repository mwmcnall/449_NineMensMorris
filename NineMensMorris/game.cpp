#include "game.h"
#include "board.h"
#include "player.h"

game::game()
{
    this->playerOne = new player;
    this->playerTwo = new player;
    this->b = new Board;
    this->game_gui = new game_GUI();

    game_gui->ChoosePlayerTurnGUI();
}

void game::setTurn(int _turn) {
    this->turn = _turn;
}

int game::getTurn() {
    return this->turn;
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

bool game::checkMill(Hole *hole){

    if (checkVerticalMill(hole) || checkHorizontalMill(hole))
        return true;

    return false;
}

bool game::checkVerticalMill(Hole *hole) {

    return false;
}

bool game::checkHorizontalMill(Hole *hole) {


    return false;
}

bool game::isHoleFilled(int row, int col) {

    for (auto& hole : this->b->buttons) {
        if ((hole->getRow() == row) && (hole->getCol() == col))
            return hole->filled;
    }

    // This means the pre-condition of sending in a valid location was not kept. Exit program.
    exit(1);
}

// All isValidHoleMove functions test:
    // If a particular direction is within bounds
    // Returns whether or not the hole in that direction is available
bool game::isValidHoleMoveUp(int row_check, int col_check) {

    // Middle row is exception
    if (row_check == HALF_BOARD_HEIGHT)
        col_check += 1;
    else
        col_check += HALF_BOARD_HEIGHT - (row_check % HALF_BOARD_HEIGHT);

    // Outside of board? Always false
    if (col_check > BOARD_HEIGHT)
        return false;

    return !isHoleFilled(row_check, col_check);
}

bool game::isValidHoleMoveDown(int row_check, int col_check) {

    // Middle row is exception
    if (row_check == HALF_BOARD_HEIGHT)
        col_check -= 1;
    else
        col_check -= HALF_BOARD_HEIGHT - (row_check % HALF_BOARD_HEIGHT);

    // Outside of board? Always false
    if (col_check < 0)
        return false;

    return !isHoleFilled(row_check, col_check);
}

bool game::isValidHoleMoveLeft(int row_check, int col_check) {

    // Middle col is exception
    if (col_check == HALF_BOARD_WIDTH)
        row_check -= 1;
    else
        row_check -= HALF_BOARD_WIDTH - (col_check % HALF_BOARD_WIDTH);

    // Outside of board? Always false
    if (row_check < 0)
        return false;

    return !isHoleFilled(row_check, col_check);
}

bool game::isValidHoleMoveRight(int row_check, int col_check) {

    // Middle col is exception
    if (col_check == HALF_BOARD_WIDTH)
        row_check += 1;
    else
        row_check += HALF_BOARD_WIDTH - (col_check % HALF_BOARD_WIDTH);

    // Outside of board? Always false
    if (row_check > BOARD_WIDTH)
        return false;

    return !isHoleFilled(row_check, col_check);;
}



