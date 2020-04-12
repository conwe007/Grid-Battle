#include "action.h"

// initializes move action, character swaps position with another character
action_t* initializeActionMove()
{
	action_t* move = (action_t*)malloc(sizeof(action_t));

	move->name = (char*)malloc(sizeof(char) * NAME_SIZE_ACTION);
	strcpy(move->name, "Move");

	move->current_position = (int*)malloc(sizeof(int) * 9);
	for(int i = 0; i < 8; i++)
	{
		move->current_position[i] = i;
	}
	move->current_position[8] = TERMINATE;

	move->target_position = NULL;

	move->move_position = (int**)malloc(sizeof(int*) * 9);
	for(int i = 0; i < 9; i++)
	{
		move->move_position[i] = (int*)malloc(sizeof(int) * 3);
		switch(i)
		{
			case 0:
				move->move_position[0][0] = 1;
				move->move_position[0][1] = 4;
				move->move_position[0][2] = TERMINATE;
				break;
			case 1:
				move->move_position[1][0] = 0;
				move->move_position[1][1] = 5;
				move->move_position[1][2] = TERMINATE;
				break;
			case 2:
				move->move_position[2][0] = 3;
				move->move_position[2][1] = 6;
				move->move_position[2][2] = TERMINATE;
				break;
			case 3:
				move->move_position[3][0] = 2;
				move->move_position[3][1] = 7;
				move->move_position[3][2] = TERMINATE;
				break;
			case 4:
				move->move_position[4][0] = 0;
				move->move_position[4][1] = 5;
				move->move_position[4][2] = TERMINATE;
				break;
			case 5:
				move->move_position[5][0] = 1;
				move->move_position[5][1] = 4;
				move->move_position[5][2] = TERMINATE;
				break;
			case 6:
				move->move_position[6][0] = 2;
				move->move_position[6][1] = 7;
				move->move_position[6][2] = TERMINATE;
				break;
			case 7:
				move->move_position[7][0] = 3;
				move->move_position[7][1] = 6;
				move->move_position[7][2] = TERMINATE;
				break;
			case 8:
				move->move_position[8][0] = TERMINATE;
				move->move_position[8][1] = TERMINATE;
				move->move_position[8][2] = TERMINATE;
				break;
			default:
				break;
		}
	}

	move->must_move = TRUE;

	move->power = 0;

	return move;
}

// initializes pass action, character passes turn
action_t* initializeActionPass()
{
	action_t* pass = (action_t*)malloc(sizeof(action_t));

	pass->name = (char*)malloc(sizeof(char) * NAME_SIZE_ACTION);
	strcpy(pass->name, "Pass");

	pass->current_position = (int*)malloc(sizeof(int) * 9);
	for(int i = 0; i < 8; i++)
	{
		pass->current_position[i] = i;
	}
	pass->current_position[8] = TERMINATE;

	pass->target_position = NULL;

	pass->move_position = NULL;

	pass->must_move = FALSE;

	pass->power = 0;

	return pass;
}

// from the front column, damages both enemy columns in the same row
action_t* initializeActionStab()
{
	action_t* stab = (action_t*)malloc(sizeof(action_t));

	stab->name = (char*)malloc(sizeof(char) * NAME_SIZE_ACTION);
	strcpy(stab->name, "Stab");

	stab->current_position = (int*)malloc(sizeof(int) * 5);
	stab->current_position[0] = 1;
	stab->current_position[1] = 2;
	stab->current_position[2] = 5;
	stab->current_position[3] = 6;
	stab->current_position[4] = TERMINATE;

	stab->target_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		stab->target_position[i] = (int*)malloc(sizeof(int) * 3);
		switch(i)
		{
			case 0:
				stab->target_position[0][0] = 2;
				stab->target_position[0][1] = 3;
				stab->target_position[0][2] = TERMINATE;
				break;
			case 1:
				stab->target_position[1][0] = 0;
				stab->target_position[1][1] = 1;
				stab->target_position[1][2] = TERMINATE;
				break;
			case 2:
				stab->target_position[2][0] = 6;
				stab->target_position[2][1] = 7;
				stab->target_position[2][2] = TERMINATE;
				break;
			case 3:
				stab->target_position[3][0] = 4;
				stab->target_position[3][1] = 5;
				stab->target_position[3][2] = TERMINATE;
				break;
			case 4:
				stab->target_position[4][0] = TERMINATE;
				stab->target_position[4][1] = TERMINATE;
				stab->target_position[4][2] = TERMINATE;
				break;
			default:
				break;
		}
	}

	stab->move_position = NULL;

	stab->must_move = FALSE;

	stab->power = 6;

	return stab;
}

