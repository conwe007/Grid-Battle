#ifndef __GRID_H
#define __GRID_H

#include "character.h"
#include "constants.h"

/*
 FR  FF      EF  ER
_____________________
|   |   |   |   |   |
| 0 | 1 |   | 2 | 3 |
|   |   |   |   |   |
---------------------
|   |   |   |   |   |
| 4 | 5 |   | 6 | 7 |
|   |   |   |   |   |
‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
*/

typedef struct
{
	character_t* position[NUM_POSITIONS];
} grid_t;

grid_t* initialize_grid();

void print_grid(grid_t* grid);
void print_character_info(grid_t* grid, int position);

#endif