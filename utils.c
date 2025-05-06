#include "utils.h"
#include <stdlib.h>
#include <time.h>

void initialize_grid_random(bool **grid, int width, int height) {
    // Randomly initialize the grid
    srand(time(NULL));  // Seed the random number generator
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = rand() % 2;  // Randomly set each cell to 0 or 1
        }
    }
}

void initialize_grid_static(bool **grid, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = false;
        }
    }

    // Glider pattern in top-left corner
    if (height >= 3 && width >= 3) {
        grid[0][1] = true;
        grid[1][2] = true;
        grid[2][0] = true;
        grid[2][1] = true;
        grid[2][2] = true;
    }
}

