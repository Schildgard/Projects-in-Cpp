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

	while (gameIsRunning)
	{
		FrameTimer::frameStart = std::chrono::high_resolution_clock::now(); //save time on frameStart

		MoveCharacter(_player, _level);

		_level = CreateLevel(GameManager::levelWidth, GameManager::levelHeight, _player);
		DrawLevel(_level, GameManager::levelWidth, GameManager::levelHeight, GameManager::roomCount);

		FrameTimer::frameDuration = FrameTimer::CheckFrameDuration();

		while(FrameTimer::frameDuration < FrameTimer::frameTime)
		{
			FrameTimer::frameDuration = FrameTimer::CheckFrameDuration();
		}

	}
}



void Exit()
{

}


