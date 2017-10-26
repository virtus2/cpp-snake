#include "game.h"
#include <cstdio>
#include <conio.h> // for kbhit
#include <Windows.h>
void Game::Init()
{
	board.Init();
	snake.Init();
	board.SetSnake(snake.GetHead());
	isRunning = false;
}

void Game::Input()
{
	if (kbhit())
	{
		int key = getch();
		if (key) key = getch(); 
		// Need esc key process to turn off the game
		// if pressed esc key; isRunning = false;
		snake.SetDirection(key);
	}
}

void Game::Update()
{
		board.DeleteSnake(snake.GetHead());
		snake.Move();
		board.SetSnake(snake.GetHead());
		
}

void Game::Render()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (board.tile_map[i][j].isSnake)
				printf("бс");
			else if (board.tile_map[i][j].isBorder)
				printf("в╦");
			else if (board.tile_map[i][j].hasFood)
				printf("в╛");
			else
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
		Input();
		Update();
		Sleep(200); // Game speed ... flickering issue
		system("cls"); // Clear the console screen
		Render();
	}
}
