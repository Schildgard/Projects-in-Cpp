#include "gameManager.h"

int*** GameManager::world = 0;

int GameManager::levelWidth = 30;
int GameManager::levelHeight = 20;
int GameManager::currentRoom = 0;
int GameManager::roomCount = 1;

short GameManager::xOffset = 0;
short GameManager::yOffset = 0;

void GameManager::ChangeCurrentRoom(int _multiplier)
{
	//either 1 for next level or -1 for previous level
	GameManager::currentRoom += _multiplier;

	switch (currentRoom)
	{
	case 0:
		GameManager::xOffset = 0;
		GameManager::yOffset = 0;
		break;
	case 1:
		GameManager::xOffset = GameManager::levelWidth;
		GameManager::yOffset = 0;
		break;
	case 2:
		GameManager::yOffset = GameManager::levelHeight;
		break;
	}
	DrawLevel(GameManager::world);
}
