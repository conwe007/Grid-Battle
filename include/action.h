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
action_t* initializeActionMove();
action_t* initializeActionPass();

// actions belonging to the lancer job
action_t* initializeActionStab();
action_t* initializeActionSweep();
action_t* initializeActionAdvance();
action_t* initializeActionRetreat();

// actions belonging to the zealot job
action_t* initializeActionPray();
action_t* initializeActionCondemn();
action_t* initializeActionSmite();
action_t* initializeActionBless();

// actions belonging to the jester job
action_t* initializeActionMock();
action_t* initializeActionFoolery();
action_t* initializeActionSomersault();
action_t* initializeActionPuppetshow();

// calculates result struct for the specified action, returns result struct on success, NULL on failure
result_t* calculateActionResult(action_t* action, double skill, int current_position, int move_position);

// helper function, returns current position action index (different from current position) for specified action, INVALID if position is invalid
int currentPositionIndex(action_t* action, int current_position);

// helper function, returns TRUE if current position is valid for specified action, FALSE otherwise
int currentPositionIsValid(action_t* action, int current_position);

// helper function, returns TRUE if move position is valid for current position and specified action, FALSE otherwise
int movePositionIsValid(action_t* action, int current_position, int move_position);

// determines whether action will be a success based on character skill, returns SUCCESS on success, FAILURE on failure, ERROR on error
int actionSuccess(double skill);

// determines whether a character will evade an action based on evasion, returns SUCCESS on success, FAILURE on failure, ERROR on error
int evadeSuccess(double evasion);

// returns an array of target positions an action will affect based on the initiator's position
int* getTargetPositions(action_t* action, int current_position);

// prints the array of target positions returned by get_target_positions(), returns SUCCESS on success, ERROR on error
int printTargetPositions(action_t* action, int current_position);

// returns an array of move positions valid to an action based on the initiator's position
int* getMovePositions(action_t* action, int current_position);

// prints the array of move positions returned by get_move_positions(), returns SUCCESS on success, ERROR on error
int printMovePositions(action_t* action, int current_position);

// returns TRUE if action index is valid, FALSE otherwise
int actionIndexIsValid(int action_index);

// prints info about action, returns SUCCESS on success, ERROR on error
int printActionInfo(action_t* action, int action_index, int current_position);

// initializes a result struct containing the initializes a result struct containing the result of any action
result_t* initializeResult();

// debugging function, returns SUCCESS on success, ERROR on error
int printResult(result_t* result);

// bookkeeping functions
void freeAction(action_t* action);
void freeResult(result_t* result);

#endif