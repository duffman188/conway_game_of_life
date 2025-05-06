/* 
Name La'Ron Latin
Date 05/06/2025

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game_of_life.h"
#include "arrays.h"
#include "utils.h"

int main(int argc, char *argv[]) {
    // Validate argument count
    if (argc != 4) {
        fprintf(stderr, "Usage: ./executable width height generations\n");
        return 1;
    }

    // Parse command-line arguments
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int generations = atoi(argv[3]);

    // Validate parsed values
    if (width <= 0 || height <= 0 || generations <= 0) {
        printf("Error: Width, height, and generations must be positive integers.\n");
        return 1;
    }

    // Allocate memory for the 2D grid
    bool **grid = malloc_2d(width, height);
    if (grid == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Initialize the grid (choose one)
    initialize_grid_static(grid, width, height);  // Default test-compatible pattern
    // initialize_grid_random(grid, width, height);  // Alternate: random pattern

    // Simulate the Game of Life for the given number of generations
    for (int gen = 1; gen <= generations; gen++) {
        printf("Generation %d:\n", gen);
        print_grid(grid, width, height);
        printf("\n");
        next_generation(grid, width, height);
    }

    // Free dynamically allocated memory
    free_2d(grid, height);
    return 0;
}
