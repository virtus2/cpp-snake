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
	score = 0;
	hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Game::Input()
{
	if (kbhit())
	{
		int key = getch();
		if (key == 27)
		{ // if press escape key then quit 
			isRunning = false; 
			return;
		}
		if (key) key = getch();
		
		snake.SetDirection(key);
	}
}
void Game::ClearScreen()
{
	COORD Position;
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hstdout, Position);
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
		score++;
		board.tile_map[snake.GetHead()->ypos][snake.GetHead()->xpos].hasFood = false;
		isFoodOnMap = false;
	}
}

void Game::Render()
{
	printf("\n\nScore: %d\t Prees ESC to Quit\n", score);
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (board.tile_map[i][j].isSnake)
			{
				printf("¡á");
			}
			else if (board.tile_map[i][j].isBorder)
				printf("¢Ë");
			else if (board.tile_map[i][j].hasFood)
			{
				printf("¢¾");
			}
			else
				printf("  ");
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
		Sleep(135);
		ClearScreen(); 
		Render();
		if (isRunning == false)
			printf("\nGAME OVER!\n\n");
	}
}

void Game::GameOver()
{
	isRunning = false;
}