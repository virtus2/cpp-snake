#include "snake.h"
#include "board.h" // for WIDTH, HEIGHT
void Snake::Init()
{
	// Set the length of snake by defined value in snake.h
	length = SNAKE_LENGTH;
	// Initial position is (WIDTH / 2 , HEIGHT / 2)
	// position of (x, y) is equal to tile_map[y][x]
	int x = WIDTH / 2;
	int y = HEIGHT / 2;
	head = new body(x , y, RIGHT);
	head->next = new body(x-1 ,y, RIGHT);
	tail = head->next->next = new body(x-2, y, RIGHT);
	// 3rd body(tail) <- 2nd body <- 1st body(head)
	
}
void Snake::Grow()
{
	// Position of new body is different by direction of snake
	switch (dirct)
	{
		case UP: 
			tail = new body(tail->xpos, tail->ypos - 1, UP);
			break;
		case DOWN: 
			tail = new body(tail->xpos, tail->ypos + 1, DOWN);
			break;
		case LEFT: 
			tail = new body(tail->xpos + 1, tail->ypos, LEFT);
			break;
		case RIGHT: 
			tail = new body(tail->xpos - 1, tail->ypos, RIGHT);
			break;
	}
	length++;
}

void Snake::SetDirection(int key)
{
	switch (key)
	{
		// UP-ARROW
		case 72: dirct = UP; break;
		case 80: dirct = DOWN; break;
		case 75: dirct = LEFT; break; 
		case 77: dirct = RIGHT; break;
	}
}

void Snake::Move()
{
	snake_body* current;
	current = head;
	switch (current->dirct)
	{
		case UP:
			current->ypos--;
			break;
		case DOWN:
			current->ypos++;
			break;
		case LEFT:
			current->xpos--;
			break;
		case RIGHT:
			current->xpos++;
			break;
	}
	current = current->next;
}
