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
				else if (h == 5 && w == 5 && c == 0) // BONFIRE SPAWN
				{
					array2D[h][w] = 2;
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

int** GameController::CreateBattleScreen()
{
	int** battleScreenArray = nullptr;
	battleScreenArray = new int* [21];


	int* width = nullptr;

	width = new int[25] { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; battleScreenArray[0] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; battleScreenArray[1] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; battleScreenArray[2] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; battleScreenArray[3] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; battleScreenArray[4] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; battleScreenArray[5] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; battleScreenArray[6] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; battleScreenArray[7] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; battleScreenArray[8] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; battleScreenArray[9] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; battleScreenArray[10] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; battleScreenArray[11] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; battleScreenArray[12] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; battleScreenArray[13] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; battleScreenArray[14] = width;
	width = new int[25] { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; battleScreenArray[15] = width;
	width = new int[25] { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 }; battleScreenArray[16] = width;
	width = new int[25] { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 }; battleScreenArray[17] = width;
	width = new int[25] { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 }; battleScreenArray[18] = width;
	width = new int[25] { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 }; battleScreenArray[19] = width;
	width = new int[25] { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; battleScreenArray[20] = width;



	return battleScreenArray;


}

int** GameController::CreateBonfireScreen()
{

	int** bonfireScreenArray = nullptr;
	bonfireScreenArray = new int* [21];


	int* width = nullptr;

	width = new int[25] { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; bonfireScreenArray[0] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; bonfireScreenArray[1] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; bonfireScreenArray[2] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; bonfireScreenArray[3] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; bonfireScreenArray[4] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; bonfireScreenArray[5] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; bonfireScreenArray[6] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; bonfireScreenArray[7] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; bonfireScreenArray[8] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; bonfireScreenArray[9] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; bonfireScreenArray[10] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; bonfireScreenArray[11] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; bonfireScreenArray[12] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; bonfireScreenArray[13] = width;
	width = new int[25] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }; bonfireScreenArray[14] = width;
	width = new int[25] { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; bonfireScreenArray[15] = width;
	width = new int[25] { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 }; bonfireScreenArray[16] = width;
	width = new int[25] { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 }; bonfireScreenArray[17] = width;
	width = new int[25] { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 }; bonfireScreenArray[18] = width;
	width = new int[25] { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 }; bonfireScreenArray[19] = width;
	width = new int[25] { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; bonfireScreenArray[20] = width;

	return bonfireScreenArray;
}

void GameController::MoveCharacter(Character* _player, int*** _level, int _input)
{
	Visualizer::ClearPreviousCharacterPosition(_player);

	int* yDisplacement = &_player->Yposition;
	int* xDisplacement = &_player->Xposition;

	int targetPositionValue = CheckTargetPosition(_player, _level, _input);


	switch (targetPositionValue)
	{
	case 0: // NORMAL GROUND
		//CHANGE CHARACTER POSITION
		ChangeCharacterPosition(_input, yDisplacement, xDisplacement);
		break;
	case 1: //WALL
		// DO NOT MOVE CHARACTER
		break;
	case 2:
		GameManager::atBonfire = true;
		GameManager::playerTurn = true; // PLAYER TURN SHOULD	 BE CHANGED TO PLAYER CHOOSE OPTION
		break;
	case 3:// DOOR
		//DO DIFFERENT CHECKS
		if (CheckDoorStatus() == false) //IF DOOR IS CLOSED
		{
			if (CheckRoomClear() == true) // IF ROOM IS CLEARED
			{
				OpenNewRoom();
				ChangeCurrentRoom(+1); // TODO: Change to constant
				ChangeCharacterPosition(_input, yDisplacement, xDisplacement);
			}
			else break;
		}
		else //IF DOOR IS OPEN
		{
			ChangeCurrentRoom(+1);
			ChangeCharacterPosition(_input, yDisplacement, xDisplacement);
		}
		if (!GameManager::enemiesInScene.empty())
		{
			Visualizer::UpdateAllMonsterPositions();
		}
		break;
	case 4:
		ChangeCurrentRoom(-1); // TODO: Change to constant
		break;
	default:
		break;
	}

	CheckCollisionWithMonster();
	Visualizer::UpdateCharacterPosition(_player);


}

int GameController::CheckTargetPosition(Character* _player, int*** _level, int _input)
{
	//CHECKS TARGET POSITION FOR ITS VALUE IN WORLD ARRAY
	int targetPositionValue = 1;

	switch (_input)
	{
	case 1:
		if (_player->Yposition > 1 || _level[GameManager::currentRoom][_player->Yposition - 1][_player->Xposition] == 4) //check if player is on upper edge
		{
			targetPositionValue = _level[GameManager::currentRoom][_player->Yposition - 1][_player->Xposition];
		}
		break;
	case -1:
		if (_player->Yposition < GameManager::levelHeight - 2 || _level[GameManager::currentRoom][_player->Yposition + 1][_player->Xposition] == 3 && GameManager::roomCleared) //check if player is on lower edge
		{
			targetPositionValue = _level[GameManager::currentRoom][_player->Yposition + 1][_player->Xposition];
		}
		break;
	case 2:
		if (_player->Xposition < GameManager::levelWidth - 2 || _level[GameManager::currentRoom][_player->Yposition][_player->Xposition + 1] == 3 && GameManager::roomCleared) //check if player is on right edge or if player enters a door
		{
			targetPositionValue = _level[GameManager::currentRoom][_player->Yposition][_player->Xposition + 1];
		}
		break;
	case -2:
		if (_player->Xposition > 1 || _level[GameManager::currentRoom][_player->Yposition][_player->Xposition - 1] == 4) //check if player is on left edge and / or if he enters a mirror Door
		{
			targetPositionValue = _level[GameManager::currentRoom][_player->Yposition][_player->Xposition - 1];
		}
		break;
	default:
		break;
	}

	return targetPositionValue;

}

void GameController::ChangeCharacterPosition(int _input, int* _yDisplacement, int* _xDisplacement)
{
	switch (_input)
	{
	case 1:  // UP
		*_yDisplacement = --GameManager::player->Yposition;
		break;
	case -1: //DOWN		 
		*_yDisplacement = ++GameManager::player->Yposition;
		break;
	case 2: //RIGHT		 
		*_xDisplacement = ++GameManager::player->Xposition;
		break;
	case -2: //LEFT		  
		*_xDisplacement = --GameManager::player->Xposition;
		break;
	default:
		break;
	}
};

void GameController::ChangeCurrentRoom(int _multiplier)
{
	//either 1 for next level or -1 for previous level
	GameManager::currentRoom += _multiplier;


	// CHANGE CURRENT ROOM INFORMATION AND OFFSET
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

	// SET PLAYER POSITION AT CORRECT SIDE OF THE NEW ROOM

	if (_multiplier == +1) // MULTIPLIER IS +1 IF PLAYERS ENTERS A DOOR
	{
		if (GameManager::currentRoom == 1)GameManager::player->Xposition = 1;
		else if (GameManager::currentRoom == 2) GameManager::player->Yposition = 1;
	}

	if (_multiplier == -1) //MULTIPLIER IS -1 IF PLAYER BACKTRACKS THROUGH A DOOR
	{
		if (GameManager::currentRoom == 0)GameManager::player->Xposition = GameManager::levelWidth - 2;
		else if (GameManager::currentRoom == 1) GameManager::player->Yposition = GameManager::levelHeight - 2;
	}

}

void GameController::OpenNewRoom()
{
	GameManager::roomCount = GameManager::currentRoom + 2;//+2 because currentRoomIndex starts at 0 while roomCount starts at 1
	SpawnMonsters();
	Visualizer::DrawLevel();

	if (GameManager::currentRoom == 0)
	{
		GameManager::doorOpen = true;
	}
	if (GameManager::currentRoom == 1)
	{
		GameManager::door1Open = true;
	}
	if (GameManager::currentRoom == 2)
	{
		GameManager::door2Open = true;
	}
}

void GameController::SpawnMonsters()
{
	if (GameManager::currentRoom == 0) //When entering room 1 from room 0
	{
		Zombie* Zombie01 = new Zombie();
		Zombie* Zombie02 = new Zombie();

		switch (GameManager::roomCount)
		{
		case 1:
			break;
		case 2:
			Zombie01->Xposition = 5;
			Zombie01->Yposition = 5;
			Zombie02->Xposition = 10;
			Zombie02->Yposition = 10;

			GameManager::enemiesInScene.push_back(Zombie01);  //IS GOING TO BNE REMOVED
			GameManager::enemiesInScene.push_back(Zombie02);

			//GameManager::enemiesInLevel1.push_back(Zombie01);
			//GameManager::enemiesInLevel1.push_back(Zombie02);
			break;
		case 3:
			break;
		default:
			break;
		}
		GameManager::room1Clear = false;
	}
	else if (GameManager::currentRoom == 1) //When entering room2 from room1
	{
		Kobold* Kobold01 = new Kobold();
		Kobold* Kobold02 = new Kobold();
		Kobold* Kobold03 = new Kobold();

		Kobold01->Xposition = 8;
		Kobold01->Yposition = 12;
		Kobold02->Xposition = 2;
		Kobold02->Yposition = 3;
		Kobold03->Xposition = 6;
		Kobold03->Yposition = 8;

		GameManager::enemiesInScene.push_back(Kobold01);
		GameManager::enemiesInScene.push_back(Kobold02);
		GameManager::enemiesInScene.push_back(Kobold03);

		//GameManager::enemiesInLevel2.push_back(Kobold01);
		//GameManager::enemiesInLevel2.push_back(Kobold02);
		//GameManager::enemiesInLevel2.push_back(Kobold03);

		GameManager::room2Clear = false;

	}
}

bool GameController::CheckDoorStatus()
{
	if (GameManager::currentRoom == 0)
	{
		return GameManager::doorOpen;
	}
	if (GameManager::currentRoom == 1)
	{
		return GameManager::door1Open;
	}
	if (GameManager::currentRoom == 2)
	{
		return GameManager::door2Open;
	}
}

bool GameController::CheckRoomClear()
{
	if (GameManager::currentRoom == 0)
	{
		return GameManager::roomClear;
	}
	if (GameManager::currentRoom == 1)
	{
		return GameManager::room1Clear;
	}
	if (GameManager::currentRoom == 2)
	{
		return GameManager::room2Clear;
	}
}

void GameController::CheckEnemyInLevel()
{
	int monsterCount = 0;
	// ITERATE THOUGH ENEMIES IN SCENE AND CHECK FOR DUNGEON LEVEL. IF IS EMPTY SET ROOM CLEAR BOOL
	for (int i = 0; i < GameManager::enemiesInScene.size(); i++)
	{
		if (GameManager::enemiesInScene[i]->dungeonLevel == GameManager::currentRoom)
		{
			monsterCount++;
		}
	}
	if (monsterCount <= 0)
	{
		//SET ROOM CLEAR OF CURRENT LEVEL TO TRUE
		if (GameManager::currentRoom == 0)
		{
			GameManager::roomClear = true;
		}
		else if (GameManager::currentRoom == 1)
		{
			GameManager::room1Clear = true;
		}
		else if (GameManager::currentRoom == 2)
		{
			GameManager::room2Clear = true;
		}
	}
}


void GameController::CheckCollisionWithMonster()
{
	for (int i = 0; i < GameManager::enemiesInScene.size(); i++)
	{
		if (GameManager::player->Xposition == GameManager::enemiesInScene[i]->Xposition && GameManager::player->Yposition == GameManager::enemiesInScene[i]->Yposition && GameManager::currentRoom == GameManager::enemiesInScene[i]->dungeonLevel)
		{
			GameManager::opponentsIndex = i; //save the index of monster to remove it after fight
			StartFight(GameManager::enemiesInScene[i]);

		}
	}
}

void GameController::StartFight(Monster* _enemy)
{
	GameManager::opponent = _enemy;
	GameManager::inFight = true;

}

void GameController::MoveCursorToBattleText()
{
	Visualizer::RelocateCursorPosition(3, 16);

}

void GameController::SetPlayerOption(int* _input, int* _currentOption)
{
	if (*_input == 1 && *_currentOption > 1)
	{
		--*_currentOption;
	}
	else if (*_input == 2 && *_currentOption < 4)
	{
		++*_currentOption;
	}

	else if (*_input == 3) // LEFT
	{
		switch (*_currentOption)
		{
		case 1:
			GameManager::player->hp--;
			break;
		case 2:
			GameManager::player->str--;
			break;
		case 3:
			GameManager::player->def--;
			break;
		default:
			break;
		}
	}
	else if (*_input == 4) //RIGHT
	{
		switch (*_currentOption)
		{
		case 1:
			GameManager::player->hp++;
			break;
		case 2:
			GameManager::player->str++;
			break;
		case 3:
			GameManager::player->def++;
			break;
		default:
			break;
		}
	}

	else if (*_input == 13 && *_currentOption == 4) // IF PLAYER PRESS ENTER ON EXIT
	{
		GameManager::playerTurn = false;

	}

	std::cout << "\n current Option Index: " << *_currentOption;
}




