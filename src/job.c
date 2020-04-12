#include "job.h"

// initializes lancer job
job_t* initialize_job_lancer()
{
	job_t* lancer = (job_t*)malloc(sizeof(job_t));

	lancer->name = (char*)malloc(sizeof(char) * NAME_SIZE_JOB);
	strcpy(lancer->name, "Lancer");

	lancer->health = 30;
	lancer->skill = 5.0;
	lancer->evasion = 5.0;
	lancer->speed = 5;

	lancer->action[0] = initialize_action_stab();
	lancer->action[1] = initialize_action_sweep();
	lancer->action[2] = initialize_action_advance();
	lancer->action[3] = initialize_action_retreat();
	lancer->action[4] = initialize_action_move();
	lancer->action[5] = initialize_action_pass();

	return lancer;
}

// initializes zealot job
job_t* initialize_job_zealot()
{
	job_t* zealot = (job_t*)malloc(sizeof(job_t));

	zealot->name = (char*)malloc(sizeof(char) * NAME_SIZE_JOB);
	strcpy(zealot->name, "Zealot");

	zealot->health = 25;
	zealot->skill = 5.0;
	zealot->evasion = 5.0;
	zealot->speed = 7;

	zealot->action[0] = initialize_action_pray();
	zealot->action[1] = initialize_action_condemn();
	zealot->action[2] = initialize_action_smite();
	zealot->action[3] = initialize_action_bless();
	zealot->action[4] = initialize_action_move();
	zealot->action[5] = initialize_action_pass();

	return zealot;
}

// initializes jester job
job_t* initialize_job_jester()
{
	job_t* jester = (job_t*)malloc(sizeof(job_t));

	jester->name = (char*)malloc(sizeof(char) * NAME_SIZE_JOB);
	strcpy(jester->name, "Jester");

	jester->health = 20;
	jester->skill = 5.0;
	jester->evasion = 8.0;
	jester->speed = 9;

	jester->action[0] = initialize_action_mock();
	jester->action[1] = initialize_action_foolery();
	jester->action[2] = initialize_action_somersault();
	jester->action[3] = initialize_action_puppetshow();
	jester->action[4] = initialize_action_move();
	jester->action[5] = initialize_action_pass();

	return jester;
}

// prints available moveset for job, returns SUCCESS on success, ERROR on error
int print_job_moveset(job_t* job, int position)
{
	if(job == NULL)
	{
		fprintf(stderr, "error: job is null\n");
		return ERROR;
	}

	for(int i = 0; i < NUM_ACTIONS; i++)
	{
		if((job->action[i] != NULL) && (current_position_is_valid(job->action[i], position) == TRUE))
		{
			print_action_info(job->action[i], i, position);
		}
	}

	return SUCCESS;
}

// bookkeeping function
void free_job(job_t* job)
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
			free_action(job->action[i]);
		}
	}
	
	free(job);
}