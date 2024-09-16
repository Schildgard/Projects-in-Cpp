//#include <iomanip> // used to precise the console output to doubles

#include "main.h"
#include "framerate.h"
#include "player.h"
#include "characterController.h"



int main() {
	Player* player = new Player();

	int*** level = CreateLevel(GameManager::levelWidth, GameManager::levelHeight, player);
	DrawLevel(level, GameManager::levelWidth, GameManager::levelHeight, GameManager::roomCount);

	Start();
	Update(player, level);
	Exit();

	return 0;
}


void Start()
{

}

void Update(Character* _player, int*** _level)
{
	bool gameIsRunning = true;
	int input = 0;

	while (gameIsRunning)
	{
		FrameTimer::frameStart = std::chrono::high_resolution_clock::now(); //start counting FrameTime

		_level = CreateLevel(GameManager::levelWidth, GameManager::levelHeight, _player);
		input = LookForInput();
		if (input != 0)
		{
		MoveCharacter(_player, _level, input);
		}

		FrameTimer::frameDuration = FrameTimer::CheckFrameDuration(); //compare startFrae with currentFrame
		while(FrameTimer::frameDuration < FrameTimer::frameTime) //wait until frameTime is reached
		{
			FrameTimer::frameDuration = FrameTimer::CheckFrameDuration();
		}
	}
}



void Exit()
{

}


