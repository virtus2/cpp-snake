#ifndef SNAKE_BODY_H
#define SNAKE_BODY_H
enum DIRECTION { UP, DOWN, LEFT, RIGHT };
typedef struct snake_body
{
	DIRECTION dirct;
	int xpos;
	int ypos;
	snake_body* next;
	snake_body() {};
	snake_body(int x, int y, DIRECTION dirct) { xpos = x; ypos = y; dirct = dirct; }
}body;

#endif /* SNAKE_BODY_H */