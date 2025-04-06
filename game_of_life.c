#include "game_of_life.h"
#include <stdio.h>

int game_of_life_rule(int row, int col, bool **grid, int width, int height) {
    // Implement the logic of the Game of Life rules here.
    // Return the next state for a given cell.
    // You'll need to count the live neighbors around the cell at (row, col).
    return 0;  // Placeholder: Update to reflect the rules.
}

void next_generation(bool **grid, int width, int height) {
    // Create a temporary grid to hold the next generation
    bool **new_grid = malloc_2d(width, height);

    // Apply game_of_life_rule to each cell
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            new_grid[row][col] = game_of_life_rule(row, col, grid, width, height);
        }
    }

    // Copy the new grid back to the original grid
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            grid[row][col] = new_grid[row][col];
        }
    }

    // Free the temporary grid
    free_2d(new_grid, height);
}

void print_grid(bool **grid, int width, int height) {
    // Print the current grid state
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (grid[row][col]) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}
