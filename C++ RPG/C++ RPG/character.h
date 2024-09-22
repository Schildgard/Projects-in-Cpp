#pragma once
#include <iostream>
#include <string.h>

class Character {
public:
	std::string name;
	int hp;
	int str;
	int def;
	int spd;
	int exp;

	int Yposition;
	int Xposition;

	std::string colorCode;

	virtual void Attack(Character* _target) = 0;
	virtual void GetDamage(int _damage);
	virtual void Die();
};
