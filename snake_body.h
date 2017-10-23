#ifndef SNAKE_BODY_H
#define SNAKE_BODY_H
typedef struct snake_body
{
	int index;
	int xpos;
	int ypos;
	snake_body* next;
}body;

#endif /* SNAKE_BODY_H */