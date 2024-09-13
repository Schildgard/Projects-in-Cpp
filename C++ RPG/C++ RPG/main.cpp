#include <iostream>
#include "main.h"
#include "conio.h"

#include "gameworld.h"
#include "gameManager.h"
#include "player.h"
#include "characterController.h"



int main() {

	Player* player = new Player();

	int*** level = CreateLevel(GameManager::levelWidth, GameManager::levelHeight, player);
	DrawLevel(level, GameManager::levelWidth, GameManager::levelHeight, GameManager::roomCount);

	Start();
	Update(player,level);
	Exit();

	return 0;
}


void Start()
{

}

void Update(Character* _player,int*** _level)
{
	bool gameIsRunning = true;


	while (gameIsRunning)
	{
		input = _getch();
		if (input == 224) // if Arrow Key was pressed
		{
			input = _getch();
			MoveCharacter(_player, _level, input);

		}
		_level = CreateLevel(GameManager::levelWidth,GameManager::levelHeight,_player);
		DrawLevel(_level,GameManager::levelWidth,GameManager::levelHeight, GameManager::roomCount);

		//std::cout << "player moved to " << _player->Yposition << " of levelheight: " << GameManager::levelHeight << "\n";
		//std::cout << " player moved to " << _player->Xposition << " of levelwidth: " << GameManager::levelWidth;
	}
}



void Exit()
{

}


