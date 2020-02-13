#include "job.h"

job_t* initialize_job_lancer()
{
	job_t* lancer = (job_t*)malloc(sizeof(job_t));

	lancer->name = (char*)malloc(sizeof(char) * NAME_SIZE_JOB);
	strcpy(lancer->name, "Lancer");

	lancer->health = 100;
	lancer->attack = 10.0;
	lancer->defense = 10.0;
	lancer->speed = 5;

	lancer->action[0] = initialize_action_stab();
	lancer->action[1] = NULL;
	lancer->action[2] = NULL;
	lancer->action[3] = NULL;
	lancer->action[4] = initialize_action_move();
	lancer->action[5] = initialize_action_pass();

	return lancer;
}

// bookkeeping function
void free_job(job_t* job)
{
	free(job->name);

	for(int i = 0; i < NUM_ACTIONS; i++)
	{
		free(job->action[i]);
	}
	
	free(job);
}