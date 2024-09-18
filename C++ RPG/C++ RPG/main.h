#pragma once
#include "character.h"
#include "controller.h"
#include "view.h"
#include "framerate.h"
#include "zombie.h"

int input;


void Start();
void Update(Character* _player, int*** _level);
void Exit();