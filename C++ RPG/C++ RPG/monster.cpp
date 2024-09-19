#include "monster.h"



void Monster::Attack(Character* _target)
{
	std::cout << name << " attacks " << _target->name << "\n";
	_target->GetDamage(str);
}

void Monster::Move()
{
	if (moveSteps >= 0)
	{
		Yposition += direction;
		moveSteps--;
	}
	else if (moveSteps <= 0)
	{
		moveSteps = 3;
		direction *= -1;
	}
}
