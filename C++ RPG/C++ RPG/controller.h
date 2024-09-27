#pragma once
#include "character.h"
#include "model.h"
#include "monster.h"
#include "zombie.h"
#include "kobold.h"


namespace GameController
{
	//CREATE GAMEPLAY FIELD
	int*** CreateLevel(int _width, int _height);
	int** CreateBattleScreen();
	int** CreateBonfireScreen();

	//PLAYER MOVEMENT
	void MoveCharacter(Character* _player, int*** _level, int _input);
	int CheckTargetPosition(Character* _player, int*** _level, int _input);
	void ChangeCharacterPosition(int _input, int* _yDisplacement, int* _xDisplacement);

	// WORLD MANAGEMENT
	void OpenNewRoom();
	void ChangeCurrentRoom(int _multiplier); //either 1 for next level or -1 for previous level
	void SpawnMonsters();
	bool CheckDoorStatus();
	bool CheckRoomClear();
	void CheckEnemyInLevel();

	// BATTLE
	void CheckCollisionWithMonster();
	void MoveCursorToBattleText();
	void StartFight(Monster* _enemy);
}

