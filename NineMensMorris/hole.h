#ifndef HOLE_H
#define HOLE_H

#include <QPushButton>
#include <QPixmap>
#include <QLabel>

struct coord
{
    int row;
    int column;
};

class Hole : public QPushButton
{
    Q_OBJECT

private:
    coord coords;
    void activateImage(int player);

public:
    int filled = false;
    int playerOwned = 0;
    Hole();
    Hole(int row, int column);
    void setCoords(int row, int column);
    int getRow();
    int getCol();
    void emptyHole();
    void fillHole(int player);

};

#endif // HOLE_H
