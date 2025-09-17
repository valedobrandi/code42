#define ALIVE 1

#include <stdlib.h>
#include <stdio.h>

int **init_board(int height, int width)
{
	int **board = malloc(height * sizeof(int *));
	for (int it = 0; it < height; it++)
	{
		board[it] = calloc(width, sizeof(int));
	}
	return board;
}

int count_cell(int **board, int height, int width, int y, int x)
{
	int count = 0;
	for (int dy = -1; dy <= 1; dy++)
	{
		for (int dx = -1; dx <= 1; dx++)
		{
			if (dx == 0 && dy == 0) continue;
			int ny = dy + y;
			int nx = dx + x;

			if (ny >= 0
				&& nx >= 0
				&& ny < height
				&& nx < width
				&& board[ny][nx]) count++;

		}
	}
	return count;
}

void free_board(int **board, int height)
{
	for (int i = 0; i < height; i++)
	{
		free(board[i]);
	}
	free(board);
}

int main(int ac, char **av)
{
	if (ac != 4) return 1;

	int width = atoi(av[1]);
	int height = atoi(av[2]), iters = atoi(av[3]);

	int **board = init_board(height, width);

	int px = 0, py = 0, pen = 0, ch;

	while((ch = getchar()) != EOF)
	{
		if (ch == 'x') pen = !pen;
		if (ch == 'w' && py > 0) py--;
		if (ch == 's' && py < height - 1) py++;
		if (ch == 'a' && px > 0) px--;
		if (ch == 'd' && px < width - 1) px++;
		if (pen) board[py][px] = ALIVE;
	}

	for (int i = 0; i < iters; i++)
	{
		int **newBoard = init_board(height, width);
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				int n = count_cell(board, height, width, y, x);
				if (board[y][x] ? (n == 2 || n == 3) : n == 3)
					newBoard[y][x] = ALIVE;
			}
		}
		free_board(board, height);
		board = newBoard;
	}
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			putchar(board[y][x] ? 'O' : ' ');
		}
		putchar('\n');
	}
	free_board(board, height);
	return 0;
}