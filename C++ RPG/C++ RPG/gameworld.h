#pragma once
#include <iostream>
#include <windows.h>
#include "character.h"

int*** CreateLevel(int _width, int _height, Character* _player);

void DrawLevel(int*** _level, int _width,int _height, int _roomCount);

void RelocateCursorPosition(int _xOffset, int _yOffset);
