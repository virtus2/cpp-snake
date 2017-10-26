#include "board.h"
#include <random>
#include <time.h>
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
			tile_map[i][j].isHead = false;
			if (j == 0 || j == WIDTH - 1) tile_map[i][j].isBorder = true;
			if (i == 0 || i == HEIGHT - 1) tile_map[i][j].isBorder = true;
		}
	}
	SetFood();
}

int Board::SetSnake(body* head)
{
	// Set snake on array, if success return 0
	// return -1 when snake head strikes against the wall or body
	body* current;
	current = head->next;
	tile_map[head->ypos][current->xpos].isHead = true;
	while (current)
	{
		tile_map[current->ypos][current->xpos].isSnake = true;
		if (tile_map[current->ypos][current->xpos].isBorder == tile_map[current->ypos][current->xpos].isSnake)
			return -1;
		if (tile_map[head->ypos][head->xpos].isSnake == true)
			return -1;
		current = current->next;
	}
	return 0;
}
// this function can be combined into SetSnake(body* head, bool b)
void Board::DeleteSnake(body* head)
{
	body* current;
	current = head->next;
	tile_map[head->ypos][current->xpos].isHead = false;
	while (current)
	{
		tile_map[current->ypos][current->xpos].isSnake = false;
		current = current->next;
	}
}

void Board::SetFood()
{
	srand((int)time(0));
	int yrand = rand() % (HEIGHT - 1) + 1;
	int xrand = rand() % (WIDTH - 1) + 1;
	tile_map[yrand][xrand].hasFood = true;
}
