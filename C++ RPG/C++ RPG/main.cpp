
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


}

void Update(Character* _player, int*** _level)
{
	bool gameIsRunning = true;
	int input = 0;

	while (gameIsRunning)
	{
		FrameTimer::frameStart = std::chrono::high_resolution_clock::now(); //start counting FrameTime

		_level = GameController::CreateLevel(GameManager::levelWidth, GameManager::levelHeight);
		input = CharacterController::LookForInput();
		if (input != 0)
		{
			GameController::MoveCharacter(_player, _level, input);
		}
		FrameTimer::frameDuration = FrameTimer::CheckFrameDuration(); //compare startFrae with currentFrame
		while (FrameTimer::frameDuration < FrameTimer::frameTime) //wait until frameTime is reached
		{
			FrameTimer::frameDuration = FrameTimer::CheckFrameDuration();
		}
	//if (GameManager::activeEnemies != nullptr)
	//{
	//	Visualizer::UpdateCharacterPosition(GameManager::activeEnemies);
	//	std::cout << GameManager::activeEnemies->name;
	//}
	}
}



void Exit()
{

}