//from the front column, damages both enemy rows in the front column
action_t* initializeActionSweep()
{
	action_t* sweep = (action_t*)malloc(sizeof(action_t));

	sweep->name = (char*)malloc(sizeof(char) * NAME_SIZE_ACTION);
	strcpy(sweep->name, "Sweep");

	sweep->current_position = (int*)malloc(sizeof(int) * 5);
	sweep->current_position[0] = 1;
	sweep->current_position[1] = 2;
	sweep->current_position[2] = 5;
	sweep->current_position[3] = 6;
	sweep->current_position[4] = TERMINATE;

	sweep->target_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		sweep->target_position[i] = (int*)malloc(sizeof(int) * 3);
		switch(i)
		{
			case 0:
				sweep->target_position[0][0] = 2;
				sweep->target_position[0][1] = 6;
				sweep->target_position[0][2] = TERMINATE;
				break;
			case 1:
				sweep->target_position[1][0] = 1;
				sweep->target_position[1][1] = 5;
				sweep->target_position[1][2] = TERMINATE;
				break;
			case 2:
				sweep->target_position[2][0] = 2;
				sweep->target_position[2][1] = 6;
				sweep->target_position[2][2] = TERMINATE;
				break;
			case 3:
				sweep->target_position[3][0] = 1;
				sweep->target_position[3][1] = 5;
				sweep->target_position[3][2] = TERMINATE;
				break;
			case 4:
				sweep->target_position[4][0] = TERMINATE;
				sweep->target_position[4][1] = TERMINATE;
				sweep->target_position[4][2] = TERMINATE;
				break;
			default:
				break;
		}
	}

	sweep->move_position = NULL;

	sweep->must_move = FALSE;

	sweep->power = 6;

	return sweep;
}

// from the back column, attack the enemy in the same row in front and move to the front column
action_t* initializeActionAdvance()
{
	action_t* advance = (action_t*)malloc(sizeof(action_t));

	advance->name = (char*)malloc(sizeof(char) * NAME_SIZE_ACTION);
	strcpy(advance->name, "Advance");

	advance->current_position = (int*)malloc(sizeof(int) * 5);
	advance->current_position[0] = 0;
	advance->current_position[1] = 3;
	advance->current_position[2] = 4;
	advance->current_position[3] = 7;
	advance->current_position[4] = TERMINATE;

	advance->target_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		advance->target_position[i] = (int*)malloc(sizeof(int) * 2);
		switch(i)
		{
			case 0:
				advance->target_position[0][0] = 2;
				advance->target_position[0][1] = TERMINATE;
				break;
			case 1:
				advance->target_position[1][0] = 1;
				advance->target_position[1][1] = TERMINATE;
				break;
			case 2:
				advance->target_position[2][0] = 6;
				advance->target_position[2][1] = TERMINATE;
				break;
			case 3:
				advance->target_position[3][0] = 5;
				advance->target_position[3][1] = TERMINATE;
				break;
			case 4:
				advance->target_position[4][0] = TERMINATE;
				advance->target_position[4][1] = TERMINATE;
				break;
			default:
				break;
		}
	}

	advance->move_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		advance->move_position[i] = (int*)malloc(sizeof(int) * 2);
		switch(i)
		{
			case 0:
				advance->move_position[0][0] = 1;
				advance->move_position[0][1] = TERMINATE;
				break;
			case 1:
				advance->move_position[1][0] = 2;
				advance->move_position[1][1] = TERMINATE;
				break;
			case 2:
				advance->move_position[2][0] = 5;
				advance->move_position[2][1] = TERMINATE;
				break;
			case 3:
				advance->move_position[3][0] = 6;
				advance->move_position[3][1] = TERMINATE;
				break;
			case 4:
				advance->move_position[4][0] = TERMINATE;
				advance->move_position[4][1] = TERMINATE;
				break;
			default:
				break;
		}
	}

	advance->must_move = TRUE;

	advance->power = 8;

	return advance;
}

