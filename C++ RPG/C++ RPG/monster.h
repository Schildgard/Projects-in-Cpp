#pragma once

#include "character.h"


class Monster : public Character {
public:
	Monster() {};
	virtual void Attack(Character* _target) override;
};
