#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <stdbool.h>

void print_grid(bool **grid, int width, int height);
void next_generation(bool **grid, int width, int height);
int game_of_life_rule(int row, int col, bool **grid, int width, int height);

#endif // GAME_OF_LIFE_H
