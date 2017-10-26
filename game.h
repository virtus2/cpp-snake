#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "snake.h"

class Game
{
	private:
	Board board;
	Snake snake;
	bool isRunning;
	bool isFoodOnMap;
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