// from the front column, attack the enemy in the same row in front and move to the back column
action_t* initializeActionRetreat()
{
	action_t* retreat = (action_t*)malloc(sizeof(action_t));

	retreat->name = (char*)malloc(sizeof(char) * NAME_SIZE_ACTION);
	strcpy(retreat->name, "Retreat");

	retreat->current_position = (int*)malloc(sizeof(int) * 5);
	retreat->current_position[0] = 1;
	retreat->current_position[1] = 2;
	retreat->current_position[2] = 5;
	retreat->current_position[3] = 6;
	retreat->current_position[4] = TERMINATE;

	retreat->target_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		retreat->target_position[i] = (int*)malloc(sizeof(int) * 2);
		switch(i)
		{
			case 0:
				retreat->target_position[0][0] = 2;
				retreat->target_position[0][1] = TERMINATE;
				break;
			case 1:
				retreat->target_position[1][0] = 1;
				retreat->target_position[1][1] = TERMINATE;
				break;
			case 2:
				retreat->target_position[2][0] = 6;
				retreat->target_position[2][1] = TERMINATE;
				break;
			case 3:
				retreat->target_position[3][0] = 5;
				retreat->target_position[3][1] = TERMINATE;
				break;
			case 4:
				retreat->target_position[4][0] = TERMINATE;
				retreat->target_position[4][1] = TERMINATE;
				break;
			default:
				break;
		}
	}

	retreat->move_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		retreat->move_position[i] = (int*)malloc(sizeof(int) * 2);
		switch(i)
		{
			case 0:
				retreat->move_position[0][0] = 0;
				retreat->move_position[0][1] = TERMINATE;
				break;
			case 1:
				retreat->move_position[1][0] = 3;
				retreat->move_position[1][1] = TERMINATE;
				break;
			case 2:
				retreat->move_position[2][0] = 4;
				retreat->move_position[2][1] = TERMINATE;
				break;
			case 3:
				retreat->move_position[3][0] = 7;
				retreat->move_position[3][1] = TERMINATE;
				break;
			case 4:
				retreat->move_position[4][0] = TERMINATE;
				retreat->move_position[4][1] = TERMINATE;
				break;
			default:
				break;
		}
	}

	retreat->must_move = TRUE;

	retreat->power = 8;

	return retreat;
}

// from the front column, heal the initiator of the action
action_t* initializeActionPray()
{
	action_t* pray = (action_t*)malloc(sizeof(action_t));

	pray->name = (char*)malloc(sizeof(char) * NAME_SIZE_ACTION);
	strcpy(pray->name, "Pray");

	pray->current_position = (int*)malloc(sizeof(int) * 5);
	pray->current_position[0] = 1;
	pray->current_position[1] = 2;
	pray->current_position[2] = 5;
	pray->current_position[3] = 6;
	pray->current_position[4] = TERMINATE;

	pray->target_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		pray->target_position[i] = (int*)malloc(sizeof(int) * 2);
		switch(i)
		{
			case 0:
				pray->target_position[0][0] = 1;
				pray->target_position[0][1] = TERMINATE;
				break;
			case 1:
				pray->target_position[1][0] = 2;
				pray->target_position[1][1] = TERMINATE;
				break;
			case 2:
				pray->target_position[2][0] = 5;
				pray->target_position[2][1] = TERMINATE;
				break;
			case 3:
				pray->target_position[3][0] = 6;
				pray->target_position[3][1] = TERMINATE;
				break;
			case 4:
				pray->target_position[4][0] = TERMINATE;
				pray->target_position[4][1] = TERMINATE;
				break;
			default:
				break;
		}
	}

	pray->move_position = NULL;

	pray->must_move = FALSE;

	pray->power = -7;

	return pray;
}

// from the back column, damage the two enemies in the back column
action_t* initializeActionCondemn()
{
	action_t* condemn = (action_t*)malloc(sizeof(action_t));

	condemn->name = (char*)malloc(sizeof(char) * NAME_SIZE_ACTION);
	strcpy(condemn->name, "Condemn");

	condemn->current_position = (int*)malloc(sizeof(int) * 5);
	condemn->current_position[0] = 0;
	condemn->current_position[1] = 3;
	condemn->current_position[2] = 4;
	condemn->current_position[3] = 7;
	condemn->current_position[4] = TERMINATE;

	condemn->target_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		condemn->target_position[i] = (int*)malloc(sizeof(int) * 3);
		switch(i)
		{
			case 0:
				condemn->target_position[0][0] = 3;
				condemn->target_position[0][1] = 7;
				condemn->target_position[0][2] = TERMINATE;
				break;
			case 1:
				condemn->target_position[1][0] = 0;
				condemn->target_position[1][1] = 4;
				condemn->target_position[1][2] = TERMINATE;
				break;
			case 2:
				condemn->target_position[2][0] = 3;
				condemn->target_position[2][1] = 7;
				condemn->target_position[2][2] = TERMINATE;
				break;
			case 3:
				condemn->target_position[3][0] = 0;
				condemn->target_position[3][1] = 4;
				condemn->target_position[3][2] = TERMINATE;
				break;
			case 4:
				condemn->target_position[4][0] = TERMINATE;
				condemn->target_position[4][1] = TERMINATE;
				condemn->target_position[4][2] = TERMINATE;
				break;
			default:
				break;
		}
	}

	condemn->move_position = NULL;

	condemn->must_move = FALSE;

	condemn->power = 5;

	return condemn;
}

