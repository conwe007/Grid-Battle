#ifndef __CHARACTER_H
#define __CHARACTER_H

#include "constants.h"
#include "job.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char* name;
	int position;
	job_t* job;
} character_t;

// initializes a character witch custom name, position, and job
character_t* initialize_character(char* name, int position, char* job);

//bookkeeping function
void free_character(character_t* character);

#endif