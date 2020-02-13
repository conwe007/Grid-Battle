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
	} else
	{
		character->job = NULL;
		fprintf(stderr, "error: job '%s' is unrecognized\n", job);
	}

	return character;
}

//bookkeeping function
void free_character(character_t* character)
{
	free(character->name);

	free_job(character->job);

	free(character);
}