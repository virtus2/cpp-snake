#include "board.h"

void Board::Init()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			tile_map[i][j].xpos = i;
			tile_map[i][j].ypos = j;
			tile_map[i][j].hasFood = false;
		}
	}
}