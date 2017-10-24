#include "game.h"

void Game::Init()
{
	board.Init();
	snake.Init();
	isRunning = false;
}
void Game::Run()
{
	isRunning = true;

	while (isRunning)
	{
		// input
		// update 
		// render
	}
}