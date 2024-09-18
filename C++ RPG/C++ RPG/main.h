#pragma once
#include "character.h"
#include "gameworld.h"
#include "view.h"
#include "framerate.h"

int input;


void Start();
void Update(Character* _player, int*** _level);
void Exit();