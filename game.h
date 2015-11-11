#include <vector>
#include "player.h"
#include "hexBoard.h"

enum Agent {NOBODY, PLAYER, CPU}

class Game
{
public:
	Game(bool multi) {
		Board board = new hexBoard();
	}
	~Game(){
		delete board;
	}
	void drawBoard();
	void gameLoop();
	
};