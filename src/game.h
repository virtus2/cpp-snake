#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "snake.h"
#include <Windows.h>
class Game
{
	private:
	Board board;
	Snake snake;
	HANDLE hstdout;
	bool isRunning;
	bool isFoodOnMap;
	int score;

	void ClearScreen();
	void Input();
	void Update();
	void Render();
	void GameOver();

	public:
	void Init();
	void Run();
};
#endif