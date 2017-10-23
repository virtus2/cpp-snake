#ifndef SNAKE_H
#define SNAKE_H
#include "snake_body.h"
enum direction { up, down, left, right };
class Snake
{
	private:
	int length;
	body* head;
	direction dirct;

	public:
	Snake();
	~Snake();
	void Grow();
	void Move();
};
#endif /* SNAKE_H */