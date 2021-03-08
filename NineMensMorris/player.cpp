#include "player.h"

player::player()
{
public:
	//initialize numPieces at 9?
	int numPieces;
	bool flyStatus;

	void placePiece() {
		//if (valid move) TODO: write check for valid move
		numPieces -= 1;
	}

	void checkFly() {
		if (numPieces == 3) {
			flyStatus = true;
		}
	}

}
