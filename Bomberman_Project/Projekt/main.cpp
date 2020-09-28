#include "Game.h"
#include "definitions.h"

int main()
{
	Game game(WINDOW_WIDTH, WINDOW_HEIGHT, "Bomberman");	
	game.Run();												
	return 0;																
}