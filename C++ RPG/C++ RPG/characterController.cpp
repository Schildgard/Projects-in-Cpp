#include "characterController.h"

int CharacterController::LookForInput()
{
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
};