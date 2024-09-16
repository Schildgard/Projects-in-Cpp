#include "gameworld.h"

#include "gameManager.h"
#define GREEN "\033[42m ";
#define RED "\033[41m ";
#define STANDARD "\033[0m ";
#define DOOR "\033[44m ";


int*** CreateLevel(int _width, int _height, Character* _player)
{
	int*** array3D = 0; //initialize pointer
	array3D = new int** [GameManager::roomCount];



	for (int c = 0; c < 3; c++) //c stands for (room)-room count, so for each active room, a 2D array is generated
	{
		int** array2D = 0;
		array2D = new int* [_height];



		for (int h = 0; h < _height; h++)
		{
			array2D[h] = new int[_width]; //set width of the height index
			for (int w = 0; w < _width; w++)
			{
				if (h == 0 || h == _height - 1 || w == 0 || w == _width - 1)
				{   //Create DOOR to next room at fixed places
					if (c == 0 && h == ((_height - 1) / 2) && w == _width - 1 || c == 1 && h == _height - 1 && w == _width / 2)
					{
						array2D[h][w] = 3;
					}
					//Create Door to previous room parallel to other door
					else if (c == 1 && h == ((_height - 1) / 2) && w == 0 || c == 2 && h == 0 && w == _width / 2)
					{
						array2D[h][w] = 4;
					}
					else
					{
						array2D[h][w] = 1; //if Wall set value to 1
					}
				}
				else if (h == _player->Yposition && w == _player->Xposition && c == GameManager::currentRoom)
				{
					array2D[h][w] = 7; // set player start position
				}
				else
				{
					array2D[h][w] = 0;
				}
			}
		} array3D[c] = array2D;
	}
	return array3D;
}


void DrawLevel(int*** _level)
{
	std::cout << "\033[H\33[J";

	short xOffset = 0;
	short yOffset = 0;


	for (int c = 0; c < GameManager::roomCount; c++)
	{
		if (c == 0) { xOffset = 0; }
		else if (c == 1) { xOffset = GameManager::levelWidth; }
		else if (c == 2) { yOffset = GameManager::levelHeight; }

		for (int h = 0; h < GameManager::levelHeight; h++)
		{

			RelocateCursorPosition(xOffset, h + yOffset);

			for (int w = 0; w < GameManager::levelWidth; w++)
			{
				if (_level[c][h][w] == 1) // if wall
				{
					std::cout << GREEN; // Colorize the Walls Green
				}
				//else if (_level[c][h][w] == 7) // if player
				//{
				//	std::cout << RED;
				//}
				else if (_level[c][h][w] == 3)
				{
					std::cout << DOOR;
				}
				else if (_level[c][h][w] == 4)
				{
					std::cout << DOOR;
				}
				else //if ground
				{
					std::cout << STANDARD; // Colorize the Ground Black
				}
			}
			std::cout << STANDARD; //reset after line is finished
			std::cout << "\n";
		}
		std::cout << STANDARD; //After DrawMap, colorize Console in Black

		if (c < GameManager::roomCount - 1)
		{
			RelocateCursorPosition(0, 0); //Do not relocate cursor in last iteration, so that the gametext gets displayed under the level screen
		}
	}
}

void DrawCharacter(Character* _char)
{

	RelocateCursorPosition(_char->Xposition + GameManager::xOffset, _char->Yposition + GameManager::yOffset);
	std::cout << RED;
	RelocateCursorPosition(0, GameManager::levelHeight + 1); //relocate cursor to text field
	std::cout << STANDARD;
}

void ClearPreviousCharacterPosition(Character* _char)
{
	RelocateCursorPosition(_char->Xposition + GameManager::xOffset, _char->Yposition + GameManager::yOffset);
	std::cout << STANDARD;
}

void RelocateCursorPosition(short _xOffset, short _yOffset)
{
	HANDLE currentPosition = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD startingPos = { _xOffset,_yOffset };
	SetConsoleCursorPosition(currentPosition, startingPos);

}



