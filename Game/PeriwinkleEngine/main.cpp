#include "Game.h"

// Entry point for the game
int main()
{
	// Create an instance of the game
	Game *pGame = new Game("Periwinkle",800,600);

	// Start it
	pGame->Run();
    
	return 0;
}

// End of main.cpp