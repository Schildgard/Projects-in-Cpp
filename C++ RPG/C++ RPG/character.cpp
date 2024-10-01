#include "character.h"
#include "controller.h"


void Character::Flee()
{
	GameManager::inFight = false;
	GameController::ChangeCurrentRoom(-1);
	GameManager::player->Xposition = 1;
	GameManager::player->Yposition = 1;

}

void Character :: GetDamage(int _damage) {
	int damage = _damage - def;
	damage <= 0 ? damage = 1 : damage = damage;
	hp -= damage;
	hp <= 0 ? hp = 0 : hp = hp;

	std::cout << RED " " << RESET << " " << name << " takes " << damage << " damage\n";
	//std::cout << "         ";

	if (hp == 0) { Die(); }

};
void Character::Die() {

};

