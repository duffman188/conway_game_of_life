/* 
Name
Date
Course
*/

/* You will need to implement the following helper functions in separate files as mentioned:

game_of_life.c:

next_generation(): Computes the next generation of the grid.

game_of_life_rule(): Determines the next state of a cell based on its neighbors.

print_grid(): Prints the grid to the console.


arrays.c:

malloc_2d(): Allocates memory for a 2D grid.

free_2d(): Frees memory for the 2D grid.


utils.c:

initialize_grid_random(): Initializes the grid with random live or dead cells.

initialize_grid_static(): Optionally, you could create this function to initialize the grid with a predefined static pattern.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game_of_life.h"
#include "arrays.h"
#include "utils.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./executable width height generations\n");
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int generations = atoi(argv[3]);

    // Allocate memory for the grid
    bool **grid = malloc_2d(width, height);
    if (grid == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize the grid (can be random or static)
    initialize_grid_static(grid, width, height);  // Or use initialize_grid_random(grid, width, height);

    // Run the game of life for the given number of generations
    for (int gen = 1; gen <= generations; gen++) {
        printf("Generation %d:\n", gen);
        print_grid(grid, width, height);
        next_generation(grid, width, height);
    }

    // Free allocated memory
    free_2d(grid, height);

    return 0;
}
