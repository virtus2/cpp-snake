#ifndef SNAKE_H
#define SNAKE_H
#include "snake_body.h"
#define SNAKE_LENGTH 3 // length of snake at start

class Snake
{
	private:
	int length;
	body* head;
	body* tail;
	DIRECTION dirct;

	public:
	void SetDirection(int key);
	body* GetHead();
	void Init();
	void Grow();
	void Move();

	
};
#endif /* SNAKE_H */