#include "characterController.h"

int CharacterController::LookForInput()
{
	//THIS IS USED WHILE MOVING THROUGH THE GAME
	if (GetAsyncKeyState(VK_UP))
	{
		return 1;
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		return -1;
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		return -2;
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		return 2;
	}

	return 0;
}
void CharacterController::LookForInputNotAsync(int* _select)
{
	//THIS IS ONLY USED TO CHOOSE PLAYER ACTIONS WHILE COMBAT
	int input = _getch();

	if (input == 224)
	{
		input = _getch();
		if (input == 72)
		{
			*_select = 1;
		}
		else if (input == 80)
		{
			*_select = 2;
		}
	}
	else if (input == 13)
	{
		GameManager::playerTurn = false;
	}
}
