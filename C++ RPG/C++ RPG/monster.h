#pragma once

#include "character.h"


class Monster : public Character {
public:
	int dungeonLevel;
	Monster()
	{
	};
	virtual void Attack(Character* _target) override;
};
