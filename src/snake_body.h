#ifndef SNAKE_BODY_H
#define SNAKE_BODY_H
enum DIRECTION { UP, DOWN, LEFT, RIGHT };
typedef struct snake_body
{
	int xpos, xprev;
	int ypos, yprev;
	snake_body* next;
	snake_body() {};
	snake_body(int x, int y) { xpos = x; ypos = y;}
}body;

#endif /* SNAKE_BODY_H */