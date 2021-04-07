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

    if (_turn == 2) {
        this->activePlayer = playerTwo;
        this->activePlayer_GUI = playerTwoGUI;
    }
    else {
        this->activePlayer = playerOne;
        this->activePlayer_GUI = playerOneGUI;
    }

}

int game::getTurn() {
    return this->turn;
}

player* game::getActivePlayer() {
    return this->activePlayer;
}

// -- ButtonPress()
// -- This is what activates what any Hole is clicked on the board
void game::ButtonPress() {
    Hole *button = qobject_cast<Hole*>(sender());

    gameLoop(button, false);

}

// Where all the basic game logic is stored
void game::gameLoop(Hole* holeClicked, bool simulated) {

    Hole* button = holeClicked;
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
        if (button->filled == false  && this->activePlayer->inMill ==0) {
            //places piece from player one pool
            if(this->activePlayer->numPieces >= 1 ){
                this->activePlayer->placePiece();
                if (!simulated)
                    this->activePlayer_GUI->UpdatePlayerGUI(this->activePlayer->numPieces);
                this->activePlayer->checkPhase();
                button->fillHole(this->turn);


                //TODO: remove piece when gaining mill. Will most likely need to allow for a second button press? for checking pieces
                //possibly add 2 more game states, one for player one clicking on piece to remove, one for player two to click on piece to remove
                //also possibly too complicated. Will need to discuss further when other members are available
                   //may need help from gui peeps to understand what to remove

                if(checkMill(button)){
                    this->log->appendMessage("You got mill!");
                    qInfo() << "You got mill";
                    this->activePlayer->inMill = 1;
                    removePiece(button);
                }
                else{
                    this->incrementTurn();
                }
            }

        }
        else if (button->filled == true && !(button->playerOwned == this->turn)){
            removePiece(button);
            this->incrementTurn();
        }
    }

    //PHASE 2 CHECKS
   if(this->activePlayer->playerPhase == 2){
        //TODO phase 2 moving pieces
       if (button->filled == false) {
           // If there are any valid spots to move, set playerMoving to true
           // Otherwise do nothing
           playerMoving = true;
       } else if ((playerMoving == true) && (button->filled == true)) {
           // Is the spot clicked a valid move?

           // If so
                // Clear current spot
                // 'Move' to new spot
                // Check mill?
                // set playerMoving False
           // If not
                //

           playerMoving = false;
       }
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

Hole* game::getHole(int row, int col) {
    for (auto& hole : this->b->buttons) {
        if ((hole->getRow() == row) && (hole->getCol() == col))
            return hole;
    }

    // pre-condition of exiting hole not met, exit
    exit(1);
}



// -- SimualteButtonPress(int, int)
// -- Can simulate a button press based on a co-ordinate
void game::SimulateButtonPress(int row, int col) {
    Hole *button = getHole(row, col);

    gameLoop(button, true);
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
        this->log->appendMessage("--> White's Turn!");
    }
    else {
        this->turn = 1;
        this->activePlayer = playerOne;
        this->activePlayer_GUI = playerOneGUI;
        this->log->appendMessage("--> Black's Turn!");
    }
}

bool game::checkMill(Hole *hole){

    if (checkVerticalMill(hole) || checkHorizontalMill(hole)) {
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
void game::removePiece(Hole *button){
    int checkI=0;
    qInfo() << "REmoving";
    //Check removePiece is ready
    if(button->removeReady==1){
        //remove button
        qInfo() << "REmoving this piece?";
        //Turn them back to not ready
        for (int i =0; i < this->b->buttons.size(); i++ )
        {

           this->b->buttons[i]->removeReady = 0;
        }
        this->activePlayer->inMill = 0;


    }
    else{
        if(button->playerOwned == 1){
            qInfo() << button->playerOwned;
            qInfo() << "1";
            //select all white pieces
            for (int i =0; i < this->b->buttons.size(); i++ )
            {
                //Also turn piece into highlight
                if(this->b->buttons[i]->playerOwned==2)
                {
                    this->b->buttons[i]->removeReady = 1;
                    checkI++;
                }
            }

        }
        else if(button->playerOwned == 2){
            qInfo() << button->playerOwned;
            qInfo() << "2";
            //select all black pieces
            for (int i =0; i < this->b->buttons.size(); i++ )
            {
                //Also turn piece into highlight
                if(this->b->buttons[i]->playerOwned==1)
                {
                    this->b->buttons[i]->removeReady = 1;
                }
            }

        }

    }
    // qInfo() << button->playerOwned;
    //if not check who's turn

    //Highlight all the pieces to remove, all turn to into remove ready


}



