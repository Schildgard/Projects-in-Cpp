#pragma once
#include "view.h"
#include "player.h"
#include <vector>

static class GameManager
{
public:
	static int*** world;
	static int** battleField;
	static int** bonfireScreen;

	static bool inFight;
	static bool playerTurn;

	static bool roomCleared;


	static bool doorOpen;
	static bool door1Open;
	static bool door2Open;

	static bool roomClear;
	static bool room1Clear;
	static bool room2Clear;


	static int opponentsIndex; //IndexPosition in EnemiesInScene array
	static int levelWidth;
	static int levelHeight;
	static int roomCount;
	static int currentRoom;

	static short xOffset;
	static short yOffset;

	static Monster* opponent;
	static Character* player;

	static std::vector<Monster*> enemiesInScene;
};

