#pragma once
#include "gameworld.h"

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

	static void ChangeCurrentRoom(int _multiplier); //either 1 for next level or -1 for previous level
};

