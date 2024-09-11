#include "player.h"

void Player::Attack(Character* _target) {
	std::cout << name << " attacks " << _target->name << "\n";
	_target->GetDamage(str);

};