// from the front column, damage the enemy in the front column and opposite row
action_t* initializeActionSmite()
{
	action_t* smite = (action_t*)malloc(sizeof(action_t));

	smite->name = (char*)malloc(sizeof(char) * NAME_SIZE_ACTION);
	strcpy(smite->name, "Smite");

	smite->current_position = (int*)malloc(sizeof(int) * 5);
	smite->current_position[0] = 1;
	smite->current_position[1] = 2;
	smite->current_position[2] = 5;
	smite->current_position[3] = 6;
	smite->current_position[4] = TERMINATE;

	smite->target_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		smite->target_position[i] = (int*)malloc(sizeof(int) * 2);
		switch(i)
		{
			case 0:
				smite->target_position[0][0] = 6;
				smite->target_position[0][1] = TERMINATE;
				break;
			case 1:
				smite->target_position[1][0] = 5;
				smite->target_position[1][1] = TERMINATE;
				break;
			case 2:
				smite->target_position[2][0] = 2;
				smite->target_position[2][1] = TERMINATE;
				break;
			case 3:
				smite->target_position[3][0] = 1;
				smite->target_position[3][1] = TERMINATE;
				break;
			case 4:
				smite->target_position[4][0] = TERMINATE;
				smite->target_position[4][1] = TERMINATE;
				break;
			default:
				break;
		}
	}

	smite->move_position = NULL;

	smite->must_move = FALSE;

	smite->power = 8;

	return smite;
}

// from the back column, heal the two allies in the front column
action_t* initializeActionBless()
{
	action_t* bless = (action_t*)malloc(sizeof(action_t));

	bless->name = (char*)malloc(sizeof(char) * NAME_SIZE_ACTION);
	strcpy(bless->name, "Bless");

	bless->current_position = (int*)malloc(sizeof(int) * 5);
	bless->current_position[0] = 0;
	bless->current_position[1] = 3;
	bless->current_position[2] = 4;
	bless->current_position[3] = 7;
	bless->current_position[4] = TERMINATE;

	bless->target_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		bless->target_position[i] = (int*)malloc(sizeof(int) * 3);
		switch(i)
		{
			case 0:
				bless->target_position[0][0] = 1;
				bless->target_position[0][1] = 5;
				bless->target_position[0][2] = TERMINATE;
				break;
			case 1:
				bless->target_position[1][0] = 2;
				bless->target_position[1][1] = 6;
				bless->target_position[1][2] = TERMINATE;
				break;
			case 2:
				bless->target_position[2][0] = 1;
				bless->target_position[2][1] = 5;
				bless->target_position[2][2] = TERMINATE;
				break;
			case 3:
				bless->target_position[3][0] = 2;
				bless->target_position[3][1] = 6;
				bless->target_position[3][2] = TERMINATE;
				break;
			case 4:
				bless->target_position[4][0] = TERMINATE;
				bless->target_position[4][1] = TERMINATE;
				bless->target_position[4][2] = TERMINATE;
				break;
			default:
				break;
		}
	}

	bless->move_position = NULL;

	bless->must_move = FALSE;

	bless->power = -4;

	return bless;
}

// from the front column, damage the enemy in the back column and opposite row
action_t* initializeActionMock()
{
	action_t* mock = (action_t*)malloc(sizeof(action_t));

	mock->name = (char*)malloc(sizeof(char) * NAME_SIZE_ACTION);
	strcpy(mock->name, "Mock");

	mock->current_position = (int*)malloc(sizeof(int) * 5);
	mock->current_position[0] = 1;
	mock->current_position[1] = 2;
	mock->current_position[2] = 5;
	mock->current_position[3] = 6;
	mock->current_position[4] = TERMINATE;

	mock->target_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		mock->target_position[i] = (int*)malloc(sizeof(int) * 2);
		switch(i)
		{
			case 0:
				mock->target_position[0][0] = 7;
				mock->target_position[0][1] = TERMINATE;
				break;
			case 1:
				mock->target_position[1][0] = 4;
				mock->target_position[1][1] = TERMINATE;
				break;
			case 2:
				mock->target_position[2][0] = 3;
				mock->target_position[2][1] = TERMINATE;
				break;
			case 3:
				mock->target_position[3][0] = 0;
				mock->target_position[3][1] = TERMINATE;
				break;
			case 4:
				mock->target_position[4][0] = TERMINATE;
				mock->target_position[4][1] = TERMINATE;
				break;
			default:
				break;
		}
	}

	mock->move_position = NULL;

	mock->must_move = FALSE;

	mock->power = 7;

	return mock;
}

