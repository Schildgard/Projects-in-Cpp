#pragma once
#include <Windows.h>
#include <WinUser.h>

#include "character.h"
#include "gameManager.h"

#include "view.h"


void MoveCharacter(Character* _player, int*** _level, int _input);
int LookForInput();
int CheckTargetPosition(Character* _player, int*** _level, int* _yDisplacement, int* _xDisplacement, int _input);
