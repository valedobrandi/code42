#define ALIVE 1
#define DEAD 0

#include <stdio.h>
#include <stdlib.h>

int **alloc_board(int width, int height)
{   
    int **board = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) board[i] = calloc(width, sizeof(int));
    return board; 
}


int count_neighbors(int **board, int width, int height, int x, int y)
{
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx, ny = y + dy;
            if (nx >= 0
                && ny >= 0
                && nx < width
                && ny < height
                && board[ny][nx]
            ) count++;
        }
    }
    return count;
}

void free_board(int **board, int height)
{
    for (int i = 0; i < height; i++) {
        free(board[i]);
    }
    free(board);
}

int main( int ac, char **av)
{
    if (ac != 4) return 1;

    int width = atoi(av[1]), height = atoi(av[2]), iters = atoi(av[3]);

    int **board = alloc_board(width, height);
    int px = 0, py = 0, pen = 0, ch;

    while ((ch = getchar()) != EOF)
    {
        if (ch == 'x') pen = !pen;
        if (ch == 'w' && py > 0) py--;
        if (ch == 'a' && px > 0) px--;
        if (ch == 's' && py < height - 1) py++;
        if (ch == 'd' && px < width - 1) px++;
        if (pen) board[py][px] = ALIVE; 
    }

    for (int t = 0; t < iters; t++)
    {
        int **newBoard = alloc_board(width, height);

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int n = count_neighbors(board, width, height, x, y);
                if (board[y][x] ? (n == 2 || n == 3) : (n == 3))
                    newBoard[y][x] = ALIVE;
            }
        }
        free_board(board, height);
        board = newBoard;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            putchar(board[y][x] ? 'O' : ' ');
        }
        putchar('\n');
    }
    free_board(board, height);
    return 0;
}