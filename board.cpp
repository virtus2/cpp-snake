#include "board.h"

Board::Board()
{
	tile_map = new Tile*[height];
	for (int i = 0; i < height; i++)
	{
		tile_map[i] = new Tile[width];
	}
}

void Board::Init()
{
	
}