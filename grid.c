#include "grid.h"

grid_t* initialize_grid()
{
	grid_t* grid = (grid_t*)malloc(sizeof(grid_t));

	char name[NAME_SIZE_CHARACTER];

	for(int i = 0; i < NUM_POSITIONS; i++)
	{
		snprintf(name, NAME_SIZE_CHARACTER, "player%i", i);
		grid->position[i] = initialize_character(name, i, "Lancer");
	}

	return grid;
}

void print_grid(grid_t* grid)
{
	// horizontal line of dashes
	for(int i = 0; i < (GRID_SIZE_CELL * 4) + GRID_SIZE_WHITESPACE + 6; i++)
	{
		printf("%c", DASH);
	}
	printf("\n");
	
	// character 0-3 names
	printf("|%-*s|%-*s|%*c|%-*s|%-*s|\n", GRID_SIZE_CELL, grid->position[0]->name, GRID_SIZE_CELL, grid->position[1]->name, GRID_SIZE_WHITESPACE, BLANK, GRID_SIZE_CELL, grid->position[2]->name, GRID_SIZE_CELL, grid->position[3]->name);

	// character 0-3 jobs
	printf("|%-*s|%-*s|%*c|%-*s|%-*s|\n", GRID_SIZE_CELL, grid->position[0]->job->name, GRID_SIZE_CELL, grid->position[1]->job->name, GRID_SIZE_WHITESPACE, BLANK, GRID_SIZE_CELL, grid->position[2]->job->name, GRID_SIZE_CELL, grid->position[3]->job->name);

	// character 0-3 health
	printf("|%s%-*i|%s%-*i|%*c|%s%-*i|%s%-*i|\n", STRING_HEALTH, GRID_SIZE_HEALTH, grid->position[0]->job->health, STRING_HEALTH, GRID_SIZE_HEALTH, grid->position[1]->job->health, GRID_SIZE_WHITESPACE, BLANK, STRING_HEALTH, GRID_SIZE_HEALTH, grid->position[2]->job->health, STRING_HEALTH, GRID_SIZE_HEALTH, grid->position[3]->job->health);

	// horizontal line of dashes
	for(int i = 0; i < (GRID_SIZE_CELL * 4) + GRID_SIZE_WHITESPACE + 6; i++)
	{
		printf("%c", DASH);
	}
	printf("\n");

	// character 4-7 names
	printf("|%-*s|%-*s|%*c|%-*s|%-*s|\n", GRID_SIZE_CELL, grid->position[4]->name, GRID_SIZE_CELL, grid->position[5]->name, GRID_SIZE_WHITESPACE, BLANK, GRID_SIZE_CELL, grid->position[6]->name, GRID_SIZE_CELL, grid->position[7]->name);

	// character 4-7 jobs
	printf("|%-*s|%-*s|%*c|%-*s|%-*s|\n", GRID_SIZE_CELL, grid->position[4]->job->name, GRID_SIZE_CELL, grid->position[5]->job->name, GRID_SIZE_WHITESPACE, BLANK, GRID_SIZE_CELL, grid->position[6]->job->name, GRID_SIZE_CELL, grid->position[7]->job->name);

	// character 4-7 health
	printf("|%s%-*i|%s%-*i|%*c|%s%-*i|%s%-*i|\n", STRING_HEALTH, GRID_SIZE_HEALTH, grid->position[4]->job->health, STRING_HEALTH, GRID_SIZE_HEALTH, grid->position[5]->job->health, GRID_SIZE_WHITESPACE, BLANK, STRING_HEALTH, GRID_SIZE_HEALTH, grid->position[6]->job->health, STRING_HEALTH, GRID_SIZE_HEALTH, grid->position[7]->job->health);

	// horizontal line of dashes
	for(int i = 0; i < (GRID_SIZE_CELL * 4) + GRID_SIZE_WHITESPACE + 6; i++)
	{
		printf("%c", DASH);
	}
	printf("\n");
}

void print_character_info(grid_t* grid, int position)
{
	printf("-----Character Info-----\n");
	printf("%-*s%s\n", INFO_SIZE_STAT, STRING_NAME, grid->position[position]->name);
	printf("%-*s%s\n", INFO_SIZE_STAT, STRING_JOB, grid->position[position]->job->name);
	printf("%-*s%i\n", INFO_SIZE_STAT, STRING_HEALTH, grid->position[position]->job->health);
	printf("%-*s%i\n", INFO_SIZE_STAT, STRING_ATTACK, (int)grid->position[position]->job->attack);
	printf("%-*s%i\n", INFO_SIZE_STAT, STRING_DEFENSE, (int)grid->position[position]->job->defense);
	printf("%-*s%i\n", INFO_SIZE_STAT, STRING_SPEED, grid->position[position]->job->speed);

	for(int i = 0; i < NUM_ACTIONS; i++)
	{
		if(grid->position[position]->job->action[i] != NULL)
		{
			printf("%s%i: %s\n", STRING_ACTION, i, grid->position[position]->job->action[i]->name);

		}
	}
}