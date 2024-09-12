#pragma once
#include "character.h"
#include "gameManager.h"

void MoveCharacter(Character* _player, int*** _level, int _input);

int CheckTargetPosition(Character* _player, int*** _level, int _input, int* _yDisplacement, int* _xDisplacement);
