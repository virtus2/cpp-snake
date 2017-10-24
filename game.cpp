#include "game.h"
#include <cstdio>
#include <conio.h> // for kbhit
#include <Windows.h>
void Game::Init()
{
	board.Init();
	snake.Init();
	isRunning = false;
}

void Game::Input()
{
	if (kbhit())
	{
		int key = getch();
		if (key) key = getch(); 
		snake.SetDirection(key);
	}
}

void Game::Update()
{

}

void Game::Render()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			printf("бр");
		}
		printf("\n");
	}
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
