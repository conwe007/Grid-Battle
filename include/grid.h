#ifndef __GRID_H
#define __GRID_H

#include "character.h"
#include "constants.h"
#include <stdio.h>
#include <stdlib.h>

/*
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

// contains data about a grid
typedef struct
{
	character_t* position[NUM_POSITIONS];	// an array containing all the characters on a grid and their respective positions
} grid_t;

// initializes each cell of the grid with a random class
grid_t* initialize_grid();

// provides i/o for human player to choose an action for character at position to perform, returns SUCCESS on success, FAILURE on invalid character, ERROR on error
int human_turn(grid_t* grid, int position);

// determines action that ai character at position will perform, returns SUCCESS on success, FAILURE on invalid character, ERROR on error
int ai_turn(grid_t* grid, int position);

// initiates action at action_index by character at position, with optional move_position (-1 if no move), returns SUCCESS on success, ERROR on ERROR
int perform_action(grid_t* grid, int position, int action_index, int move_position);

// returns LEFT_TEAM if index corresponds to the left team, RIGHT_TEAM if index corresponds to the right team, ERROR on error
int get_team(int position);

// uses characters by their speed stat to determine in what order they perform actions, returns an array of integer indexes (corresponding to the characters' indexes on the grid) in the order the characters will perform their actions, returns ERROR on error
int* get_character_turn_order(grid_t* grid);

// prints character turn order returned by get_character_turn_order(), returns SUCCESS on success, ERROR on error
int print_character_turn_order(grid_t* grid);

// determines the winner based on the current grid, returns 0 for no winner, 1 for left team, 2 for right team
int determine_winner(grid_t* grid);

// swaps 2 characters' positions on the grid
int swap_characters(grid_t* grid, int position0, int position1);

// prints grid state (player name, job, health for each cell), returns SUCCESS on success, ERROR on error
int print_grid(grid_t* grid);

// prints info about each character in the grid, returns SUCCESS on success, ERROR on error
int print_grid_info(grid_t* grid);

// bookkeeping function
void free_grid(grid_t* grid);

#endif