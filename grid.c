#include "grid.h"

// initializes each cell of the grid with a random class
grid_t* initialize_grid()
{
	grid_t* grid = (grid_t*)malloc(sizeof(grid_t));

	char name[NAME_SIZE_CHARACTER];
	double random = 0.0;

	for(int i = 0; i < NUM_POSITIONS; i++)
	{
		random = (double)rand() / (double)RAND_MAX;
		snprintf(name, NAME_SIZE_CHARACTER, "player%i", i);

		if(random <= 0.333)
		{
			grid->position[i] = initialize_character(name, i, "Lancer");
		} else if(random > 0.333 && random <= 0.666)
		{
			grid->position[i] = initialize_character(name, i, "Zealot");
		} else
		{
			grid->position[i] = initialize_character(name, i, "Jester");
		}
	}

	return grid;
}

// provides i/o for human player to choose an action for character at position to perform, returns SUCCESS on success, FAILURE on invalid character, ERROR on error
int human_turn(grid_t* grid, int position)
{
	if(grid == NULL)
	{
		fprintf(stderr, "error: grid is null\n");
	}

	// do not give character a turn if they are dead
	if(is_alive(grid->position[position]) == FALSE)
	{
		return FAILURE;
	}

	int action_index = -1;
	char action_index_input[BUFFER_SIZE];
	memset(action_index_input, 0, sizeof(char) * BUFFER_SIZE);
	int action_index_valid = action_index_is_valid(action_index);
	int* available_action_array = get_available_actions(grid->position[position]);

	printf("Current character info:\n");
	print_character_info(grid->position[position], position);

	// loop until player selects valid action
	while(action_index_valid == FALSE)
	{
		printf("Select action (0 - 5): ");
		while(fgets(action_index_input, BUFFER_SIZE, stdin) == NULL)
		{
			printf("Incorrect input type, Select action (0 - 5): ");
		}
		action_index = atoi(action_index_input);
		printf("%i\n", action_index);

		// check selection against available actions at character's position
		int i = 0;
		while(available_action_array[i] != TERMINATE)
		{
			if(available_action_array[i] == action_index)
			{
				action_index_valid = TRUE;
			}

			i++;
		}

		if(action_index_valid == FALSE)
		{
			printf("Invalid action\n");
		}
	}

	printf("\n");

	int move_position = NO_MOVE;
	char move_position_input[BUFFER_SIZE];
	memset(move_position_input, 0, sizeof(char) * BUFFER_SIZE);
	int move_position_valid = move_position_is_valid(grid->position[position]->job->action[action_index], position, move_position);
	int* move_position_array = get_move_positions(grid->position[position]->job->action[action_index], position);
	
	// if the action requires character to move, have player select move position
	if(grid->position[position]->job->action[action_index]->must_move == TRUE)
	{
		move_position_valid = FALSE;
		
		print_move_positions(grid->position[position]->job->action[action_index], position);

		while(move_position_valid == FALSE)
		{
			printf("Select move position: ");
			while(fgets(move_position_input, BUFFER_SIZE, stdin) == NULL)
			{
				printf("Incorrect input type, Select move position: ");
			}
			move_position = atoi(move_position_input);

			int i = 0;
			while(move_position_array[i] != TERMINATE)
			{
				if(move_position_array[i] == move_position)
				{
					move_position_valid = TRUE;
				}

				i++;
			}

			if(move_position_valid == FALSE)
			{
				printf("Invalid move position\n");
			}
		}
	}

	free(available_action_array);
	free(move_position_array);

	// perform the action with player specified inputs
	return perform_action(grid, position, action_index, move_position);;
}

