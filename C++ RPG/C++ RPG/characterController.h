#pragma once
#include <Windows.h>
#include "character.h"
#include "gameManager.h"
#include <WinUser.h>
#include "gameworld.h"



void MoveCharacter(Character* _player, int*** _level);

int CheckTargetPosition(Character* _player, int*** _level, int* _yDisplacement, int* _xDisplacement);
