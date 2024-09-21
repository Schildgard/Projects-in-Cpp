#include "view.h"

#include "controller.h"

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

void Visualizer::DrawBattleScreen(int** _battleScreenArray)
{
	CLEARSCREEN
		for (int h = 0; h < 21; h++)
		{
			for (int w = 0; w < 25; w++)
			{
				if (_battleScreenArray[h][w] == 1)
				{
					std::cout << RED;
				}
				else std::cout << STANDARD
					std::cout << RESET;
			}
			std::cout << "\n";
		}


	RelocateCursorPosition(4, 3); //Numbers are tests
	std::cout << "Player HP";
	RelocateCursorPosition(5, 4);
	for (int i = 0; i < GameManager::player->hp; i++)
	{
		std::cout << GREEN;
	}
	std::cout << RESET;

	RelocateCursorPosition(4, 5); //Numbers are tests
	std::cout << "Enemy HP";
	RelocateCursorPosition(5, 6);
	for (int i = 0; i < GameManager::enemiesInScene[0]->hp; i++)
	{
		std::cout << GREEN;
	}
	std::cout << RESET;

}

void Visualizer::DrawPlayerBattleOption(int* _select)
{
	if (*_select == 1)
	{
		GameController::MoveCursorToBattleText();
		std::cout << " > Attack\n";
		std::cout << RED << RED << RESET << "   Flee";
	}
	else if (*_select ==2)
	{
		GameController::MoveCursorToBattleText();
		std::cout << "   Attack\n";
		std::cout << RED << RED << RESET << " > Flee";
	}

}

void Visualizer::DrawGameOverScreen()
{
	CLEARSCREEN;
	RelocateCursorPosition(5, 5);
	std::cout << " GAME OVER";
	getchar();
}

void Visualizer::WriteBattleText(std::string _text) //Probably unnecessary
{
	RelocateCursorPosition(3, 16);
	std::cout << _text;
}

void Visualizer::UpdateCharacterPosition(Character* _char)
{
	RelocateCursorPosition(_char->Xposition + GameManager::xOffset, _char->Yposition + GameManager::yOffset);
	std::cout << RED;
	RelocateCursorPosition(0, GameManager::levelHeight + 1); //relocate cursor to text field
	std::cout << STANDARD;
}

void Visualizer::UpdateMonsterPosition(Monster* _mon)
{
	if (_mon->dungeonLevel == 1)
	{
		RelocateCursorPosition(_mon->Xposition + GameManager::levelWidth, _mon->Yposition + 0);
		std::cout << MONSTER;
		RelocateCursorPosition(0, GameManager::levelHeight + 1); //relocate cursor to text field
		std::cout << STANDARD;
	}
	else if (_mon->dungeonLevel == 2)
	{
		RelocateCursorPosition(_mon->Xposition + GameManager::levelWidth, _mon->Yposition + GameManager::levelHeight);
		std::cout << MONSTER;
		RelocateCursorPosition(0, GameManager::levelHeight + 1); //relocate cursor to text field
		std::cout << STANDARD;
	}

}
void Visualizer::UpdateAllMonsterPositions()
{
	for (int i = 0; i < GameManager::enemiesInScene.size(); i++)
	{
		UpdateMonsterPosition(GameManager::enemiesInScene[i]);
	}
}

void Visualizer::RelocateCursorPosition(short _xOffset, short _yOffset)
{
	HANDLE currentPosition = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD startingPos = { _xOffset,_yOffset };
	SetConsoleCursorPosition(currentPosition, startingPos);
}

void Visualizer::ClearPreviousCharacterPosition(Character* _char)
{
	RelocateCursorPosition(_char->Xposition + GameManager::xOffset, _char->Yposition + GameManager::yOffset);
	std::cout << STANDARD;
}

void Visualizer::ClearPreviousMonsterPosition(Monster* _mon)
{
	if (_mon->dungeonLevel == 1)
	{
		RelocateCursorPosition(_mon->Xposition + GameManager::levelWidth, _mon->Yposition + 0);
		std::cout << STANDARD;
	}
	else if (_mon->dungeonLevel == 2)
	{
		RelocateCursorPosition(_mon->Xposition + GameManager::levelWidth, _mon->Yposition + GameManager::levelHeight);
		std::cout << STANDARD;
	}
}
