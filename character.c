#include "character.h"

// initializes a character witch custom name, position, and job
character_t* initialize_character(char* name, int position, char* job)
{
	character_t* character = (character_t*)malloc(sizeof(character_t));

	character->name = (char*)malloc(sizeof(char) * NAME_SIZE_CHARACTER);
	strcpy(character->name, name);

	character->position = position;

	if(!strcmp(job, "Lancer"))
	{
		character->job = initialize_job_lancer();
	} else if(!strcmp(job, "Zealot"))
	{
		character->job = initialize_job_zealot();
	} else if(!strcmp(job, "Jester"))
	{
		character->job = initialize_job_jester();
	} else
	{
		character->job = NULL;
		fprintf(stderr, "error: job '%s' is unrecognized\n", job);
	}

	return character;
}

// update character's health based on action with power being applied to it, returns SUCCESS normally, FAILURE if updated health <= 0
int update_health(character_t* character, int power)
{
	character->job->health = character->job->health - power;

	if(character->job->health <= 0)
	{
		return FAILURE;
	}

	return SUCCESS;
}

// returns TRUE if character has > 0 health, false otherwise
int is_alive(character_t* character)
{
	if(character->job->health > 0)
	{
		return TRUE;
	}

	return FALSE;
}

// returns an array with the index of each available action based on the character's current position
int* get_available_actions(character_t* character)
{
	// maximum size needed is 6 actions plus terminating -1
	int* action_index_array = (int*)malloc(sizeof(int) * (NUM_ACTIONS + 1));
	int index = 0;

	for(int i = 0; i < NUM_ACTIONS; i++)
	{
		// check if the character's position is valid for its action at action_index i
		if(current_position_is_valid(character->job->action[i], character->position))
		{
			action_index_array[index] = i;
			index++;
		}
	}

	// add terminating value to the end of the array
	action_index_array[index] = TERMINATE;

	return action_index_array;
}

// debugging function, prints action indexes of actions available to character at its current location, returns SUCCESS on success, ERROR on error
int print_available_actions(character_t* character)
{
	if(character == NULL)
	{
		fprintf(stderr, "error: character is null\n");
		return ERROR;
	}

	int* action_index_array = get_available_actions(character);
	int index = 0;

	printf("Available actions for Character '%s': ", character->name);
	while(action_index_array[index] != TERMINATE)
	{
		printf("%i ", action_index_array[index]);
		index++;
	}
	printf("\n");

	return SUCCESS;
}

// prints character name, job, health, skill, evasion, speed, moveset, returns SUCCESS on success, ERROR on error
int print_character_info(character_t* character, int position)
{
	if(character == NULL)
	{
		fprintf(stderr, "error: character is null\n");
		return ERROR;
	}

	printf("\t%-*s%s\n", INFO_SIZE_STAT, STRING_NAME, character->name);
	printf("\t%-*s%s\n", INFO_SIZE_STAT, STRING_JOB, character->job->name);
	printf("\t%-*s%i\n", INFO_SIZE_STAT, STRING_HEALTH, character->job->health);
	printf("\t%-*s%i\n", INFO_SIZE_STAT, STRING_SKILL, (int)character->job->skill);
	printf("\t%-*s%i\n", INFO_SIZE_STAT, STRING_EVASION, (int)character->job->evasion);
	printf("\t%-*s%i\n", INFO_SIZE_STAT, STRING_SPEED, character->job->speed);

	printf("Valid actions:\n");
	print_job_moveset(character->job, position);

	return SUCCESS;
}

//bookkeeping function
void free_character(character_t* character)
{
	if(character == NULL)
	{
		fprintf(stderr, "error: character is null\n");
		return;
	}

	free(character->name);

	free_job(character->job);

	free(character);
}