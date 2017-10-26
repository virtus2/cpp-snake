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
	tail->next = 0;
	// 3rd body(tail) <- 2nd body <- 1st body(head)
	// Start Direction is RIGHT
	dirct = RIGHT;
	
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

body * Snake::GetHead()
{
	return this->head;
}

void Snake::Grow()
{
	// Position of new body is different by direction of snake
	switch (dirct)
	{
		case UP: 
			tail = tail->next = new body(tail->xpos, tail->ypos - 1, UP);
			break;
		case DOWN: 
			tail = tail->next = new body(tail->xpos, tail->ypos + 1, DOWN);
			break;
		case LEFT: 
			tail = tail->next = new body(tail->xpos + 1, tail->ypos, LEFT);
			break;
		case RIGHT: 
			tail = tail->next = new body(tail->xpos - 1, tail->ypos, RIGHT);
			break;
	}
	length++;
}



void Snake::Move()
{
	// Save previous position of the snake's head, body
	int xprev = head->xpos;
	int yprev = head->ypos;
	// Save previous position for update xpre, yprev
	int xtemp, ytemp;
	body* current = head->next;
	switch (dirct)
	{
		case UP:
			head->ypos--;
			break;
		case DOWN:
			head->ypos++;
			break;
		case LEFT:
			head->xpos--;
			break;
		case RIGHT:
			head->xpos++;
			break;
	}
	while (current)
	{
		xtemp = current->xpos;
		ytemp = current->ypos;
		current->xpos = xprev;
		current->ypos = yprev;
		xprev = xtemp;
		yprev = ytemp;
		current = current->next;
	}
}