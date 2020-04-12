#ifndef __ACTION_H
#define __ACTION_H

#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// contains data on an action
typedef struct
{
	char* name;				// name of the action
	int* current_position;	// list of valid positions for the initiator of the action
	int** target_position;	// list of valid target positions for the action based on the initiator's position
	int** move_position;	// list of valid positions for the initiator to move to based on the initiator's position
	int must_move;			// boolean, true if character must move to use the action, false otherwise
	int power;				// power applied to the target(s) of the action, negative power heals the target
} action_t;

// contains data on how the result of an action will affect the board
typedef struct
{
	int power_grid[NUM_POSITIONS];	// a scalar to be applied to each character's health
	int move_cells[NUM_MOVE_CELLS];	// a pair of cells whose positions are to be swapped
} result_t;

// general actions common to every job
action_t* initialize_action_move();
action_t* initialize_action_pass();

// actions belonging to the lancer job
action_t* initialize_action_stab();
action_t* initialize_action_sweep();
action_t* initialize_action_advance();
action_t* initialize_action_retreat();

// actions belonging to the zealot job
action_t* initialize_action_pray();
action_t* initialize_action_condemn();
action_t* initialize_action_smite();
action_t* initialize_action_bless();

// actions belonging to the jester job
action_t* initialize_action_mock();
action_t* initialize_action_foolery();
action_t* initialize_action_somersault();
action_t* initialize_action_puppetshow();

// calculates result struct for the specified action, returns result struct on success, NULL on failure
result_t* calculate_action_result(action_t* action, double skill, int current_position, int move_position);

// helper function, returns current position action index (different from current position) for specified action, INVALID if position is invalid
int current_position_index(action_t* action, int current_position);

// helper function, returns TRUE if current position is valid for specified action, FALSE otherwise
int current_position_is_valid(action_t* action, int current_position);

// helper function, returns TRUE if move position is valid for current position and specified action, FALSE otherwise
int move_position_is_valid(action_t* action, int current_position, int move_position);

// determines whether action will be a success based on character skill, returns SUCCESS on success, FAILURE on failure, ERROR on error
int action_success(double skill);

// determines whether a character will evade an action based on evasion, returns SUCCESS on success, FAILURE on failure, ERROR on error
int evade_success(double evasion);

// returns an array of target positions an action will affect based on the initiator's position
int* get_target_positions(action_t* action, int current_position);

// prints the array of target positions returned by get_target_positions(), returns SUCCESS on success, ERROR on error
int print_target_positions(action_t* action, int current_position);

// returns an array of move positions valid to an action based on the initiator's position
int* get_move_positions(action_t* action, int current_position);

// prints the array of move positions returned by get_move_positions(), returns SUCCESS on success, ERROR on error
int print_move_positions(action_t* action, int current_position);

// returns TRUE if action index is valid, FALSE otherwise
int action_index_is_valid(int action_index);

// prints info about action, returns SUCCESS on success, ERROR on error
int print_action_info(action_t* action, int action_index, int current_position);

// initializes a result struct containing the initializes a result struct containing the result of any action
result_t* initialize_result();

// debugging function, returns SUCCESS on success, ERROR on error
int print_result(result_t* result);

// bookkeeping functions
void free_action(action_t* action);
void free_result(result_t* result);

#endif