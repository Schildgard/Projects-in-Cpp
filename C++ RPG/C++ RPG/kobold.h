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

	};

	 virtual void Attack(Character* _target) override;
};
