#include <stdio.h>
#include <stdlib.h>

#define DEAD 0
#define ALIVE 1

int **alloc_board(int width, int height) {
    int **board = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) board[i] =  calloc(width, sizeof(int));
    return board;
}

void free_board(int **board, int height) {
    for (int i = 0; i < height; i++) free(board[i]);
    free(board);
}

int count_neighbors(int **b, int width, int height, int x, int y) {
    int c = 0;
    for (int dy = -1; dy <= 1; dy++)
        for (int dx = -1; dx <= 1; dx++) {
            if (!dx && !dy) continue;
            int nx = x + dx, ny = y + dy;
            if (
                nx >= 0 
                && ny >= 0
                && nx < width
                && ny < height
                && b[ny][nx] 
            ) c++;
        }
    return c;
}

int main(int ac, char **av) {
    if (ac != 4) return 1;
    int width = atoi(av[1]), height = atoi(av[2]), iters = atoi(av[3]);
    int **board = alloc_board(width, height), px = 0, py = 0, pen = 0, ch;

    while ((ch = getchar()) != EOF) {
        if (ch == 'x') pen = !pen;
        else if (ch == 'w' && py > 0) py--;
        else if (ch == 'a' && px > 0) px--;
        else if(ch == 's' && py < height - 1) py++;
        else if (ch == 'd' && px < width - 1) px++;

        if (pen) board[py][px] = ALIVE;
    }
    
    for (int t = 0; t < iters; t++) {
        int **nb = alloc_board(width, height);
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++) {
                int n = count_neighbors(board, width, height, x, y);
                if (board[y][x] ? (n == 2 || n == 3) : (n == 3))
                    nb[y][x] = ALIVE;
            }
        free_board(board, height);
        board = nb;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) putchar(board[y][x] ? 'O' : ' ');
        putchar('\n');
    }

    free_board(board, height);
    return 0;
}
