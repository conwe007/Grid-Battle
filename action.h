#ifndef __ACTION_H
#define __ACTION_H

#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char* name;
	int* valid_position;
	int** target_position;
	int** move_position;
	double power;
} action_t;

// general actions common to every job
action_t* initialize_action_move();
action_t* initialize_action_pass();

// actions belonging to the lancer job
action_t* initialize_action_stab();
action_t* initialize_action_hook();
action_t* initialize_action_advance();
action_t* initialize_action_retreat();

// actions belonging to the zealot job


// actions belonging to the jester job


// bookkeeping function
void free_action(action_t* action);

// helper functions to determine target
int get_position_same_FR(int position);
int get_position_opposite_FR(int position);
int get_position_same_FF(int position);
int get_position_opposite_FF(int position);
int get_position_same_EF(int position);
int get_position_opposite_EF(int position);
int get_position_same_ER(int position);
int get_position_opposite_ER(int position);

#endif