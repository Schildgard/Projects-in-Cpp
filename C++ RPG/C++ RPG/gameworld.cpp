#include "gameworld.h"


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




