#include "game.h"
#include "board.h"
#include "player.h"
#include "hole.h"
#include<QDebug>
#include<QtMath>

// -- game()
// -- Initialization to all variables, activates a GUI element for Player to choose their color
game::game()
{
    this->playerOne = new player(BLACK_PLAYER);
    this->playerTwo = new player(WHITE_PLAYER);
    this->b = new Board;
    this->game_gui = new game_GUI();
    this->playerOneGUI = new player_GUI();
    this->playerTwoGUI = new player_GUI();

    game_gui->ChoosePlayerTurnGUI();
}

// -- getTurn()
// -- Returns private turn variable
int game::getTurn() {
    return this->turn;
}

// -- getActivePlayer()
// -- Returns private activePlayer pointer
player* game::getActivePlayer() {
    return this->activePlayer;
}

// -- setTurn()
// -- sets the private turn variables
// -- Also sets the active player and active player GUI as those depend on the turn
void game::setTurn(int _turn) {
    this->turn = _turn;

    setActivePlayer(_turn);

}

// -- setActivePlayer(int turn)
// -- Sets the activePlayer and activePlayer_GUI
// -- Both are pointers to objects used within the gameLoop
void game::setActivePlayer(int turn) {
    if (turn == BLACK_PLAYER) {
        this->activePlayer = this->playerOne;
        this->activePlayer_GUI = this->playerOneGUI;
    }
    else if (turn == WHITE_PLAYER) {
        this->activePlayer = this->playerTwo;
        this->activePlayer_GUI = this->playerTwoGUI;
    }
    else
        exit(1);
}

// -- incrementTurn()
// -- Changes from one player's turn to another
// Sets active player pointers and logs a message for the player
// letting them know what the active turn is
void game::incrementTurn() {
    if (this->turn == WHITE_PLAYER) {
        this->turn = BLACK_PLAYER;
        setActivePlayer(BLACK_PLAYER);
        this->log->appendMessage("--> Black's Turn!");
    }
    else {
        this->turn = WHITE_PLAYER;
        setActivePlayer(WHITE_PLAYER);
        this->log->appendMessage("--> White's Turn!");
    }
}


// -- ButtonPress()
// -- This is what activates what any Hole is clicked on the board
// -- Runs the gameLoop logic with the clicked button
void game::ButtonPress() {
    Hole *button = qobject_cast<Hole*>(sender());

    gameLoop(button, false);

}

// -- gameLoop(Hole *, bool)
// -- All the core game logic is stored here.
// -- Can be simulated
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

    if (this->activePlayer->playerPhase == 1) {
        phase_one(button, simulated);
    }

    // ----- PHASE 2 -----
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

   // ----- PHASE 3 -----
   if(this->activePlayer->playerPhase == 3){
        //TODO phase 3 fly
   }
}

void game::phase_one(Hole *hole, bool simulated) {
    // If hole is open and no mill has been formed
    if (hole->filled == false  && this->activePlayer->inMill ==0) {
        //places piece from player one pool
        if(this->activePlayer->numPieces >= 1 ){
            this->activePlayer->placePiece();
            if (!simulated)
                this->activePlayer_GUI->UpdatePlayerGUI(this->activePlayer->numPieces);
            this->activePlayer->checkPhase();
            hole->fillHole(this->turn);


            //TODO: remove piece when gaining mill. Will most likely need to allow for a second button press? for checking pieces
            //possibly add 2 more game states, one for player one clicking on piece to remove, one for player two to click on piece to remove
            //also possibly too complicated. Will need to discuss further when other members are available
               //may need help from gui peeps to understand what to remove

            if(checkMill(hole)){
                this->log->appendMessage("You got mill!");
                qInfo() << "You got mill";
                this->activePlayer->inMill = 1;
                this->activePlayer->removing = true;
                removePiece(hole);
            }
            else{
                this->incrementTurn();
            }
        }

    }
    // If the hole has been filled and the current player doesn't own it
        // and active player is in removing phase
    else if (hole->filled == true && !(hole->playerOwned == this->turn) &&
             (this->activePlayer->removing)){
        // TODO: Inefficient, it would be better to have a flag on Hole to check
            // instead of multiple for loops w/in checkMill
        // If trying to remove a piece from a mill, don't allow it
        if (checkMill(hole))
            return;
        removePiece(hole);
        this->incrementTurn();
        this->activePlayer->removing = false;
    }
}

// -- getHole(int row, int col)
// -- Returns a Hole* pointer based on the co-ordinate of the button
// -- Pre-condition: Must be a legal position on the board
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

// -- checkMill(Hole *)
// -- Returns true if this Hole is part of a mill
bool game::checkMill(Hole *hole){

    if (checkVerticalMill(hole) || checkHorizontalMill(hole)) {
        return true;
    }
    return false;
}

// -- checkVerticalMill(Hole *)
// -- Returns true if this Hole is part of a vertical mill
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

// -- checkHorizontalMill(Hole *)
// -- Returns true if this Hole is part of a Horizontal mill
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

// -- isHoleFilled(int row, int col)
// -- Returns true if this Hole exists and is filled
// -- Pre-condition: Must be a legal position on the board
bool game::isHoleFilled(int row, int col) {

    for (auto& hole : this->b->buttons) {
        if ((hole->getRow() == row) && (hole->getCol() == col))
            return hole->filled;
    }

    // This means the pre-condition of sending in a valid location was not kept. Exit program.
    exit(1);
}

// -- isHoleFilled(int row, int col)
// -- Returns true if this Hole exists, and is filled, and is owned by the corresponding player
// -- Pre-condition: Must be a legal position on the board
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


// -- isValidHoleMoveUp(int, int)
// -- Returns true if hole above exists and is a valid move location
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

// -- isValidHoleMoveDown(int, int)
// -- Returns true if hole below exists and is a valid move location
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

// -- isValidHoleMoveLeft(int, int)
// -- Returns true if hole to the left exists and is a valid move location
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

// -- isValidHoleMoveRight(int, int)
// -- Returns true if hole to the right exists and is a valid move location
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

// TODO: still need to implement
void game::removePiece(Hole *button){
    int checkI=0;
    qInfo() << "REmoving";
    //Check removePiece is ready
    if(button->removeReady==1){
        //remove button
        qInfo() << "Removing this piece?";
        //removes hole
        button->emptyHole();
        button->playerOwned = 0;
        //Turn them back to not ready

        for (int i =0; i < this->b->buttons.size(); i++ )
        {

           this->b->buttons[i]->removeReady = 0;
        }
        this->activePlayer->inMill = 0;

        // Need to increment pieces
        if(this->activePlayer == this->playerOne) {
            playerTwo->numPieces++;
            playerTwoGUI->UpdatePlayerGUI(playerTwo->numPieces);
        }
        else {
            playerOne->numPieces++;
            playerOneGUI->UpdatePlayerGUI(playerOne->numPieces);
        }

    }
    else{
        if(button->playerOwned == BLACK_PLAYER){
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
        else if(button->playerOwned == WHITE_PLAYER){
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



