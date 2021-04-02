#include "game.h"
#include "board.h"
#include "player.h"
#include<QDebug>
#include<QtMath>

game::game()
{
    this->playerOne = new player(1);
    this->playerTwo = new player(2);
    this->b = new Board;
    this->game_gui = new game_GUI();
    this->playerOneGUI = new player_GUI();
    this->playerTwoGUI = new player_GUI();

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

}

// -- ButtonPress()
// -- This is what activates what any Hole is clicked on the board
void game::ButtonPress() {
    Hole *button = qobject_cast<Hole*>(sender());
    playerOne->checkPhase();
    playerTwo->checkPhase();
    //TODO logic should allow for moving pieces when there is no more pieces

    // TODO: Need to figure out how to set the turn via the GUI before the board is built
    // Otherwise we need a check like this, which is inefficient
    if (this->turn == -1) {
        setTurn(this->game_gui->getTurn());
        setActivePlayer(this->game_gui->getTurn());
    }

    // PHASE 1
    if (this->activePlayer->playerPhase == 1) {
        if (button->filled == false) {
            //places piece from player one pool
            if(this->activePlayer->numPieces >= 1){
                this->activePlayer->placePiece();
                this->activePlayer_GUI->UpdatePlayerGUI(this->activePlayer->numPieces);
                this->activePlayer->checkPhase();
                button->fillHole(this->turn);

                if(checkMill(button)){
                    qInfo() << "You got mill";
                }
                this->incrementTurn();
            }
        }
    }

    //PHASE 2 CHECKS
   if(this->activePlayer->playerPhase == 2){
        //TODO phase 2 moving pieces
   }

   //PHASE 3 CHECKS
   if(this->activePlayer->playerPhase == 3){
        //TODO phase 3 fly
   }



}


void game::setActivePlayer(int turn) {
    if (turn == 1) {
        this->activePlayer = this->playerOne;
        this->activePlayer_GUI = this->playerOneGUI;
    }
    else if (turn == 2) {
        this->activePlayer = this->playerTwo;
        this->activePlayer_GUI = this->playerTwoGUI;
    }
    else
        exit(1);
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
    if (this->turn == 1) {
        this->turn = 2;
        this->activePlayer = playerTwo;
        this->activePlayer_GUI = playerTwoGUI;
    }
    else {
        this->turn = 1;
        this->activePlayer = playerOne;
        this->activePlayer_GUI = playerOneGUI;
    }
}

bool game::checkMill(Hole *hole){

    if (checkVerticalMill(hole) || checkHorizontalMill(hole)) {
        removePiece();
        return true;
    }
    return false;
}

bool game::checkVerticalMill(Hole *hole) {
    int vertCord = hole->getCol();
    int horCord = hole->getRow();
    int holeColor = hole->playerOwned;

    if(!(vertCord==3)){
        if(isHoleFilled(qFabs(6-vertCord),vertCord, holeColor) &&
                isHoleFilled(3,vertCord, holeColor) &&
                isHoleFilled(vertCord,vertCord, holeColor)){

            return true;
        }


    }
    else if(horCord > 3){
        if(isHoleFilled(6,vertCord, holeColor) &&
                isHoleFilled(5,vertCord, holeColor) &&
                isHoleFilled(4,vertCord, holeColor)){

            return true;
        }

    }
    else if(horCord < 3){
        if(isHoleFilled(2,vertCord, holeColor) &&
                isHoleFilled(1,vertCord, holeColor) &&
                isHoleFilled(0,vertCord, holeColor)){

            return true;
        }

    }


    return false;
}

bool game::checkHorizontalMill(Hole *hole) {
    int vertCord = hole->getCol();
    int horCord = hole->getRow();
    int holeColor = hole->playerOwned;

    if(!(horCord==3)){
        if(isHoleFilled(horCord ,qFabs(6-horCord), holeColor) &&
                isHoleFilled(horCord,3, holeColor) &&
                isHoleFilled(horCord,horCord, holeColor)){

            return true;
        }
    }
    else if(vertCord > 3){
        if(isHoleFilled(horCord,6, holeColor) &&
                isHoleFilled(horCord,5, holeColor) &&
                isHoleFilled(horCord,4, holeColor)){

            return true;
        }

    }
    else if(vertCord < 3){
        if(isHoleFilled(horCord,2, holeColor) &&
                isHoleFilled(horCord,1, holeColor) &&
                isHoleFilled(horCord,0, holeColor)){

            return true;
        }

    }



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

bool game::isHoleFilled(int row, int col, int playerTurn) {

    for (auto& hole : this->b->buttons) {
        if ((hole->getRow() == row) && (hole->getCol() == col)) {
            if (hole->playerOwned == playerTurn)
                return true;
            else
                return false;
        }
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

// TODO: Function still needs to be implemented
void game::removePiece(){
    //you get to remove a piece

}



