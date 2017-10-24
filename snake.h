#ifndef SNAKE_H
#define SNAKE_H
#include "snake_body.h"
#define SNAKE_LENGTH 3
enum direction { UP, DOWN, LEFT, RIGHT };
class Snake
{
	private:
	int length;
	body* head;
	body* tail;
	direction dirct;

	public:
	void Init();
	void Grow();
	void Move();
};
#endif /* SNAKE_H */