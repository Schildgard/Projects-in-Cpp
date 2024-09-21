#pragma once
#include <iostream>
#include <windows.h>
#include "character.h"
#include "monster.h"
#include "model.h"

#define GREEN "\033[42m ";
#define RED "\033[41m "
#define STANDARD "\033[0m ";
#define RESET "\033[0m"
#define WHITE "\033[47m ";
#define DOOR "\033[44m ";
#define MONSTER "\033[45m "
#define CLEARSCREEN std::cout << "\033[H\33[J";

namespace Visualizer
{
	void DrawLevel();
	void DrawBattleScreen(int** _battleScreenArray);
	void DrawPlayerBattleOption(int* _select);

	void WriteBattleText(std::string _text);

	void UpdateCharacterPosition(Character* _char);
	void UpdateMonsterPosition(Monster* _mon); // Difference to Update Character Position is, that Monsters do not leave their assigned Room.

	void RelocateCursorPosition(short _xOffset, short _yOffset);

	void ClearPreviousCharacterPosition(Character* _char);
	void ClearPreviousMonsterPosition(Monster* _mon); // Prototype, merge with clearCharacterPos later
};
