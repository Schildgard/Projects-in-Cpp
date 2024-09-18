#include "view.h"

void Visualizer::DrawLevel()
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
				if (GameManager::world[c][h][w] == 1) // if wall
				{
					std::cout << GREEN; // Colorize the Walls Green
				}
				else if (GameManager::world[c][h][w] == 3)
				{
					std::cout << DOOR;
				}
				else if (GameManager::world[c][h][w] == 4)
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

void Visualizer::UpdateCharacterPosition(Character* _char)
{
	RelocateCursorPosition(_char->Xposition + GameManager::xOffset, _char->Yposition + GameManager::yOffset);
	std::cout << RED;
	RelocateCursorPosition(0, GameManager::levelHeight + 1); //relocate cursor to text field
	std::cout << STANDARD;
}

void Visualizer::RelocateCursorPosition(short _xOffset, short _yOffset)
{
	HANDLE currentPosition = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD startingPos = { _xOffset,_yOffset };
	SetConsoleCursorPosition(currentPosition, startingPos);
}

void Visualizer:: ClearPreviousCharacterPosition(Character* _char)
{
	RelocateCursorPosition(_char->Xposition + GameManager::xOffset, _char->Yposition + GameManager::yOffset);
	std::cout << STANDARD;
}