// determines action that ai character at position will perform, returns SUCCESS on success, FAILURE on invalid character, ERROR on error
int ai_turn(grid_t* grid, int position)
{
	if(grid == NULL)
	{
		fprintf(stderr, "error: grid is null\n");
	}

	// do not give character a turn if they are dead
	if(is_alive(grid->position[position]) == FALSE)
	{
		return FAILURE;
	}

	int action_index = -1;
	int* available_action_array = get_available_actions(grid->position[position]);

	// count how many available actions there are
	int available_action_count = 0;
	while(available_action_array[available_action_count] != TERMINATE)
	{
		available_action_count++;
	}

	action_index = available_action_array[rand() % available_action_count];

	printf("'%s' uses action '%s'\n", grid->position[position]->name, grid->position[position]->job->action[action_index]->name);

	int move_position = NO_MOVE;
	int* move_position_array = get_move_positions(grid->position[position]->job->action[action_index], position);
	
	// if the action requires character to move, have player select move position
	if(grid->position[position]->job->action[action_index]->must_move == TRUE)
	{
		// count how many possible move positions there are
		int move_position_count = 0;
		while(move_position_array[move_position_count] != TERMINATE)
		{
			move_position_count++;
		}

		// select a move position from the possibilities
		move_position = move_position_array[rand() % move_position_count];

		printf("'%s' moves to position '%i'\n", grid->position[position]->name, move_position);
	}

	free(available_action_array);
	free(move_position_array);

	// perform the action with player specified inputs
	return perform_action(grid, position, action_index, move_position);;
}

// initiates action at action_index by character at position, with optional move_position (-1 if no move), returns SUCCESS on success, ERROR on error
int perform_action(grid_t* grid, int position, int action_index, int move_position)
{
	if(position < 0 || position > 7)
	{
		fprintf(stderr, "error: position '%i' is not valid\n", position);
		return ERROR;
	}

	if(grid->position[position]->job->action[action_index] == NULL)
	{
		fprintf(stderr, "error: action at action index '%i' is not valid\n", action_index);
		return ERROR;
	}

	result_t* result = calculate_action_result(grid->position[position]->job->action[action_index], grid->position[position]->job->skill, position, move_position);
	if(result == NULL)
	{
		fprintf(stderr, "error: null result\n");
		return ERROR;
	}

	// apply the action power to the applicable cells in the grid
	for(int i = 0; i < NUM_POSITIONS; i++)
	{
		// for each action target position roll against the corresponding character's evasion stat
		if((result->power_grid[i] != 0) && (evade_success(grid->position[i]->job->evasion) == 0))
		{
			// if the character fails to evade, update their health
			update_health(grid->position[i], result->power_grid[i]);
			printf("Character '%s' took %i damage\n", grid->position[i]->name, result->power_grid[i]);
		} else
		{
			printf("Character '%s' avoided damage\n", grid->position[i]->name);
		}
	}

	// swap the two move cells if applicable
	if(result->move_cells[0] != NO_MOVE)
	{
		swap_characters(grid, result->move_cells[0], result->move_cells[1]);
	}

	free(result);

	return SUCCESS;
}

// returns LEFT_TEAM if index corresponds to the left team, RIGHT_TEAM if index corresponds to the right team, ERROR on error
int get_team(int position)
{
	if(position < 0 || position > 7)
	{
		fprintf(stderr, "error: position is invalid\n");
		return ERROR;
	}

	if((position & 2) == LEFT_TEAM)
	{
		return LEFT_TEAM;
	}

	return RIGHT_TEAM;
}

// uses characters by their speed stat to determine in what order they perform actions, returns an array of integer indexes (corresponding to the characters' indexes on the grid) in the order the characters will perform their actions, returns NULL on error
int* get_character_turn_order(grid_t* grid)
{
	if(grid == NULL)
	{
		fprintf(stderr, "error: grid is null\n");
		return NULL;
	}

	int* character_turn_order = (int*)malloc(sizeof(int) * NUM_POSITIONS);
	for(int i = 0; i < NUM_POSITIONS; i++)
	{
		character_turn_order[i] = i;
	}

	// temporary array to store modified speeds used in order calculation
	int speed_array_temp[8];

	// modify each character's speed by a random amount to increase variance in character order
	for(int i = 0; i < NUM_POSITIONS; i++)
	{
		speed_array_temp[i] = grid->position[i]->job->speed + (rand() % SPEED_MODIFIER);
	}

	// sort the characters by their modified speed and add their indexes to the character_turn_order array
	for(int i = 1; i < NUM_POSITIONS; i++)
	{
		int key = speed_array_temp[i];
		int j = i - 1;

		while(j >= 0 && speed_array_temp[j] < key)
		{
			speed_array_temp[j + 1] = speed_array_temp[j];
			character_turn_order[j + 1] = character_turn_order[j];

			j--;
		}

		speed_array_temp[j + 1] = key;
		character_turn_order[j + 1] = i;
	}

	return character_turn_order;
}

