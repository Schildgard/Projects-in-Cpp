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



	for (int c = 0; c < GameManager::roomCount; c++)
	{
		int** array2D = 0;
		array2D = new int* [_height];



		for (int h = 0; h < _height; h++)
		{
			array2D[h] = new int[_width]; //set width of the height index
			for (int w = 0; w < _width; w++)
			{
				if (h == 0 || h == _height - 1 || w == 0 || w == _width - 1)
				{  
					if (c == 0 && h == ((_height - 1) / 2) && w == _width - 1 || c == 1 && h ==_height-1 &&  w == _width/2) //Create DOOR. Different places for room 1 and 2
					{
						array2D[h][w] = 3;
					} else
					array2D[h][w] = 1; //if Wall set value to 1
				}
				else if (h == _player->Yposition && w == _player->Xposition && c == GameManager::currentRoom)
				{
					array2D[h][w] = 7;
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

void DrawLevel(int*** _level, int _width, int _height, int _roomCount)
{
	std::cout << "\033[H\33[J";

	int xOffset;
	int yOffset = 0;


	for (int c = 0; c < _roomCount; c++)
	{
		if (c == 0) { xOffset = 0; }
		else if (c == 1) { xOffset = _width; }
		else if (c == 2) { xOffset = _width * 2; }




		for (int h = 0; h < _height; h++)
		{
			for (int i = 0; i < xOffset; i++) //Add Offset
			{
				RelocateCursorPosition(xOffset, h);
			}

			for (int w = 0; w < _width; w++)
			{
				if (_level[c][h][w] == 1) // if wall
				{
					std::cout << GREEN; // Colorize the Walls Green
				}
				else if (_level[c][h][w] == 7) // if player
				{

					std::cout << RED;
				}
				else if (_level[c][h][w] == 3)
				{
					std::cout << DOOR;
				}
				else //if ground
				{
					std::cout << STANDARD; // Colorize the Ground Black
				};
			}
			std::cout << STANDARD; //reset after line is finished
			std::cout << "\n";
		}
		std::cout << STANDARD; //After DrawMap, colorize Console in Black

		if (c < _roomCount - 1)
		{
			RelocateCursorPosition(0, 0); //Do not relocate cursor in last iteration, so that the gametext gets displayed under the level screen
		}

	}
}


void RelocateCursorPosition(int _xOffset, int _yOffset) {
	HANDLE currentPosition = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD startingPos = { _xOffset,_yOffset };
	SetConsoleCursorPosition(currentPosition, startingPos);

}



