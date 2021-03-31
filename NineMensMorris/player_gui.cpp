#include "player_gui.h"

player_GUI::player_GUI()
{

}

QWidget* player_GUI::CreatePlayerGUI(int player_color) {
    // Vertical Layout
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    // Title for the player
    QLabel *title;
    if (player_color == 1)
         title = new QLabel("Black");
    else if (player_color == 2)
        title = new QLabel("White");
    else // should never reach, crash if you do
        exit(1);
    QFont f("Arial", 20, QFont::Bold);
    title->setFont(f);
    title->setAlignment(Qt::AlignCenter);
    verticalLayout->addWidget(title);
    // Picture of color
    // Number of pieces
    pieces = new QLabel("9");
    pieces->setFont(f);
    pieces->setAlignment(Qt::AlignCenter);
    verticalLayout->addWidget(pieces);

    // Create a widget
    w = new QWidget();

    // Set the grid layout as a main layout
    w->setLayout(verticalLayout);

    return w;
}

void player_GUI::UpdatePlayerGUI(int numPieces) {
    // Update number of pieces
    pieces->setText(QString::number(numPieces));
}
