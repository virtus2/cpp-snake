#include "game.h"
#include <cstdio>
#include <conio.h> // for kbhit
#include <Windows.h>
void Game::Init()
{
	board.Init();
	snake.Init();
	board.SetSnake(snake.GetHead());
	board.SetFood();
	isFoodOnMap = true;
	isRunning = true;
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
void Game::ClearScreen()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void Game::Update()
{
	board.DeleteSnake(snake.GetHead());
	snake.Move();
	if (!isFoodOnMap)
	{
		board.SetFood();
		isFoodOnMap = true;
	}
	if (board.SetSnake(snake.GetHead()) != 0)
	{
		GameOver();
	}
	if (board.tile_map[snake.GetHead()->ypos][snake.GetHead()->xpos].hasFood)
	{
		snake.Grow();
		board.tile_map[snake.GetHead()->ypos][snake.GetHead()->xpos].hasFood = false;
		isFoodOnMap = false;
	}
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
	while (isRunning)
	{
		// input
		Input();
		Update();
		Sleep(100);
		ClearScreen();// Game speed? flickering issue with system("cls")
		Input(); // Input latency issue?
		Render();
		if (isRunning == false)
			printf("\nGAME OVER!\n\n");
	}
}

void Game::GameOver()
{
	isRunning = false;
}