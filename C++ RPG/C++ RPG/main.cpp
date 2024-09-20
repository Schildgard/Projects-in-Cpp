
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
				Visualizer::ClearPreviousMonsterPosition(GameManager::enemiesInScene[0]);
				GameManager::enemiesInScene[0]->Move();
				Visualizer::UpdateMonsterPosition(GameManager::enemiesInScene[0]);
				
			}
			FrameTimer::frameCounter = 0;
		}

		while(GameManager::inFight)
		{
			Visualizer::DrawBattleScreen(GameManager::battleField);
			Visualizer::DrawPlayerBattleOption();
			int input = getchar();
		}




	}
}



void Exit()
{

}


