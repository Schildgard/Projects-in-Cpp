
#include "main.h"
#include "player.h"
#include "characterController.h"



int main()
{
	Start();
	Update(GameManager::player, GameManager::world);
	Exit();

	return 0;
}


void Start()
{
	// Initialize Level
	GameManager::player = new Player();
	GameManager::world = GameController::CreateLevel(GameManager::levelWidth, GameManager::levelHeight);
	Visualizer::DrawLevel();

	//Initialize BattleScreen
	GameManager::battleField = GameController::CreateBattleScreen();

}

void Update(Character* _player, int*** _level)
{
	bool gameIsRunning = true;
	int input = 0;
	int* select = nullptr; //represents the option when player is in battle

	int currentOption = 1; // even necessary?
	select = &currentOption;



	_level = GameController::CreateLevel(GameManager::levelWidth, GameManager::levelHeight);


	while (gameIsRunning)
	{
		FrameTimer::frameStart = std::chrono::high_resolution_clock::now(); //start counting FrameTime

		//PLAYER INPUT
		input = CharacterController::LookForInput();
		if (input != 0)
		{
			GameController::MoveCharacter(_player, _level, input);
		}


		//WAIT FOR FRAME TIME TO END
		FrameTimer::frameDuration = FrameTimer::CheckFrameDuration(); //compare startFrame with currentFrame
		while (FrameTimer::frameDuration < FrameTimer::frameTime) //wait until frameTime is reached
		{
			FrameTimer::frameDuration = FrameTimer::CheckFrameDuration();
		}


		//COUNT FRAMES TO CONTROL ENEMY BEHAVIOUR
		FrameTimer::frameCounter++;
		if (FrameTimer::frameCounter >= 15) //how fast enemy are supposed to move. framerate is limited to 30 fps so 30 means 1 move per second
		{
			//INSERT ENEMY BEHAVIOUR HERE
			if (!GameManager::enemiesInScene.empty())
			{

				for (int i = 0; i < GameManager::enemiesInScene.size(); i++)
				{
					Visualizer::ClearPreviousMonsterPosition(GameManager::enemiesInScene[i]);
					GameManager::enemiesInScene[i]->Move();
					Visualizer::UpdateMonsterPosition(GameManager::enemiesInScene[i]);
				}

			}
			FrameTimer::frameCounter = 0;
		}


		//BATTLE SCENE
		*select = 1; //first option is always 1
		while (GameManager::inFight)
		{
			Visualizer::DrawBattleScreen(GameManager::battleField);

			//PLAYER TURN
			while (GameManager::playerTurn)
			{
				Visualizer::DrawPlayerBattleOption(select);
				CharacterController::LookForInputNotAsync(select);
			}
			if (*select == 1) // PLAYER ATTACK
			{
				GameManager::player->Attack(GameManager::opponent);
				getchar();
				GameManager::playerTurn = false;
				if (GameManager::opponent->hp >= 1)
				{
					GameManager::opponent->Attack(GameManager::player);
					GameManager::playerTurn = true;
				}
				else
				{
					GameManager::enemiesInScene.erase(GameManager::enemiesInScene.begin()+ GameManager::opponentsIndex); //remove enemy after combat
					GameManager::inFight = false;
					if (GameManager::enemiesInScene.empty())
					{
						GameManager::roomCleared = true;
					}
				}
			}
			else if (*select == 2) //PLAYER FLEE
			{
				//insert flee option
			}
			getchar();
			Visualizer::DrawLevel();
		}
	}
}



void Exit()
{

}


