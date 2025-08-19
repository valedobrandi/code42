#include <stdio.h>
#include <stdlib.h>

#define DEAD 0
#define ALIVE 1

// alloc_board: create a 2D board (height rows × width cols)
// Each cell initialized to 0 (DEAD)
int **alloc_board(int width, int height) {
    // allocate array of row pointers
    int **board = malloc(height * sizeof(int*));
    // allocate and zero each row
    for (int i = 0; i < height; i++) board[i] =  calloc(width, sizeof(int));

    return board;
}

// free_board: free the 2D array memory
void free_board(int **board, int height) {
    for (int i = 0; i < height; i++) free(board[i]);
    free(board);
}

// count_neighbors: count ALIVE cells around (x, y)
int count_neighbors(int **b, int width, int height, int x, int y) {
    int c = 0;
    // neighbor rows offset
    for (int dy = -1; dy <= 1; dy++) {
        // neighbor cols offset
        for (int dx = -1; dx <= 1; dx++) {
            // skip the cell itself
            if (!dx && !dy) continue;
            // neighbor coords
            int nx = x + dx, ny = y + dy;
            if (
                nx >= 0 // inside left bound
                && ny >= 0 // inside top bound
                && nx < width // inside right bound
                && ny < height // inside bottom bound
                && b[ny][nx] // neighbor is alive
            ) c++;
        }
    }
    return c;
}

int main(int ac, char **av) {
    if (ac != 4) return 1;
    int width = atoi(av[1]), height = atoi(av[2]), iters = atoi(av[3]);

    // Create board and setup pen position/state
    int **board = alloc_board(width, height);
    // pen position (column, row)
    px = 0, py = 0;
    // 0 = up, 1 = down
    pen = 0;
    // input char
    ch;

    while ((ch = getchar()) != EOF) {
        if (ch == 'x') pen = !pen; // toggle pen up/down
        else if (ch == 'w' && py > 0) py--;
        else if (ch == 'a' && px > 0) px--;
        else if(ch == 's' && py < height - 1) py++;
        else if (ch == 'd' && px < width - 1) px++;

        if (pen) board[py][px] = ALIVE; // draw if pen down
    }
    
    // Simulation phase: run Game of Life for `iters` steps
    for (int t = 0; t < iters; t++) {
        // next board state
        int **nb = alloc_board(width, height);
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++) {
                int n = count_neighbors(board, width, height, x, y);
                // Apply Conway's rules:
                if (board[y][x] ? (n == 2 || n == 3) : (n == 3))
                    nb[y][x] = ALIVE;
            }
        // discard old board
        free_board(board, height);
        // use new board
        board = nb;
    }

    // Print final board
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) putchar(board[y][x] ? 'O' : ' ');
        putchar('\n');
    }

    free_board(board, height);
    return 0;
}
