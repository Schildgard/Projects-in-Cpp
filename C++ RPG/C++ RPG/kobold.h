#pragma once
#include "monster.h"

class Kobold : public Monster {
public:
		Kobold() {
		name = "Kobold";
		hp = 3;
		str = 3;
		def = 3;
		spd = 3;
		exp = 3;

		colorCode = "\033[43m ";
		dungeonLevel = 2;
		moveSteps = 2;
		direction = 1;

	};

	 virtual void Attack(Character* _target) override;
};
