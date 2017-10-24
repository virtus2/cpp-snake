#ifndef SNAKE_BODY_H
#define SNAKE_BODY_H
typedef struct snake_body
{
	int index;
	int xpos;
	int ypos;
	snake_body* next;
	snake_body() {};
	snake_body(int x, int y) { xpos = x; ypos = y; }
}body;

#endif /* SNAKE_BODY_H */