#include "gameworld.h"
#define GREEN "\033[42m ";
#define STANDARD "\033[0m ";

int** CreateLevel(int _width, int _height)
{
	int** array2D = 0; //initialize pointer

	array2D = new int* [_height];

	for (int h = 0; h < _height; h++)
	{
		array2D[h] = new int[_width]; //set width of the height index
		for (int w = 0; w < _width; w++)
		{
			if (h == 0 || h == _height - 1 || w == 0 || w == _width -1) {  //if outer corner set value of 1
				array2D[h][w] = 1;
			}
			else {
				array2D[h][w] = 0;
			}
		}
	}
	return array2D;
}

void DrawLevel(int** _level, int _width, int _height)
{
	for (int h = 0; h < _height; h++)
	{
		for (int w = 0; w < _width; w++)
		{
			//std::cout << _level[h][w];
			if (_level[h][w] == 1)
			{
				std::cout << GREEN;
			}
			else
			{
				std::cout << STANDARD;
			};
		}
		std::cout << "\n";
	} std::cout << STANDARD;
}

