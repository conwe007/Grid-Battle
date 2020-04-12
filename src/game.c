#include "game.h"

int main(int argc, char* argv[])
{
	srand(time(NULL));

	grid_t* grid = initialize_grid();
	print_grid(grid);
	printf("\n");

	// main game loop
	while(determine_winner(grid) == NO_WINNER)
	{
		int* character_turn_order = get_character_turn_order(grid);

		for(int i = 0; i < NUM_POSITIONS; i++)
		{
			// left team (human player)
			if(get_team(character_turn_order[i]) == LEFT_TEAM)
			{
				human_turn(grid, character_turn_order[i]);
			}

			// right team (AI)
			else
			{
				ai_turn(grid, character_turn_order[i]);
			}

			print_grid(grid);
			printf("\n");
		}

		free(character_turn_order);
	}


	// end the game and print the winner
	if(determine_winner(grid) == LEFT_TEAM)
	{
		printf("Left team wins\n");
	} else if(determine_winner(grid) == RIGHT_TEAM)
	{
		printf("Right team wins\n");
	}

	free_grid(grid);

	return 0;
}