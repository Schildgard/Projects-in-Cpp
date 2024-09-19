#include "monster.h"



void Monster::Attack(Character* _target)
{
	std::cout << name << " attacks " << _target->name << "\n";
	_target->GetDamage(str);
}
