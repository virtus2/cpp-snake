#ifndef BOARD_H
#define BOARD_H
#include "tile.h"
class Board
{
	private:
	const int width = 20; // x position for snake body. default value is 20
	const int height = 18; // y position for snake body. default value is 18
	Tile** tile_map;// 2-dimensial array for game board (width * height)

	public:
	Board();
	~Board();

	void Init();

};

#endif