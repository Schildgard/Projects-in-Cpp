#pragma once
#include <iostream>
#include <windows.h>
#include "character.h"



int*** CreateLevel(int _width, int _height, Character* _player);
void DrawLevel(int*** _level);
void DrawCharacter(Character* _char);
void ClearPreviousCharacterPosition(Character* _char);
void RelocateCursorPosition(short _xOffset, short _yOffset);
