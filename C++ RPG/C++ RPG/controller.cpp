#include "controller.h"


int*** GameController::CreateLevel(int _width, int _height)
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
				else if (h == GameManager::player->Yposition && w == GameManager::player->Xposition && c == GameManager::currentRoom)
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

void GameController::MoveCharacter(Character* _player, int*** _level, int _input)
{
	Visualizer::ClearPreviousCharacterPosition(_player);

	int* yDisplacement = &_player->Yposition;
	int* xDisplacement = &_player->Xposition;

	int targetPositionValue = CheckTargetPosition(_player, _level, yDisplacement, xDisplacement, _input);
	switch (targetPositionValue)
	{
	case 0: // if targetPosition is normal ground
		_player->Yposition = *yDisplacement;
		_player->Xposition = *xDisplacement;
		break;
	case 1: // if targetPosition is a Wall, Displacement remains unchanged so the player does not move
		_player->Yposition = *yDisplacement;
		_player->Xposition = *xDisplacement;
		break;
	case 3:
		if (GameManager::roomCount < 3) // Open new Room if not opened yet
		{
			OpenNewRoom();
		}
		ChangeCurrentRoom(+1); // TODO: Change to constant
		if (GameManager::currentRoom == 1)_player->Xposition = 1;
		else if (GameManager::currentRoom == 2) _player->Yposition = 1;
		if (GameManager::activeEnemies != nullptr)
		{
			Visualizer::UpdateMonsterPosition(GameManager::activeEnemies);
		}
		break;
	case 4:
		ChangeCurrentRoom(-1); // TODO: Change to constant
		if (GameManager::currentRoom == 0)_player->Xposition = GameManager::levelWidth - 2;
		else if (GameManager::currentRoom == 1) _player->Yposition = GameManager::levelHeight - 2;
		break;
	default:
		break;
	}
	Visualizer::UpdateCharacterPosition(_player);
	

}

int GameController::CheckTargetPosition(Character* _player, int*** _level, int* _yDisplacement, int* _xDisplacement, int _input)
{
	int currentPositionValue = _level[GameManager::currentRoom][_player->Yposition][_player->Xposition];
	int targetPositionValue = 1;


	switch (_input)
	{
	case 1:
		if (_player->Yposition > 1 || _level[GameManager::currentRoom][_player->Yposition - 1][_player->Xposition] == 4) //check if player is on upper edge
		{
			targetPositionValue = _level[GameManager::currentRoom][_player->Yposition - 1][_player->Xposition];
			*_yDisplacement = _player->Yposition--;
		}
		break;
	case -1:
		if (_player->Yposition < GameManager::levelHeight - 2 || _level[GameManager::currentRoom][_player->Yposition + 1][_player->Xposition] == 3) //check if player is on lower edge
		{
			targetPositionValue = _level[GameManager::currentRoom][_player->Yposition + 1][_player->Xposition];
			*_yDisplacement = _player->Yposition++;
		}
		break;
	case 2:
		if (_player->Xposition < GameManager::levelWidth - 2 || _level[GameManager::currentRoom][_player->Yposition][_player->Xposition + 1] == 3) //check if player is on right edge or if player enters a door
		{
			targetPositionValue = _level[GameManager::currentRoom][_player->Yposition][_player->Xposition + 1];
			*_xDisplacement = _player->Xposition++;
		}
		break;
	case -2:
		if (_player->Xposition > 1 || _level[GameManager::currentRoom][_player->Yposition][_player->Xposition - 1] == 4) //check if player is on left edge and / or if he enters a mirror Door
		{
			targetPositionValue = _level[GameManager::currentRoom][_player->Yposition][_player->Xposition - 1];
			*_xDisplacement = _player->Xposition--;
		}
		break;
	default:
		break;
	}

	return targetPositionValue;

};

void GameController::ChangeCurrentRoom(int _multiplier)
{
	//either 1 for next level or -1 for previous level
	GameManager::currentRoom += _multiplier;

	switch (GameManager::currentRoom)
	{
	case 0:
		GameManager::xOffset = 0;
		GameManager::yOffset = 0;
		break;
	case 1:
		GameManager::xOffset = GameManager::levelWidth;
		GameManager::yOffset = 0;
		break;
	case 2:
		GameManager::yOffset = GameManager::levelHeight;
		break;
	}
}

void GameController::OpenNewRoom()
{
	GameManager::roomCount = GameManager::currentRoom + 2;//+2 because currentRoomIndex starts at 0 while roomCount starts at 1
	SpawnMonsters();
	Visualizer::DrawLevel();
}

void GameController::SpawnMonsters()
{
	if (GameManager::currentRoom == 0)
	{
		Zombie* Zombie01 = new Zombie();

		switch (GameManager::roomCount)
		{
		case 1:
			break;
		case 2:
			Zombie01->Xposition = 5;
			Zombie01->Yposition = 5;
			GameManager::activeEnemies = Zombie01;
			break;
		case 3:
			break;
		default:
			break;
		}
	}
}




