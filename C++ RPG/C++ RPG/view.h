#pragma once
#include <iostream>
#include <windows.h>
#include "character.h"
#include "gameManager.h"

#define GREEN "\033[42m ";
#define RED "\033[41m ";
#define STANDARD "\033[0m ";
#define DOOR "\033[44m ";

namespace Visualizer
{
	void DrawLevel();

	void UpdateCharacterPosition(Character* _char);
	void RelocateCursorPosition(short _xOffset, short _yOffset);

	void ClearPreviousCharacterPosition(Character* _char);
};
