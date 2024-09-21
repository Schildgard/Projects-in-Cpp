#include "model.h"

int*** GameManager::world = 0;
int** GameManager::battleField = 0;

bool GameManager::inFight = false;
bool GameManager::playerTurn = true;

int GameManager::levelWidth = 30;
int GameManager::levelHeight = 20;
int GameManager::currentRoom = 0;
int GameManager::roomCount = 1;
int GameManager::opponentsIndex =0;

short GameManager::xOffset = 0;
short GameManager::yOffset = 0;

Character* GameManager::player = nullptr;
Monster* GameManager::opponent = nullptr;

std::vector<Monster*>GameManager::enemiesInScene;
