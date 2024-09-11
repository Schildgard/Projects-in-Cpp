#include <iostream>
#include "player.h"
#include "kobold.h"
#include "zombie.h"

int main() {
	Kobold* kobold = new Kobold();
	Zombie* zombie = new Zombie();
	Player* player = new Player();

	player->Attack(zombie);
	std::cout << "Zombie HP is: " << zombie->hp<< "\n";

	player->Attack(zombie);
	std::cout << "Zombie HP is: " << zombie->hp << "\n";

	player->Attack(zombie);


	return 0;
}