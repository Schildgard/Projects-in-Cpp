#pragma once
#include "character.h"

class Player : public Character {
public:
	inline
		Player() {
		name = "Player";
		hp = 5;
		str = 5;
		def = 5;
		spd = 5;
		exp = 0;
	};

	virtual void Attack(Character* _target);
};
