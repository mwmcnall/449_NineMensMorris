#include "game.h"
#include "board.h"
#include "player.h"
#include "hole.h"
#include<QDebug>
#include<QtMath>
#include<string>

// -- game(bool simulated)
// -- Initialization to all variables, activates a GUI element for Player to choose their color if not simulated
game::game(bool simulated) {
    this->playerOne = new player(BLACK_PLAYER);
    this->playerTwo = new player(WHITE_PLAYER);
    this->b = new Board;
    this->game_gui = new game_GUI();
    this->playerOneGUI = new player_GUI();
    this->playerTwoGUI = new player_GUI();

    if (!simulated)
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
    //TODO logic should allow for moving pieces when there is no more pieces

    // TODO: Need to figure out how to set the turn via the GUI before the board is built
    // Otherwise we need a check like this, which is inefficient
    if (this->turn == -1) {
        setTurn(this->game_gui->getTurn());
        setActivePlayer(this->game_gui->getTurn());
    }

    if (this->activePlayer->playerPhase == PHASE_ONE) {
        phase_one(button, simulated);
    }

    // ----- PHASE 2 -----
   if(this->activePlayer->playerPhase == PHASE_TWO){
        phase_two(button, simulated);
   }

   // ----- PHASE 3 -----
   if(this->activePlayer->playerPhase == PHASE_THREE){
        //TODO phase 3 fly
   }

   this->activePlayer->checkPhase();
}

void game::phase_one(Hole *hole, bool simulated) {
    // If hole is open and no mill has been formed
    if (hole->filled == false  && this->activePlayer->inMill ==0) {
        //places piece from player one pool
        if(this->activePlayer->numPieces >= 1 ){
            this->activePlayer->placePiece();
            this->log->appendMessage("--Piece placed at: (" +
                                     QString::number(hole->getRow()) + ", " +
                                     QString::number(hole->getCol())+ ")");
            if (!simulated)
                this->activePlayer_GUI->UpdatePlayerGUI(this->activePlayer->numPieces);
            hole->fillHole(this->turn);
            this->activePlayer->checkPhase();

            //TODO: remove piece when gaining mill. Will most likely need to allow for a second button press? for checking pieces
            //possibly add 2 more game states, one for player one clicking on piece to remove, one for player two to click on piece to remove
            //also possibly too complicated. Will need to discuss further when other members are available
               //may need help from gui peeps to understand what to remove

            if(checkMill(hole)){
                this->log->appendMessage("You got mill!");
                qInfo() << "You got mill";
                this->activePlayer->inMill = 1;
                this->activePlayer->removing = true;
                removePiece(hole, simulated);
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
        removePiece(hole, simulated);
        this->incrementTurn();
        this->activePlayer->removing = false;
    }
}

void game::phase_two(Hole *hole, bool simulated) {

    // NOTE: Turn is only incremented when move is finished
    // QUESTION: Is there ever no valid moves? Is game only over then?

    if (this->movingHole == nullptr)
        this->movingHole = hole;

    // If a previous move formed a mill and hole is filled by other player
    if (this->activePlayer->removing && hole->filled == true
            && !(hole->playerOwned == this->turn)) {
        // If hole forms a mill, can't remove it
        if (checkMill(hole)) {
            this->log->appendMessage("Can't remove piece! It forms a mill, try again");
            return;
        }
        this->log->appendMessage("Removing opponent's piece at (" +
                                 QString::number(hole->getRow()) + ", " +
                                 QString::number(hole->getCol())+ ")");
        hole->removeReady = true;
        removePiece(hole, simulated);
        this->activePlayer->removing = false;
        this->incrementTurn();
    }
    // Move piece logic
    else if ((this->movingHole->moveState)) {
        if (hole->filled == false) {
           // Move
           // Set hole to correct player image
           hole->fillHole(this->activePlayer->turn);
           this->log->appendMessage("Piece moved to (" +
                                    QString::number(hole->getRow()) + ", " +
                                    QString::number(hole->getCol())+ ")");
           // Set movingHole to nothing
           this->movingHole->emptyHole();
           this->movingHole->moveState = false;
           // Check if piece formed a mill in it's new position
           if(checkMill(hole)) {
               // Set flag, don't increment turn
               this->activePlayer->removing = true;
               this->log->appendMessage("Mill formed! Select an opponent's piece to remove");
               return;
           }
           incrementTurn();
        }
        else {
            this->log->appendMessage("Invalid move spot! Try again.");
        }
       }
    // If the hole is filled and the player owns it
    else if ((hole->filled == true) && (this->activePlayer->turn == hole->playerOwned)) {
       // If there are any valid spots to move, set playerMoving to true
       // Otherwise do nothing

       if (this->validMoveCount(hole)) {
           hole->moveState = true;
           this->movingHole = hole;
           this->log->appendMessage("Piece at ("+
                                    QString::number(hole->getRow()) + ", " +
                                    QString::number(hole->getCol())+ ")" +
                                    " can be moved!");
       }
       else
           return;
   }
}

bool game::validMoveCount(Hole *hole) {

    int row = hole->getRow(), col = hole->getCol();

    if (isValidHoleMoveUp(row, col))
        return true;
    else if (isValidHoleMoveDown(row, col))
        return true;
    else if (isValidHoleMoveLeft(row, col))
        return true;
    else if (isValidHoleMoveRight(row, col))
        return true;

    return false;
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
            if (hole->playerOwned == playerTurn && hole->filled)
                return true;
            else
                return false;
        }
    }

    // This means the pre-condition of sending in a valid location was not kept. Exit program.
    exit(1);
}

