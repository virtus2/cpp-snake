#include "snake.h"
#include "board.h"

void Snake::Init()
{
	// Set the length of snake by defined value in snake.h 
	length = SNAKE_LENGTH;
	// Initial position is (WIDTH / 2 , HEIGHT / 2)
	// position of (x, y) is equal to tile_map[y][x]
	int x = WIDTH / 2;
	int y = HEIGHT / 2;
	head = new body(x, y);
	tail = head->next = new body(x - 1, y);
	// Create more body until length to be SNAKE_LENGTH
	for (int i = 0; i < SNAKE_LENGTH - 1; i++)
	{
		tail = tail->next = new body(x - (i + 2), y);
	}
	tail->next = 0;
	// Default start direction is RIGHT
	dirct = RIGHT;
	
}

void Snake::SetDirection(int key)
{
	// if pressed opposite key return
	// else change direction
	switch (key)
	{
		case 72: 
			if (dirct == DOWN) 
				return;
			dirct = UP; 
			break; // UP ARROW key

		case 80: 
			if (dirct == UP)
				return;
			dirct = DOWN;
			break; // DOWN ARROW Key

		case 75: 
			if (dirct == RIGHT) 
				return;
			dirct = LEFT; 
			break; // LEFT ARROW Key

		case 77: 
			if (dirct == LEFT)
				return;
			dirct = RIGHT; 
			break; // RIGHT ARROW Key
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
			tail = tail->next = new body(tail->xpos, tail->ypos - 1);
			break;
		case DOWN: 
			tail = tail->next = new body(tail->xpos, tail->ypos + 1);
			break;
		case LEFT: 
			tail = tail->next = new body(tail->xpos + 1, tail->ypos);
			break;
		case RIGHT: 
			tail = tail->next = new body(tail->xpos - 1, tail->ypos);
			break;
	}
	tail->next = 0;
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