// prints character turn order returned by get_character_turn_order(), returns SUCCESS on success, ERROR on error
int print_character_turn_order(grid_t* grid)
{
	if(grid == NULL)
	{
		fprintf(stderr, "error: grid is null\n");
		return ERROR;
	}

	int* character_turn_order = get_character_turn_order(grid);

	printf("Character turn order:\n");
	for(int i = 0; i < NUM_POSITIONS; i++)
	{
		printf("Character: %s, Job: %s, Speed: %i, Position: %i\n", grid->position[character_turn_order[i]]->name, grid->position[character_turn_order[i]]->job->name, grid->position[character_turn_order[i]]->job->speed, grid->position[character_turn_order[i]]->position);
	}

	free(character_turn_order);
}

// determines the winner based on the current grid, returns NO_WINNER for no winner, LEFT_TEAM for left team, RIGHT_TEAM for right team, ERROR on error
int determine_winner(grid_t* grid)
{
	if(grid == NULL)
	{
		fprintf(stderr, "error: grid is null\n");
	}

	int left_deaths = 0;
	int right_deaths = 0;

	for(int i = 0; i < NUM_POSITIONS; i++)
	{
		if(is_alive(grid->position[i]) == FALSE)
		{
			if(get_team(i) == LEFT_TEAM)
			{
				left_deaths++;
			} else
			{
				right_deaths++;
			}
		} 
	}

	if(left_deaths >= 4)
	{
		return RIGHT_TEAM;
	} else if(right_deaths >= 4)
	{
		return LEFT_TEAM;
	}

	return NO_WINNER;
}

// swaps 2 characters' positions on the grid
int swap_characters(grid_t* grid, int position0, int position1)
{
	if(grid == NULL)
	{
		fprintf(stderr, "error: grid is null\n");
		return ERROR;
	}

	if(position0 < 0 || position0 > NUM_POSITIONS - 1 || position1 < 0 || position1 > NUM_POSITIONS - 1)
	{
		fprintf(stderr, "error: position out of range\n");
	}

	// new character struct that will inherit properties from the character at position 0 and replace the character at position 1
	character_t* new_char0 = initialize_character(grid->position[position0]->name, position1, grid->position[position0]->job->name);

	// new character struct that will inherit properties from the character at position 1 and replace the character at position 0
	character_t* new_char1 = initialize_character(grid->position[position1]->name, position0, grid->position[position1]->job->name);

	// swap over old health values
	new_char0->job->health = grid->position[position0]->job->health;
	new_char1->job->health = grid->position[position1]->job->health;

	// free old characters
	free_character(grid->position[position0]);
	free_character(grid->position[position1]);

	// insert new characters in appropriate positions
	grid->position[position0] = new_char1;
	grid->position[position1] = new_char0;

	return SUCCESS;
}

// prints grid state (player name, job, health for each cell), returns SUCCESS on success, ERROR on error
int print_grid(grid_t* grid)
{
	if(grid == NULL)
	{
		fprintf(stderr, "error: grid is null\n");
		return ERROR;
	}

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

	return SUCCESS;
}

// prints info about each character in the grid, returns SUCCESS on success, ERROR on error
int print_grid_info(grid_t* grid)
{
	if(grid == NULL)
	{
		fprintf(stderr, "error: grid is null\n");
		return ERROR;
	}

	for(int i = 0; i < NUM_POSITIONS; i++)
	{
		if(grid->position[i] != NULL)
		{
			printf("-----Character Info Position %i-----\n", i);
			print_character_info(grid->position[i], i);
		}
	}
	printf("\n");

	return SUCCESS;
}

// bookkeeping function
void free_grid(grid_t* grid)
{
	if(grid == NULL)
	{
		fprintf(stderr, "error: grid is null\n");
		return;
	}

	for(int i = 0; i < NUM_POSITIONS; i++)
	{
		if(grid->position[i] != NULL)
		{
			free_character(grid->position[i]);
		}
	}

	free(grid);
}