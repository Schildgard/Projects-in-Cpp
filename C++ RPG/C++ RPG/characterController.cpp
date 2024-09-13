#include "characterController.h"

void MoveCharacter(Character* _player, int*** _level, int _input)
{
	int* yDisplacement = &_player->Yposition;
	int* xDisplacement = &_player->Xposition;

	int targetPositionValue = CheckTargetPosition(_player, _level, _input, yDisplacement,xDisplacement);

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
		GameManager::roomCount = GameManager::currentRoom + 2; //+2 because currentRoomIndex starts at 0 while roomCount starts at 1
		GameManager::currentRoom++;
		if (GameManager::currentRoom == 1)_player->Xposition = 1; // funktioniert in level 1, in level 2 aber nicht mehr
		//else if (GameManager::currentRoom == 2) _player->Yposition = 1;
		break;
	case 4:
		GameManager::currentRoom--;
		if (GameManager::currentRoom == 1)_player->Xposition = GameManager::levelWidth - 2; // funktioniert von level 2 in level 1, aber von level 3 in 2 wird das nicht funktionieren
		else if (GameManager::currentRoom == 2) _player->Yposition = GameManager::levelHeight -2;
		break;


	default:
		break;
	}

};

int CheckTargetPosition(Character* _player, int*** _level, int _input, int* _yDisplacement, int* _xDisplacement)
{
	int currentPositionValue = _level[GameManager::currentRoom][_player->Yposition][_player->Xposition];
	int targetPositionValue =1;


	switch (_input)
	{
	case 72: // UP
		if (_player->Yposition > 1 || _level[GameManager::currentRoom][_player->Yposition - 1][_player->Xposition] == 4) //check if player is on upper edge
		{
			targetPositionValue = _level[GameManager::currentRoom][_player->Yposition - 1][_player->Xposition];
			*_yDisplacement = _player->Yposition--;
		}
		break;
	case 80: //DOWN
		if (_player->Yposition < GameManager::levelHeight - 2 || _level[GameManager::currentRoom][_player->Yposition+1][_player->Xposition ] == 3) //check if player is on lower edge
		{
			targetPositionValue = _level[GameManager::currentRoom][_player->Yposition + 1][_player->Xposition];
			*_yDisplacement = _player->Yposition++;
		}
		break;
	case 75: //LEFT
		if (_player->Xposition > 1 || _level[GameManager::currentRoom][_player->Yposition][_player->Xposition - 1] == 4) //check if player is on left edge and / or if he enters a mirror Door
		{
			targetPositionValue = _level[GameManager::currentRoom][_player->Yposition][_player->Xposition - 1];
			*_xDisplacement = _player->Xposition--;
		}
		break;
	case 77: // RIGHT
		if (_player->Xposition < GameManager::levelWidth - 2 || _level[GameManager::currentRoom][_player->Yposition][_player->Xposition + 1] == 3) //check if player is on right edge or if player enters a door
		{
			targetPositionValue = _level[GameManager::currentRoom][_player->Yposition][_player->Xposition + 1];
			*_xDisplacement = _player->Xposition++;
		}
		break;
	default:
		break;
	}
	return targetPositionValue;

};