// from the back column, damage the enemy in the back column and the enemy in the front column and opposite row, swap with ally in the front column and opposite row
action_t* initializeActionFoolery()
{
	action_t* foolery = (action_t*)malloc(sizeof(action_t));

	foolery->name = (char*)malloc(sizeof(char) * NAME_SIZE_ACTION);
	strcpy(foolery->name, "Foolery");

	foolery->current_position = (int*)malloc(sizeof(int) * 5);
	foolery->current_position[0] = 0;
	foolery->current_position[1] = 3;
	foolery->current_position[2] = 4;
	foolery->current_position[3] = 7;
	foolery->current_position[4] = TERMINATE;

	foolery->target_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		foolery->target_position[i] = (int*)malloc(sizeof(int) * 2);
		switch(i)
		{
			case 0:
				foolery->target_position[0][0] = 3;
				foolery->target_position[0][1] = 6;
				foolery->target_position[0][2] = TERMINATE;
				break;
			case 1:
				foolery->target_position[1][0] = 0;
				foolery->target_position[1][1] = 5;
				foolery->target_position[1][2] = TERMINATE;
				break;
			case 2:
				foolery->target_position[2][0] = 2;
				foolery->target_position[2][1] = 7;
				foolery->target_position[2][2] = TERMINATE;
				break;
			case 3:
				foolery->target_position[3][0] = 1;
				foolery->target_position[3][1] = 4;
				foolery->target_position[3][2] = TERMINATE;
				break;
			case 4:
				foolery->target_position[4][0] = TERMINATE;
				foolery->target_position[4][1] = TERMINATE;
				foolery->target_position[4][2] = TERMINATE;
				break;
			default:
				break;
		}
	}

	foolery->move_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		foolery->move_position[i] = (int*)malloc(sizeof(int) * 2);
		switch(i)
		{
			case 0:
				foolery->move_position[0][0] = 5;
				foolery->move_position[0][1] = TERMINATE;
				break;
			case 1:
				foolery->move_position[1][0] = 6;
				foolery->move_position[1][1] = TERMINATE;
				break;
			case 2:
				foolery->move_position[2][0] = 1;
				foolery->move_position[2][1] = TERMINATE;
				break;
			case 3:
				foolery->move_position[3][0] = 2;
				foolery->move_position[3][1] = TERMINATE;
				break;
			case 4:
				foolery->move_position[4][0] = TERMINATE;
				foolery->move_position[4][1] = TERMINATE;
				break;
			default:
				break;
		}
	}

	foolery->must_move = TRUE;

	foolery->power = 4;

	return foolery;
}

// from the front column, damage the enemy in the front column and the same row, and move to the opposite row
action_t* initializeActionSomersault()
{
	action_t* somersault = (action_t*)malloc(sizeof(action_t));

	somersault->name = (char*)malloc(sizeof(char) * NAME_SIZE_ACTION);
	strcpy(somersault->name, "Somersault");

	somersault->current_position = (int*)malloc(sizeof(int) * 5);
	somersault->current_position[0] = 1;
	somersault->current_position[1] = 2;
	somersault->current_position[2] = 5;
	somersault->current_position[3] = 6;
	somersault->current_position[4] = TERMINATE;

	somersault->target_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		somersault->target_position[i] = (int*)malloc(sizeof(int) * 2);
		switch(i)
		{
			case 0:
				somersault->target_position[0][0] = 2;
				somersault->target_position[0][1] = TERMINATE;
				break;
			case 1:
				somersault->target_position[1][0] = 1;
				somersault->target_position[1][1] = TERMINATE;
				break;
			case 2:
				somersault->target_position[2][0] = 6;
				somersault->target_position[2][1] = TERMINATE;
				break;
			case 3:
				somersault->target_position[3][0] = 5;
				somersault->target_position[3][1] = TERMINATE;
				break;
			case 4:
				somersault->target_position[4][0] = TERMINATE;
				somersault->target_position[4][1] = TERMINATE;
				break;
			default:
				break;
		}
	}

	somersault->move_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		somersault->move_position[i] = (int*)malloc(sizeof(int) * 2);
		switch(i)
		{
			case 0:
				somersault->move_position[0][0] = 5;
				somersault->move_position[0][1] = TERMINATE;
				break;
			case 1:
				somersault->move_position[1][0] = 6;
				somersault->move_position[1][1] = TERMINATE;
				break;
			case 2:
				somersault->move_position[2][0] = 1;
				somersault->move_position[2][1] = TERMINATE;
				break;
			case 3:
				somersault->move_position[3][0] = 2;
				somersault->move_position[3][1] = TERMINATE;
				break;
			case 4:
				somersault->move_position[4][0] = TERMINATE;
				somersault->move_position[4][1] = TERMINATE;
				break;
			default:
				break;
		}
	}

	somersault->must_move = TRUE;

	somersault->power = 6;

	return somersault;
}

