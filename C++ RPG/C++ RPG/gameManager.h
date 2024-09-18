#pragma once
#include "view.h"
#include "player.h"

static class GameManager
{
public:
	static int*** world;

	static int levelWidth;
	static int levelHeight;
	static int roomCount;
	static int currentRoom;


	static short xOffset;
	static short yOffset;

	static Character* player;

	static void ChangeCurrentRoom(int _multiplier); //either 1 for next level or -1 for previous level
};

