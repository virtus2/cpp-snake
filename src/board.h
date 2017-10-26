#ifndef BOARD_H
#define BOARD_H
#include "tile.h"
#include "snake.h"
#define WIDTH 20 // x position for map. default value is 20
#define HEIGHT 18 // y position for map. default value is 18
class Board
{
	public:
	Tile tile_map[18][20];// 2-dimensial array for game board (width * height)
	void Init();
	int SetSnake(body* head);
	void DeleteSnake(body* head);
	void SetFood();
};

#endif