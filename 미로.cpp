#include <stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100
#define MAZE_SIZE 10

typedef struct Mouse
{
	short x;
	short y;
}Mouse;

typedef struct Stack
{
	Mouse data[MAX_SIZE];
	int top;
}Stack;

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1','1','1','1','1'},
	{'m','0','0','0','1','0','0','0','0','1'},
	{'1','0','0','0','1','0','0','1','0','1'},
	{'1','0','1','1','1','0','0','1','0','1'},
	{'1','0','0','0','1','0','0','1','0','1'},
	{'1','0','1','0','1','0','0','1','0','1'},
	{'1','0','1','0','1','0','0','1','0','1'},
	{'1','0','1','0','1','0','0','1','0','1'},
	{'1','0','1','0','0','0','0','1','0','X'},
	{'1','1','1','1','1','1','1','1','1','1'} };

void init(Stack* p)
{
	p->top = -1;
}

int is_full(Stack* p)
{
	return (p->top == MAX_SIZE - 1);
}

int is_empty(Stack* p)
{
	return(p->top == -1);
}

void push(Stack* p, Mouse data)
{
	if (is_full(p))
	{
		printf("스택이 찼습니다.\n");
		return;
	}
	else
	{
		p->top++;
		p->data[p->top].x = data.x;
		p->data[p->top].y = data.y;
	}
}

Mouse pop(Stack* p)
{
	if (is_empty(p))
	{
		printf("스택이 비어있습니다.\n");
		exit(1);
	}
	return p->data[(p->top)--];
}

void FindWay(Stack* s, int x, int y)
{
	if (x<0 || y<0 || x>MAZE_SIZE || y>MAZE_SIZE)
		return;
	if (maze[x][y] != '1' && maze[x][y] != '.')
	{
		Mouse temp;
		temp.x = x;
		temp.y = y;

		push(s, temp);
	}
}

int main()
{
	Stack s;
	Mouse m;
	int i, j, x, y;

	init(&s);

	for (i = 0; i < MAZE_SIZE; i++)
	{
		for (j = 0; j < MAZE_SIZE; j++)
		{
			if (maze[i][j] == 'm')
			{
				m.x = i;
				m.y = j;
			}
		}
	}

	printf("미로\n");
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			if (maze[i][j] == '0') {
				printf("□");
			}
			else if (maze[i][j] == '1') {
				printf("■");
			}
			else {
				printf("%c", maze[i][j]);
			}
		}printf("\n");
	}

	printf("\n 이동 경로\n");
	printf("시작(%d,%d)->", m.x, m.y);

	while (maze[m.x][m.y] != 'X')
	{
		x = m.x;
		y = m.y;

		maze[x][y] = '.';

		FindWay(&s, x + 1, y);
		FindWay(&s, x - 1, y);
		FindWay(&s, x, y + 1);
		FindWay(&s, x, y - 1);

		if (is_empty(&s))
		{
			printf("이동경로를 찾을 수 없습니다.\n");
			return 0;
		}
		else
		{
			m = pop(&s);
			printf("(%d,%d)->", m.x, m.y);
		}
	}
	printf("도착\n");
	printf("탐색 성공\n");

	return 0;
}

