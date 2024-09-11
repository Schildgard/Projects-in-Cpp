#include "gameworld.h"
#define GREEN "\033[42m ";
#define RED "\033[41m ";
#define STANDARD "\033[0m ";

int** CreateLevel(int _width, int _height, Character* _player)
{
	int** array2D = 0; //initialize pointer

	array2D = new int* [_height];

	for (int h = 0; h < _height; h++)
	{
		array2D[h] = new int[_width]; //set width of the height index
		for (int w = 0; w < _width; w++)
		{
			if (h == 0 || h == _height - 1 || w == 0 || w == _width - 1)
			{  //if Wall set value to 1
				array2D[h][w] = 1;
			}
			else if (h == _player->Yposition && w == _player->Xposition)
			{
				array2D[h][w] = 7;
			}
			else
			{
				array2D[h][w] = 0;
			}
		}
	}
	return array2D;
}

void DrawLevel(int** _level, int _width, int _height)
{
	std::cout << "\033[H\33[J";
	for (int h = 0; h < _height; h++)
	{
		for (int w = 0; w < _width; w++)
		{
			if (_level[h][w] == 1)
			{
				std::cout << GREEN; // Colorize the Walls Green
			}
			else if (_level[h][w] == 7)
			{
				std::cout << RED;
			}
			else
			{
				std::cout << STANDARD; // Colorize the Ground Black
			};
		}
		std::cout << "\n";
	} std::cout << STANDARD; //After DrawMap, colorize Console in Black
}

