#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

struct coord
{
    int row;
    int column;
    
};

class Button : public QPushButton
{
private:
    coord coords;

public:
    int filled;
    int playerOwned;
    Button();
    Button(int row, int column);
    void setCoords(int row, int column);
    int getRow();
    int getCol();
    void emptyHole();
    void fillHole(int player);

};

#endif // BUTTON_H
