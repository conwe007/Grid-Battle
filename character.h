#ifndef __CHARACTER_H
#define __CHARACTER_H

#include "constants.h"
#include "job.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// contains data about a character
typedef struct
{
	char* name;		// character's name
	int position;	// character's current position on the grid
	job_t* job;		// character's job
} character_t;

// initializes a character witch custom name, position, and job
character_t* initialize_character(char* name, int position, char* job);

// update character's health based on action with power being applied to it, returns SUCCESS normally, FAILURE if updated health <= 0
int update_health(character_t* character, int power);

// returns TRUE if character has > 0 health, false otherwise
int is_alive(character_t* character);

// returns an array with the index of each available action based on the character's current position
int* get_available_actions(character_t* character);

// debugging function, prints action indexes of actions available to character at its current location, returns SUCCESS on success, ERROR on error
int print_available_actions(character_t* character);

// prints character name, job, health, skill, evasion, speed, returns SUCCESS on success, ERROR on error
int print_character_info(character_t* character, int position);

//bookkeeping function
void free_character(character_t* character);

#endif