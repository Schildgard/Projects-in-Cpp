#include <iostream>
#include "main.h"
#include "player.h"
#include "kobold.h"
#include "zombie.h"
#include "gameworld.h"
#include "conio.h"

int main() {
	//Kobold* kobold = new Kobold();
	//Zombie* zombie = new Zombie();
	Player* player = new Player();

	//player->Attack(zombie);
	//std::cout << "Zombie HP is: " << zombie->hp<< "\n";
	//
	//player->Attack(zombie);
	//std::cout << "Zombie HP is: " << zombie->hp << "\n";
	//
	//player->Attack(zombie);

	int levelWidth = 15;
	int levelHeight = 20;

	int** level = CreateLevel(levelWidth, levelHeight, player);
	DrawLevel(level, levelWidth, levelHeight);

	Update(player,level, levelWidth,levelHeight);

	//level = CreateLevel(levelWidth, levelHeight, player);
	//DrawLevel(level, levelWidth, levelHeight);



	return 0;
}


void Start()
{

}

void Update(Character* _player,int** _level, int _width, int _height)
{
	bool gameIsRunning = true;


	while (gameIsRunning)
	{
		input = _getch();
		if (input == 224)
		{
			input = _getch();

			switch (input)
			{
			case 72:
				_player->Yposition--;
				break;
			case 80:
				_player->Yposition++;
				break;
			default:
				std::cout << "either";
				break;
			}
		}
		_level = CreateLevel(_width,_height,_player);
		DrawLevel(_level,_width,_height);
	}
}



void Exit()
{

}


