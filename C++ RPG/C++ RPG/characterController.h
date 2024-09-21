#pragma once
#include <Windows.h>
#include <WinUser.h>

#include "character.h"
#include "model.h"

#include "view.h"
#include <conio.h> //necessary for getch function to get arrow key input not async

namespace CharacterController
{
	int LookForInput();

	void LookForInputNotAsync(int* _select);

}
