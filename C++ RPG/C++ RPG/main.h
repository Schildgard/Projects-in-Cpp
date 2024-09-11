#pragma once
#include "character.h"
#include "gameworld.h"

int input;


void Start();
void Update(Character* _player, int** _level, int _width, int _height);
void Exit();