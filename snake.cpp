#include "snake.h"
#include "board.h" // for WIDTH, HEIGHT
void Snake::Init()
{
	// Set the length of snake by defined value in snake.h
	length = SNAKE_LENGTH;
	// Initial position is (WIDTH / 2 , HEIGHT / 2)
	int x = WIDTH / 2;
	int y = HEIGHT / 2;
	head = new body(x , y);
	head->next = new body(x-1 ,y);
	tail = head->next->next = new body(x-2, y);
	// 3rd body(tail) <- 2nd body <- 1st body(head)
	
}
void Snake::Grow()
{
	// Position of new body is different by direction of snake
	switch (dirct)
	{
		case UP: 
			tail = new body(tail->xpos, tail->ypos + 1);
			break;
		case DOWN: 
			tail = new body(tail->xpos, tail->ypos - 1);
			break;
		case LEFT: 
			tail = new body(tail->xpos-1, tail->ypos);
			break;
		case RIGHT: 
			tail = new body(tail->xpos + 1, tail->ypos);
			break;
	}
	length++;
}

void Snake::Move()
{

}
