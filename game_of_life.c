#include "game_of_life.h"
#include "arrays.h"  // Needed for malloc_2d and free_2d
#include <stdio.h>

int game_of_life_rule(int row, int col, bool **grid, int width, int height) {
    int live_neighbors = 0;

    // Check all 8 neighbors
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) continue; // Skip the cell itself
            if (i >= 0 && i < height && j >= 0 && j < width) {
                if (grid[i][j]) live_neighbors++;
            }
        }
    }

    // Apply Conway's Game of Life rules
    if (grid[row][col]) {
        if (live_neighbors < 2 || live_neighbors > 3) return false; // Under/overpopulation
        else return true; // Lives on to next generation
    } else {
        if (live_neighbors == 3) return true; // Reproduction
        else return false; // Remains dead
    }
}

void next_generation(bool **grid, int width, int height) {
    bool **new_grid = malloc_2d(width, height);
    if (!new_grid) {
        fprintf(stderr, "Failed to allocate memory for next generation.\n");
        return;
    }

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            new_grid[row][col] = game_of_life_rule(row, col, grid, width, height);
        }
    }

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            grid[row][col] = new_grid[row][col];
        }
    }

    free_2d(new_grid, height);
}

void print_grid(bool **grid, int width, int height) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            printf("%c", grid[row][col] ? 'X' : '.');
        }
        printf("\n");
    }
}
