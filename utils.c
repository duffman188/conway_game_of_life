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
    // Initialize the grid to a known static pattern (e.g., a simple "blinker" pattern)
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = 0;  // Start with all dead cells
        }
    }

    // Example: Create a blinker pattern (a vertical line of three live cells)
    grid[1][1] = 1;
    grid[1][2] = 1;
    grid[1][3] = 1;
}
