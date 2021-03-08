#include "hole.h"

hole::hole()
{
public:
	//value if hole has piece. 0 for no, 1 for yes
	int open;
	//value if hole is filled, which player has piece. 0 for none, 1 for player 1, 2 for player 2.
	int playerOwned;

	void emptyHole() {
		open = 0;
	}
}