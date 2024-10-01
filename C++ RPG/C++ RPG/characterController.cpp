#include "characterController.h"

int CharacterController::LookForInput()
{
	//THIS IS USED WHILE MOVING THROUGH THE GAME
	if (GetAsyncKeyState(VK_UP))
	{
		return 1;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		return -1;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		return -2;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		return 2;
	}

	return 0;
}
void CharacterController::LookForInputNotAsync(int* _select) // TODO: CHANGE NAMING OF THAT FUNCTION
{
	//THIS IS ONLY USED TO CHOOSE PLAYER ACTIONS WHILE COMBAT OR AT BONFIRE
	int input = _getch();

	if (input == 224)
	{
		input = _getch();
		if (input == 72) // UP
		{
			*_select = 1;
		}
		else if (input == 80) //DOWN
		{
			*_select = 2;
		}
		else if (input == 75) // LEFT
		{
			*_select = 3;
		}
		else if (input == 77) // RIGHT
		{
			*_select = 4;
		}
	}
	else if (input == 13)
	{
		GameManager::playerTurn = false;
		*_select = 13;
	}
}
