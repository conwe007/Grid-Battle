#include "game.h"

// runs the game
int runGame()
{
	srand(time(NULL));

	grid_t* grid = initializeGrid();
	printGrid(grid);
	printf("\n");

	// main game loop
	while(determineWinner(grid) == NO_WINNER)
	{
		int* character_turn_order = getCharacterTurnOrder(grid);

		for(int i = 0; i < NUM_POSITIONS; i++)
		{
			// left team (human player)
			if(getTeam(character_turn_order[i]) == LEFT_TEAM)
			{
				humanTurn(grid, character_turn_order[i]);
			}

			// right team (AI)
			else
			{
				aiTurn(grid, character_turn_order[i]);
			}

			printGrid(grid);
			printf("\n");
		}

		free(character_turn_order);
	}


	// end the game and print the winner
	if(determineWinner(grid) == LEFT_TEAM)
	{
		printf("Left team wins\n");
	} else if(determineWinner(grid) == RIGHT_TEAM)
	{
		printf("Right team wins\n");
	}

	freeGrid(grid);

	return 0;
}
