#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdbool.h>

bool **malloc_2d(int width, int height);
void free_2d(bool **grid, int height);

#endif // ARRAYS_H
