#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct in
{
	int h;
	int w;
	int d;
}node;

int top;
int x, y;
int dd = 0;
int i = 2;


void init_stack(void)
{
	top = -1;
}

node stack[MAX];

void push(int h, int w, int d)
{
	if (top >= MAX - 1)
	{
		printf("Stack overflow\n");
		return;
	}
	top++;
	stack[top].h = x;
	stack[top].w = y;
	stack[top].d = dd;
}

node pop()
{
	if (top < 0)
	{
		printf("Stack underflow\n");
		node err = { -1,-1,-1 };
		return err;
	}
	return stack[top--];
}

int input_map[15][15] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0},
	{0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0},
	{0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0},
	{0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
	{0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0},
	{0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
	{0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0},
	{0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
	{0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0}, 
	{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int algoritm() {
	int x1[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	int y1[8] = { -1, 1, 0, -1, 1, -1, 0, 1 };
	int n;

	for (n = 0; n < 8; n++) {
		int x2 = x + x1[n];
		int y2 = y + y1[n];

		if (x2 >= 0 && x2 < 15 && y2 >= 0 && y2 < 15) {
			if (input_map[x2][y2] == 1) {
				x = x2;
				y = y2;
				return n;
			}
		}
	}
	return -1;
}

int main() {
	init_stack();
	node temp;
	int a;
	int b;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			printf("%d ", input_map[i][j]);
		}
		printf("\n");
	}

	for (a = 0; a < 15; a++) {
		for (b = 0; b < 15; b++) {
			if (input_map[a][b] == 1) {
				x = a; y = b;
				input_map[x][y] = i;
				push(x, y, 0);

				while (top != -1) {
					dd = algoritm();

					if (dd != -1) {
						input_map[x][y] = i;
						push(x, y, dd);     
					}
					else {
						temp = pop();
						x = temp.h;
						y = temp.w;
					}
				}
			}
		}
	}
	printf("\n\n");
	printf("---------------------------------\n");
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			printf("%d ", input_map[i][j]);
		}
		printf("\n");
	}
}