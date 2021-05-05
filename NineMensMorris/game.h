#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "board.h"
#include "mainwindow.h"

#include "player_gui.h"
#include "logwindow.h"

#define BLACK_PLAYER 1
#define WHITE_PLAYER 2
#define PHASE_ONE 1
#define PHASE_TWO 2
#define PHASE_THREE 3

class game : public QObject
{
// variables
public:
    Board* b;
    player_GUI* playerOneGUI;
    player_GUI* playerTwoGUI;
    LogWindow *log = new LogWindow();
private:
    int turn = -1;
    player* playerOne;
    player* playerTwo;
    player* activePlayer;
    player_GUI* activePlayer_GUI;

    bool playerMoving = false;
    Hole* movingHole = nullptr;
    Hole* flyingHole = nullptr;

    player* computerPlayer;

// methods
public:
    game();
    game(bool simulated);
    void setActivePlayer(int turn);
    int getTurn();
    void setTurn(int _turn);
    void gameLoop(Hole *, bool);
    void ConnectButtons();
    void SimulateButtonPress(int x, int y);
    Hole* getHole(int x, int y);
    player* getActivePlayer();

    void setComputerPlayer(int human_Color);
private:
    void ButtonPress();
    void incrementTurn();
    // Mill stuff
    bool checkMill(Hole *);
    bool checkVerticalMill(Hole *);
    bool checkHorizontalMill(Hole *);
    // Is valid checks
    bool isHoleFilled(int row, int col);
    bool isHoleFilled(int row, int col, int playerTurn);
    // Remove Piece
    void removePiece(Hole *, bool);
    // Move Piece
    int moveShift(int);
    bool validMoveCount(Hole *);
    bool doesHoleExist(int, int);
    bool isValidHoleMoveUp(int, int);
    bool isValidHoleMoveDown(int, int);
    bool isValidHoleMoveLeft(int, int);
    bool isValidHoleMoveRight(int, int);
    // Phases
    void phase_one(Hole *, bool simulated);
    void phase_two(Hole *, bool simulated);
    void phase_three(Hole *, bool simulated);
    //Computer Player

    void computerLoop(bool simulated);
    void computerPhaseOne(bool simulated);
    void computerPhaseTwo(bool simulated);
    void computerPhaseThree(bool simulated);
    Hole* computerChoice();
    void momentToFill(Hole* hole);
    void momentToUnfill(Hole* hole);
};

#endif // GAME_H
