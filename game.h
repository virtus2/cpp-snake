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

	public:
	void Init();
	void Run();
	void Input();
	void Update();
	void Render();
	void GameOver();
};
#endif