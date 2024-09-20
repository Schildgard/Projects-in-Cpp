#pragma once
#include "view.h"
#include "player.h"
#include <vector>

static class GameManager
{
public:
	static int*** world;
	static int** battleField;

	static int levelWidth;
	static int levelHeight;
	static int roomCount;
	static int currentRoom;


	static short xOffset;
	static short yOffset;

	static Character* player;

	//static Monster* activeEnemies;

	static std::vector<Monster*> enemiesInScene;

};

