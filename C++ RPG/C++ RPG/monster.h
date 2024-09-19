#pragma once

#include "character.h"


class Monster : public Character {
public:
	int dungeonLevel;
	int moveSteps;
	int direction;
	Monster()
	{
	};
	virtual void Attack(Character* _target) override;
	virtual void Move();
};
