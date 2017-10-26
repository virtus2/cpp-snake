#ifndef BOARD_H
#define BOARD_H
#include "tile.h"
#include "snake.h"
#define WIDTH 20 // x position for snake body. default value is 20
#define HEIGHT 18 // y position for snake body. default value is 18
class Board
{
	public:
	Tile tile_map[18][20];// 2-dimensial array for game board (width * height)

	void Init();
	void SetSnake(body* head);
	void DeleteSnake(body* head);
};

#endif