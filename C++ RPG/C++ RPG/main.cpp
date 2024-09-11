#include <iostream>
#include "main.h"
#include "player.h"
#include "kobold.h"
#include "zombie.h"
#include "gameworld.h"

int main() {
	Kobold* kobold = new Kobold();
	Zombie* zombie = new Zombie();
	Player* player = new Player();

	//player->Attack(zombie);
	//std::cout << "Zombie HP is: " << zombie->hp<< "\n";
	//
	//player->Attack(zombie);
	//std::cout << "Zombie HP is: " << zombie->hp << "\n";
	//
	//player->Attack(zombie);

	int levelWidth = 15;
	int levelHeight = 20;

	int** level = CreateLevel(levelWidth, levelHeight);
	DrawLevel(level, levelWidth, levelHeight);


	return 0;
}


void Start()
{
	
}

void Update()
{
	
}

void Exit()
{
	
}


