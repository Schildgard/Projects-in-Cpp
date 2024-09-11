#include "zombie.h"

void Zombie::Die()
{
	if (!resurrected) {
	std::cout << "Zombie rises once more\n";
		hp = 1;
		resurrected = true;
	}
	else {
		std::cout << "Zombie finaly finds its peace\n";
	}
};
