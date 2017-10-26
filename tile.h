#ifndef TILE_H
#define TILE_H
struct Tile
{
	int xpos;
	int ypos;
	bool hasFood;
	bool isSnake;
	bool isBorder;
	bool isHead;
};
#endif