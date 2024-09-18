#pragma once
#include "character.h"
#include "gameManager.h"

namespace GameController
{
int*** CreateLevel(int _width, int _height, Character* _player);

void MoveCharacter(Character* _player, int*** _level, int _input);
int CheckTargetPosition(Character* _player, int*** _level, int* _yDisplacement, int* _xDisplacement, int _input);
}

