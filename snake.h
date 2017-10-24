#ifndef SNAKE_H
#define SNAKE_H
#include "snake_body.h"
#define SNAKE_LENGTH 3

class Snake
{
	private:
	int length;
	body* head;
	body* tail;
	DIRECTION dirct;

	public:
	void SetDirection(int key);
	void Init();
	void Grow();
	void Move();
	
};
#endif /* SNAKE_H */