#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QPushButton>
#include <QGridLayout>

class Board : public QObject
{
    Q_OBJECT
public:
    // Variables
    QVector<QPushButton*> buttons;
    // Methods
    explicit Board(QObject *parent = nullptr);
private:
    void CreateButtons();
    void AddButtonsToBoard(QGridLayout*);
    void HideButtons();
    void ButtonPress();
    void ConnectButtons();

signals:

};

#endif // BOARD_H