// from the front column, heal the ally in the back column, the ally in the opposite row, and the enemy in the front column, swap with ally in the back column
action_t* initializeActionPuppetshow()
{
	action_t* puppetshow = (action_t*)malloc(sizeof(action_t));

	puppetshow->name = (char*)malloc(sizeof(char) * NAME_SIZE_ACTION);
	strcpy(puppetshow->name, "Puppetshow");

	puppetshow->current_position = (int*)malloc(sizeof(int) * 5);
	puppetshow->current_position[0] = 1;
	puppetshow->current_position[1] = 2;
	puppetshow->current_position[2] = 5;
	puppetshow->current_position[3] = 6;
	puppetshow->current_position[4] = TERMINATE;

	puppetshow->target_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		puppetshow->target_position[i] = (int*)malloc(sizeof(int) * 2);
		switch(i)
		{
			case 0:
				puppetshow->target_position[0][0] = 0;
				puppetshow->target_position[0][1] = 2;
				puppetshow->target_position[0][2] = 5;
				puppetshow->target_position[0][3] = TERMINATE;
				break;
			case 1:
				puppetshow->target_position[1][0] = 1;
				puppetshow->target_position[1][1] = 3;
				puppetshow->target_position[1][2] = 6;
				puppetshow->target_position[1][3] = TERMINATE;
				break;
			case 2:
				puppetshow->target_position[2][0] = 1;
				puppetshow->target_position[2][1] = 4;
				puppetshow->target_position[2][2] = 6;
				puppetshow->target_position[2][3] = TERMINATE;
				break;
			case 3:
				puppetshow->target_position[3][0] = 2;
				puppetshow->target_position[3][1] = 5;
				puppetshow->target_position[3][2] = 7;
				puppetshow->target_position[3][3] = TERMINATE;
				break;
			case 4:
				puppetshow->target_position[4][0] = TERMINATE;
				puppetshow->target_position[4][1] = TERMINATE;
				puppetshow->target_position[4][2] = TERMINATE;
				puppetshow->target_position[4][3] = TERMINATE;
				break;
			default:
				break;
		}
	}

	puppetshow->move_position = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i < 5; i++)
	{
		puppetshow->move_position[i] = (int*)malloc(sizeof(int) * 2);
		switch(i)
		{
			case 0:
				puppetshow->move_position[0][0] = 0;
				puppetshow->move_position[0][1] = TERMINATE;
				break;
			case 1:
				puppetshow->move_position[1][0] = 3;
				puppetshow->move_position[1][1] = TERMINATE;
				break;
			case 2:
				puppetshow->move_position[2][0] = 4;
				puppetshow->move_position[2][1] = TERMINATE;
				break;
			case 3:
				puppetshow->move_position[3][0] = 7;
				puppetshow->move_position[3][1] = TERMINATE;
				break;
			case 4:
				puppetshow->move_position[4][0] = TERMINATE;
				puppetshow->move_position[4][1] = TERMINATE;
				break;
			default:
				break;
		}
	}

	puppetshow->must_move = TRUE;

	puppetshow->power = -8;

	return puppetshow;
}

// performs the specified action, returns result struct on success, NULL on failure
result_t* calculateActionResult(action_t* action, double skill, int current_position, int move_position)
{
	// exit if current position is not valid
	if(currentPositionIsValid(action, current_position) == 0)
	{
		fprintf(stderr, "error: current position '%i' is not valid\n", current_position);
		return NULL;
	}

	// exit if move position is not valid
	if(movePositionIsValid(action, current_position, move_position) == 0)
	{
		fprintf(stderr, "error: move position '%i' is not valid\n", move_position);
		return NULL;
	}

	int index = currentPositionIndex(action, current_position);
	result_t* result = initializeResult();

	// loop through each target position defined for the current position, apply power to result power grid
	if(action->target_position != NULL)
	{
		int i = 0;
		while(action->target_position[index][i] != TERMINATE)
		{
			// roll against skill stat to determine if action power is applied
			if(actionSuccess(skill))
			{
				result->power_grid[action->target_position[index][i]] = action->power;
			}
			
			i++;
		}
	}

	// if applicable, indicate two cells to switch (current position and move position)
	if(move_position != NO_MOVE)
	{
		result->move_cells[0] = current_position;
		result->move_cells[1] = move_position;
	}

	return result;
}

