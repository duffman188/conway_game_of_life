#include "arrays.h"
#include <stdlib.h>

bool **malloc_2d(int width, int height) {
    bool **grid = (bool **)malloc(height * sizeof(bool *));
    if (grid == NULL) {
        return NULL;  // Memory allocation failed
    }

    for (int i = 0; i < height; i++) {
        grid[i] = (bool *)malloc(width * sizeof(bool));
        if (grid[i] == NULL) {
            // Free previously allocated memory if allocation fails
            for (int j = 0; j < i; j++) {
                free(grid[j]);
            }
            free(grid);
            return NULL;
        }
    }
    return grid;
}

void free_2d(bool **grid, int height) {
    for (int i = 0; i < height; i++) {
        free(grid[i]);
    }
    free(grid);
}
