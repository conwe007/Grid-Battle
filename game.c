#include "game.h"

int main(int argc, char* argv[])
{
	grid_t* grid = initialize_grid();

	print_grid(grid);
	printf("\n");
	print_character_info(grid, 5);

	// for(int i = 0; i < NUM_POSITIONS; i++)
	// {
	// 	printf("%i: name: %s\n", i, grid->position[i]->name);
	// 	printf("%i: pos: %i\n", i, grid->position[i]->position);

	// 	printf("%i: job name: %s\n", i, grid->position[i]->job->name);
	// 	printf("%i: job health: %i\n", i, grid->position[i]->job->health);
	// 	printf("%i: job attack: %f\n", i, grid->position[i]->job->attack);
	// 	printf("%i: job defense: %f\n", i, grid->position[i]->job->defense);
	// 	printf("%i: job speed: %i\n", i, grid->position[i]->job->speed);

	// 	printf("%i: action name: %s\n", i, grid->position[i]->job->action[0]->name);
	// 	printf("%i: action name: %s\n", i, grid->position[i]->job->action[4]->name);
	// 	printf("%i: action name: %s\n", i, grid->position[i]->job->action[5]->name);

	// 	printf("\n");
	// }

	return 0;
}