// helper function, returns current position action index (different from current position) for specified action, INVALID if position is invalid
int currentPositionIndex(action_t* action, int current_position)
{
	if(action == NULL)
	{
		return INVALID;
	}

	int i = 0;
	while(action->current_position[i] != TERMINATE)
	{
		if(action->current_position[i] == current_position)
		{
			return i;
		}

		i++;
	}

	return INVALID;
}

// helper function, returns TRUE if current position is valid for specified action, FALSE otherwise
int currentPositionIsValid(action_t* action, int current_position)
{
	if(currentPositionIndex(action, current_position) == INVALID)
	{
		return FALSE;
	}

	return TRUE;
}

// helper function, returns TRUE if move position is valid for current position and specified action, FALSE otherwise
int movePositionIsValid(action_t* action, int current_position, int move_position)
{
	// exit SUCCESS if action does not support move and move position is NO_MOVE, FAILURE if move position is not NO_MOVE
	if(action->move_position == NULL && move_position == NO_MOVE && action->must_move == FALSE)
	{
		return TRUE;
	} else if((action->move_position == NULL || action->must_move == FALSE) && move_position != NO_MOVE)
	{
		return FALSE;
	} else if(action->must_move == TRUE && move_position == NO_MOVE)
	{
		return FALSE;
	}

	int index = currentPositionIndex(action, current_position);

	// loop until a valid matching move position from current position is found
	int i = 0;
	while(action->move_position[index][i] != TERMINATE)
	{
		if(action->move_position[index][i] == move_position)
		{
			return TRUE;
		}

		i++;
	}

	return FALSE;
}

// determines whether action will be a success based on character skill, returns SUCCESS on success, FAILURE on failure, ERROR on error
int actionSuccess(double skill)
{
	if(skill < 0 || skill > 10)
	{
		fprintf(stderr, "error: incorrect skill '%f'\n", skill);
		return ERROR;
	}

	// skill 0: 70% ---> skill 10: 100%
	if(((double)rand() / (double)RAND_MAX) < (0.7 + skill * 0.03))
	{
		return SUCCESS;
	}
	
	return FAILURE;
}

// determines whether a character will evade an action based on evasion, returns SUCCESS on success, FAILURE on failure, ERROR on error
int evadeSuccess(double evasion)
{
	if(evasion < 0 || evasion > 10)
	{
		fprintf(stderr, "error: incorrect evasion '%f'\n", evasion);
		return ERROR;
	}

	// evasion 0: 0% ---> evasion 10: 30%
	if(((double)rand() / (double)RAND_MAX) < (evasion * 0.03))
	{
		return SUCCESS;
	}
	
	return FAILURE;
}

// returns an array of target positions an action will affect based on the initiator's position
int* getTargetPositions(action_t* action, int current_position)
{
	// maximum size needed is 8 target positions plus terminating -1
	int* target_position_array = (int*)malloc(sizeof(int) * (NUM_TARGET_POSITIONS + 1));
	int current_position_index_temp = currentPositionIndex(action, current_position);
	int index = 0;

	// return empty array if the action does not have target position(s)
	if(action->target_position == NULL)
	{
		target_position_array[index] = TERMINATE;
		return target_position_array;
	}

	// if action is not valid at the current position, return empty array
	if(current_position_index_temp == INVALID)
	{
		target_position_array[index] = TERMINATE;
		return target_position_array;
	}

	// loop through target positions for the action at the current position and add them to target_positon_array
	while(action->target_position[current_position_index_temp][index] != TERMINATE)
	{
		target_position_array[index] = action->target_position[current_position_index_temp][index];
		index++;
	}

	target_position_array[index] = TERMINATE;

	return target_position_array;
}

