#include "board.h"

void Board::Init()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			tile_map[i][j].xpos = i;
			tile_map[i][j].ypos = j;
			tile_map[i][j].isBorder = false;
			tile_map[i][j].hasFood = false;
			tile_map[i][j].isSnake = false;
			if (j == 0 || j == WIDTH - 1) tile_map[i][j].isBorder = true;
			if (i == 0 || i == HEIGHT - 1) tile_map[i][j].isBorder = true;
		}
	}
	for (int i = 0; i < HEIGHT; i++)
	{

	}
}

void Board::SetSnake(body* head)
{
	body* current;
	current = head;
	while (current)
	{
		tile_map[current->ypos][current->xpos].isSnake = true;
		current = current->next;
	}
}

void Board::DeleteSnake(body* head)
{
	body* current;
	current = head;
	while (current)
	{
		tile_map[current->ypos][current->xpos].isSnake = false;
		current = current->next;
	}
}

