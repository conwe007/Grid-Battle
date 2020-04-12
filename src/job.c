#include "job.h"

// initializes lancer job
job_t* initializeJobLancer()
{
	job_t* lancer = (job_t*)malloc(sizeof(job_t));

	lancer->name = (char*)malloc(sizeof(char) * NAME_SIZE_JOB);
	strcpy(lancer->name, "Lancer");

	lancer->health = 30;
	lancer->skill = 5.0;
	lancer->evasion = 5.0;
	lancer->speed = 5;

	lancer->action[0] = initializeActionStab();
	lancer->action[1] = initializeActionSweep();
	lancer->action[2] = initializeActionAdvance();
	lancer->action[3] = initializeActionRetreat();
	lancer->action[4] = initializeActionMove();
	lancer->action[5] = initializeActionPass();

	return lancer;
}

// initializes zealot job
job_t* initializeJobZealot()
{
	job_t* zealot = (job_t*)malloc(sizeof(job_t));

	zealot->name = (char*)malloc(sizeof(char) * NAME_SIZE_JOB);
	strcpy(zealot->name, "Zealot");

	zealot->health = 25;
	zealot->skill = 5.0;
	zealot->evasion = 5.0;
	zealot->speed = 7;

	zealot->action[0] = initializeActionPray();
	zealot->action[1] = initializeActionCondemn();
	zealot->action[2] = initializeActionSmite();
	zealot->action[3] = initializeActionBless();
	zealot->action[4] = initializeActionMove();
	zealot->action[5] = initializeActionPass();

	return zealot;
}

// initializes jester job
job_t* initializeJobJester()
{
	job_t* jester = (job_t*)malloc(sizeof(job_t));

	jester->name = (char*)malloc(sizeof(char) * NAME_SIZE_JOB);
	strcpy(jester->name, "Jester");

	jester->health = 20;
	jester->skill = 5.0;
	jester->evasion = 8.0;
	jester->speed = 9;

	jester->action[0] = initializeActionMock();
	jester->action[1] = initializeActionFoolery();
	jester->action[2] = initializeActionSomersault();
	jester->action[3] = initializeActionPuppetshow();
	jester->action[4] = initializeActionMove();
	jester->action[5] = initializeActionPass();

	return jester;
}

// prints available moveset for job, returns SUCCESS on success, ERROR on error
int printJobMoveset(job_t* job, int position)
{
	if(job == NULL)
	{
		fprintf(stderr, "error: job is null\n");
		return ERROR;
	}

	for(int i = 0; i < NUM_ACTIONS; i++)
	{
		if((job->action[i] != NULL) && (currentPositionIsValid(job->action[i], position) == TRUE))
		{
			printActionInfo(job->action[i], i, position);
		}
	}

	return SUCCESS;
}

// bookkeeping function
void freeJob(job_t* job)
{
	if(job == NULL)
	{
		fprintf(stderr, "error: job is null\n");
		return;
	}

	free(job->name);

	for(int i = 0; i < NUM_ACTIONS; i++)
	{
		if(job->action[i] != NULL)
		{
			freeAction(job->action[i]);
		}
	}
	
	free(job);
}