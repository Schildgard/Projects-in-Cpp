#pragma once
#include "monster.h"

class Zombie : public Monster {
public:
	Zombie() {
		name = "Zombie";
		hp = 5;
		str = 3;
		def = 2;
		spd = 2;
		exp = 4;

		dungeonLevel = 1;
	};
	bool resurrected = false;
	virtual void Die() override;

};
