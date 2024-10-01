#include "model.h"

int*** GameManager::world = 0;
int** GameManager::battleField = 0;
int** GameManager::bonfireScreen = 0;

bool GameManager::inFight = false;
bool GameManager::playerTurn = true;
bool GameManager::roomCleared = true;
bool GameManager::atBonfire = false;


bool GameManager::doorOpen = false;
bool GameManager::door1Open = false;
bool GameManager::door2Open = false;

bool GameManager::roomClear = true;
bool GameManager::room1Clear = false;
bool GameManager::room2Clear = false;


int GameManager::levelWidth = 30;
int GameManager::levelHeight = 20;
int GameManager::currentRoom = 0;
int GameManager::roomCount = 1;

short GameManager::xOffset = 0;
short GameManager::yOffset = 0;

Character* GameManager::player = nullptr;
Monster* GameManager::opponent = nullptr;

std::vector<Monster*>GameManager::enemiesInScene;

