#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QPixmap>
#include <QLabel>

struct coord
{
    int row;
    int column;
    
};

class Button : public QPushButton
{
    Q_OBJECT

private:
    coord coords;

public:
    int filled = false;
    int playerOwned = 0;
    Button();
    Button(int row, int column);
    void setCoords(int row, int column);
    int getRow();
    int getCol();
    void emptyHole();

    void activateImage(int player);
//public slots:
    void fillHole(int player);

};

#endif // BUTTON_H
