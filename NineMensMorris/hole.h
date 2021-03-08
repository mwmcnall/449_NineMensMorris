#ifndef HOLE_H
#define HOLE_H

#include <QObject>

class hole : QObject
{
// variables
public:
    //value if hole has piece. 0 for no, 1 for yes
    int filled;
    //value if hole is filled, which player has piece. 0 for none, 1 for player 1, 2 for player 2.
    int playerOwned;

// methods
public:
   hole();
   void emptyHole();
   void fillHole(int player);
};

#endif // HOLE_H
