#ifndef __JOB_H
#define __JOB_H

#include "action.h"
#include "constants.h"

// contains data about a job
typedef struct
{
	char* name;						// name of the job
	int health;						// base health stat of the job, character dies when this reaches 0
	double skill;					// base skill stat of the job, chance of action power being successfully applied
	double evasion;					// base evasion stat of the job, 
	int speed;						// base speed stat of the job
	action_t* action[NUM_ACTIONS];	// a list of actions available to the job
} job_t;

// initialization functions for each job
job_t* initialize_job_lancer();
job_t* initialize_job_zealot();
job_t* initialize_job_jester();

// prints moveset for job, returns SUCCESS on success, ERROR on error
int print_job_moveset(job_t* job, int position);

// bookkeeping function
void free_job(job_t* job);

#endif