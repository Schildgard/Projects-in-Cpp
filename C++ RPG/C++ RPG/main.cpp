#include <iostream>
#include "main.h"
#include "player.h"
#include "kobold.h"
#include "zombie.h"
#include "gameworld.h"
#include "conio.h"


#define UP_ARROW 72;
#define DOWN_ARROW 80;
#define LEFT_ARROW 75;
#define RIGHT_ARROW 77;

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

	int levelWidth = 30;
	int levelHeight = 20;

	int** level = CreateLevel(levelWidth, levelHeight, player);
	DrawLevel(level, levelWidth, levelHeight);



	Start();
	Update(player,level, levelWidth,levelHeight);
	Exit();



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
		if (input == 224) // if Arrow Key was pressed
		{
			input = _getch();

			switch (input) //check which Arrowkey pressed
			{
			case 72: // UP
				_player->Yposition > 1 ? _player->Yposition-- : _player->Yposition = 1; // if player is on upper wall, dont move
				break;
			case 80: //DOWN
				_player->Yposition < _height-2 ? _player->Yposition++ : _player->Yposition = _height-2; // if player is on down wall, dont move
				break;
			case 75: //LEFT
				_player->Xposition > 1 ? _player->Xposition-- : _player->Xposition = 1; // if player is on left wall, dont move
				break;
			case 77: // RIGHT
				_player->Xposition < _width - 2 ? _player->Xposition++ : _player->Xposition = _width - 2; //if player in on right wall, dont move
				break;

			default:
				std::cout << "either";
				break;
			}
		}
		_level = CreateLevel(_width,_height,_player);
		DrawLevel(_level,_width,_height);
		std::cout << "player moved to " << _player->Yposition << "of " << _height-2 << "\n";
		std::cout << " player moved to " << _player->Xposition << "of " << _width - 2;
	}
}



void Exit()
{

}


