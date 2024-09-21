#pragma once
#include "character.h"
#include "model.h"
#include "monster.h"
#include "zombie.h"


namespace GameController
{
	int*** CreateLevel(int _width, int _height);
	int** CreateBattleScreen();

	void MoveCharacter(Character* _player, int*** _level, int _input);
	int CheckTargetPosition(Character* _player, int*** _level, int* _yDisplacement, int* _xDisplacement, int _input);

	void ChangeCurrentRoom(int _multiplier); //either 1 for next level or -1 for previous level
	void OpenNewRoom();

	void SpawnMonsters();

	void CheckCollisionWithMonster();

	void MoveCursorToBattleText();

	void StartFight(Monster* _enemy);
}

