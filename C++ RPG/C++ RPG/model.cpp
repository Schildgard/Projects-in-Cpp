#include "model.h"

int*** GameManager::world = 0;

int GameManager::levelWidth = 30;
int GameManager::levelHeight = 20;
int GameManager::currentRoom = 0;
int GameManager::roomCount = 1;

short GameManager::xOffset = 0;
short GameManager::yOffset = 0;

Character* GameManager::player = nullptr;

Monster* GameManager::activeEnemies = nullptr;
