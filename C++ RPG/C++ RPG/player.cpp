#include "player.h"

void Player::Attack(Character* _target)
{
	GameController::MoveCursorToBattleText();
	std::cout << name << " attacks " << _target->name << "\n";
	_target->GetDamage(str);

};

void Player::Die()
{
	Visualizer::DrawGameOverScreen();

}