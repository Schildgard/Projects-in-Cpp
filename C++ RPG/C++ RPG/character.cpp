#include "character.h"

void Character :: GetDamage(int _damage) {
	int damage = _damage - def;
	damage <= 0 ? damage = 1 : damage = damage;
	hp -= damage;
	hp <= 0 ? hp = 0 : hp = hp;
	std::cout << name << " takes " << damage << " damage\n";

	if (hp == 0) { Die(); }

};
void Character::Die() {
	//_player->exp += exp;
	//std::cout << _player->name << " gains " << exp << " exp\n";
};

