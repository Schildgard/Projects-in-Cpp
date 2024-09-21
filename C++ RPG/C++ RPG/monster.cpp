#include "monster.h"
#include "model.h"


void Monster::Attack(Character* _target)
{
	GameController::MoveCursorToBattleText();
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

	if(Yposition == GameManager::player->Yposition && Xposition == GameManager::player->Xposition && dungeonLevel == GameManager::currentRoom)
	{
		std::cout << "Encounter";
	}
}