// prints the array of target positions returned by get_target_positions(), returns SUCCESS on success, ERROR on error
int printTargetPositions(action_t* action, int current_position)
{
	if(action == NULL)
	{
		fprintf(stderr, "error: action is null\n");
		return ERROR;
	}

	int* target_position_array = getTargetPositions(action, current_position);
	int index = 0;

	printf("Target positions for action '%s' at position '%i': ", action->name, current_position);
	while(target_position_array[index] != TERMINATE)
	{
		printf("%i ", target_position_array[index]);
		index++;
	}
	printf("\n");

	free(target_position_array);

	return SUCCESS;
}

// returns an array of move positions valid to an action based on the initiator's position
int* getMovePositions(action_t* action, int current_position)
{
	// maximum size needed is 2 move positions plus terminating -1
	int* move_position_array = (int*)malloc(sizeof(int) * (NUM_MOVE_CELLS + 1));
	int current_position_index_temp = currentPositionIndex(action, current_position);
	int index = 0;

	// return empty array if the action does not have move position(s)
	if(action->move_position == NULL)
	{
		move_position_array[index] = TERMINATE;
		return move_position_array;
	}

	// if action is not valid at the current position, return empty array
	if(current_position_index_temp == INVALID)
	{
		move_position_array[index] = TERMINATE;
		return move_position_array;
	}

	// loop through move positions for the action at the current position and add them to move_positon_array
	while(action->move_position[current_position_index_temp][index] != TERMINATE)
	{
		move_position_array[index] = action->move_position[current_position_index_temp][index];
		index++;
	}

	move_position_array[index] = TERMINATE;

	return move_position_array;
}

// prints the array of move positions returned by get_move_positions(), returns SUCCESS on success, ERROR on error
int printMovePositions(action_t* action, int current_position)
{
	if(action == NULL)
	{
		fprintf(stderr, "error: action is null\n");
		return ERROR;
	}

	int* move_position_array = getMovePositions(action, current_position);
	int index = 0;

	printf("Move positions for action '%s' at position '%i': ", action->name, current_position);
	while(move_position_array[index] != TERMINATE)
	{
		printf("%i ", move_position_array[index]);
		index++;
	}
	printf("\n");

	free(move_position_array);

	return SUCCESS;
}

// returns TRUE if action index is valid, FALSE otherwise
int actionIndexIsValid(int action_index)
{
	if(action_index < 0 || action_index > (NUM_ACTIONS - 1))
	{
		return FALSE;
	}

	return TRUE;
}

// prints info about action, returns SUCCESS on success, ERROR on error
int printActionInfo(action_t* action, int action_index, int current_position)
{
	if(action == NULL)
	{
		fprintf(stderr, "error: action is null\n");
		return ERROR;
	}

	printf("\t%s%i: %s\n", STRING_ACTION, action_index, action->name);
	printf("\t\t");
	printTargetPositions(action, current_position);
	printf("\t\t");
	printMovePositions(action, current_position);

	return SUCCESS;
}

// initializes a result struct containing the result of any action
result_t* initializeResult()
{
	result_t* result = (result_t*)malloc(sizeof(result_t));

	// initially, no power applied to any cell
	for(int position = 0; position < NUM_POSITIONS; position++)
	{
		result->power_grid[position] = 0;
	}

	// initially, all movement pairs set to NO_MOVE
	for(int cell = 0; cell < NUM_MOVE_CELLS; cell++)
	{
		result->move_cells[cell] = NO_MOVE;
	}

	return result;
}

// debugging function, returns SUCCESS on success, ERROR on error
int printResult(result_t* result)
{
	if(result == NULL)
	{
		fprintf(stderr, "error: null result\n");
		return ERROR;
	}

	printf("-----Result-----\n");
	printf("Power Grid:\n");
	printf("%i %i %i %i\n", result->power_grid[0], result->power_grid[1], result->power_grid[2], result->power_grid[3]);
	printf("%i %i %i %i\n", result->power_grid[4], result->power_grid[5], result->power_grid[6], result->power_grid[7]);
	printf("Move Pair:\n");
	printf("%i <-> %i\n", result->move_cells[0], result->move_cells[1]);

	return SUCCESS;
}

// bookkeeping function
void freeAction(action_t* action)
{
	if(action == NULL)
	{
		fprintf(stderr, "error: action is null\n");
		return;
	}

	int i;

	free(action->name);

	free(action->current_position);

	i = 0;
	if(action->target_position != NULL)
	{
		while(action->target_position[i][0] != TERMINATE)
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
		while(action->move_position[i][0] != TERMINATE)
		{
			free(action->move_position[i]);
			i++;
		}

		free(action->move_position[i]);
		free(action->move_position);
	}

	free(action);
}

// bookkeeping function
void freeResult(result_t* result)
{
	free(result);
}