bool game::doesHoleExist(int row, int col) {
    for (auto& hole : this->b->buttons) {
        if ((hole->getRow() == row) && (hole->getCol() == col))
            return true;
    }

    return false;
}

int game::moveShift(int n) {
    if ((n == 0) || (n == 6))
        return 3;
    else if ((n == 1) || (n == 5))
        return 2;
    else if ((n == 2) || (n == 3) || (n == 4))
        return 1;

    exit(1);
}

// -- isValidHoleMoveUp(int, int)
// -- Returns true if hole above exists and is a valid move location
bool game::isValidHoleMoveUp(int row_check, int col_check) {

    row_check -= moveShift(col_check);

    // Outside of board? Always false
    if (row_check < 0)
        return false;

    if (doesHoleExist(row_check, col_check))
        return !isHoleFilled(row_check, col_check);
    else
        return false;
}

// -- isValidHoleMoveDown(int, int)
// -- Returns true if hole below exists and is a valid move location
bool game::isValidHoleMoveDown(int row_check, int col_check) {

    row_check += moveShift(col_check);

    // Outside of board? Always false
    if (row_check > BOARD_HEIGHT)
        return false;

    if (doesHoleExist(row_check, col_check))
        return !isHoleFilled(row_check, col_check);
    else
        return false;
}

// -- isValidHoleMoveLeft(int, int)
// -- Returns true if hole to the left exists and is a valid move location
bool game::isValidHoleMoveLeft(int row_check, int col_check) {

    col_check -= moveShift(row_check);

    // Outside of board? Always false
    if (col_check < 0)
        return false;

    if (doesHoleExist(row_check, col_check))
        return !isHoleFilled(row_check, col_check);
    else
        return false;
}

// -- isValidHoleMoveRight(int, int)
// -- Returns true if hole to the right exists and is a valid move location
bool game::isValidHoleMoveRight(int row_check, int col_check) {

    col_check += moveShift(row_check);

    // Outside of board? Always false
    if (col_check > BOARD_WIDTH)
        return false;

    if (doesHoleExist(row_check, col_check))
        return !isHoleFilled(row_check, col_check);
    else
        return false;
}

// TODO: still need to implement
void game::removePiece(Hole *button, bool simulated){
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

        if (!simulated) {
            if(this->activePlayer == this->playerOne) {
                playerTwoGUI->UpdatePlayerGUI(playerTwo->numPieces);
            }
            else {
                playerOneGUI->UpdatePlayerGUI(playerOne->numPieces);
            }
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



