#include "action.h"

// initializes move action, character swaps position with another character
action_t* initialize_action_move()
{
	action_t* move = (action_t*)malloc(sizeof(action_t));

	move->name = (char*)malloc(sizeof(char) * NAME_SIZE_ACTION);
	strcpy(move->name, "Move");

	move->valid_position = (int*)malloc(sizeof(int) * 9);
	for(int i = 0; i < 8; i++)
	{
		move->valid_position[i] = i;
	}
	move->valid_position[8] = -1;

	move->target_position = NULL;

	move->move_position = (int**)malloc(sizeof(int*) * 9);
	for(int i = 0; i < 9; i++)
	{
		move->move_position[i] = (int*)malloc(sizeof(int) * 2);
		switch(i)
		{
			case 0:
				move->move_position[0][0] = 1;
				move->move_position[0][1] = 4;
				break;
			case 1:
				move->move_position[1][0] = 0;
				move->move_position[1][1] = 5;
				break;
			case 2:
				move->move_position[2][0] = 3;
				move->move_position[2][1] = 6;
				break;
			case 3:
				move->move_position[3][0] = 2;
				move->move_position[3][1] = 7;
				break;
			case 4:
				move->move_position[4][0] = 0;
				move->move_position[4][1] = 5;
				break;
			case 5:
				move->move_position[5][0] = 1;
				move->move_position[5][1] = 4;
				break;
			case 6:
				move->move_position[6][0] = 2;
				move->move_position[6][1] = 7;
				break;
			case 7:
				move->move_position[7][0] = 3;
				move->move_position[7][1] = 6;
				break;
			case 8:
				move->move_position[8][0] = -1;
				move->move_position[8][1] = -1;
				break;
			default:
				break;
		}
	}

	move->power = 0.0;

	return move;
}

// initializes pass action, character passes turn
action_t* initialize_action_pass()
{
	action_t* pass = (action_t*)malloc(sizeof(action_t));

	pass->name = (char*)malloc(sizeof(char) * NAME_SIZE_ACTION);
	strcpy(pass->name, "Pass");

	pass->valid_position = (int*)malloc(sizeof(int) * 9);
	for(int i = 0; i < 8; i++)
	{
		pass->valid_position[i] = i;
	}
	pass->valid_position[8] = -1;

	pass->target_position = NULL;

	pass->move_position = NULL;

	pass->power = 0.0;

	return pass;
}

// from the front column, damages both enemy columns in the same row
action_t* initialize_action_stab()
{
	action_t* stab = (action_t*)malloc(sizeof(action_t));

	stab->name = (char*)malloc(sizeof(char) * NAME_SIZE_ACTION);
	strcpy(stab->name, "Stab");

	stab->valid_position = (int*)malloc(sizeof(int) * 5);
	stab->valid_position[0] = 1;
	stab->valid_position[1] = 2;
	stab->valid_position[2] = 5;
	stab->valid_position[3] = 6;
	stab->valid_position[4] = -1;

	stab->target_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		stab->target_position[i] = (int*)malloc(sizeof(int) * 2);
		switch(i)
		{
			case 0:
				stab->target_position[0][0] = 2;
				stab->target_position[0][1] = 3;
				break;
			case 1:
				stab->target_position[1][0] = 0;
				stab->target_position[1][1] = 1;
				break;
			case 2:
				stab->target_position[2][0] = 6;
				stab->target_position[2][1] = 7;
				break;
			case 3:
				stab->target_position[3][0] = 4;
				stab->target_position[3][1] = 5;
				break;
			case 4:
				stab->target_position[4][0] = -1;
				stab->target_position[4][1] = -1;
				break;
			default:
				break;
		}
	}

	stab->move_position = NULL;

	stab->power = 6.0;

	return stab;
}

//
action_t* initialize_action_hook()
{

}

//
action_t* initialize_action_advance()
{

}

//
action_t* initialize_action_retreat()
{

}

// bookkeeping function
void free_action(action_t* action)
{
	int i;

	free(action->name);

	free(action->valid_position);

	i = 0;
	if(action->target_position != NULL)
	{
		while(action->target_position[i][0] != -1)
		{
			free(action->target_position[i]);
			i++;
		}
		free(action->target_position[i]);
		free(action->target_position);
	}

	i = 0;
	if(action->move_position != NULL)
	{
		while(action->move_position[i][0] != -1)
		{
			free(action->move_position[i]);
			i++;
		}
		free(action->move_position[i]);
		free(action->move_position);
	}

	free(action);
}

// returns integer positions relative to the character
int get_position_same_FR(int position)
{
	return (position < 4) ? 0 : 4;
}

int get_position_opposite_FR(int position)
{
	return (position < 4) ? 4 : 0;
}

int get_position_same_FF(int position)
{
	return (position < 4) ? 1 : 5;
}

int get_position_opposite_FF(int position)
{
	return (position < 4) ? 5 : 1;
}

int get_position_same_EF(int position)
{
	return (position < 4) ? 2 : 6;
}

int get_position_opposite_EF(int position)
{
	return (position < 4) ? 6 : 2;
}

int get_position_same_ER(int position)
{
	return (position < 4) ? 3 : 7;
}

int get_position_opposite_ER(int position)
{
	return (position < 4) ? 7 : 3;
}
// end get_position functions