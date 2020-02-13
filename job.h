#ifndef __JOB_H
#define __JOB_H

#include "action.h"
#include "constants.h"

typedef struct
{
	char* name;
	int health;
	double attack;
	double defense;
	int speed;
	action_t* action[NUM_ACTIONS];
} job_t;

// initialization functions for each job
job_t* initialize_job_lancer();

// bookkeeping function
void free_job(job_t* job);

#endif