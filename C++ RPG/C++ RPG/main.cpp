#include  <Windows.h>
#include <iostream>
#include <chrono>
#include "conio.h"
#include <iomanip>
#include <WinUser.h>


#include "main.h"
#include "gameworld.h"
#include "gameManager.h"

#include "player.h"
#include "characterController.h"
#include "framerate.h"



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
		FrameTimer::frameStart = std::chrono::high_resolution_clock::now();

		
		//input = _getch();
		//input = GetAsyncKeyState(VK_DOWN);
	//if (input == 224) // if Arrow Key was pressed
	//{
	//	input = _getch();
		MoveCharacter(_player, _level);
	//
	//}

		_level = CreateLevel(GameManager::levelWidth, GameManager::levelHeight, _player);
		DrawLevel(_level, GameManager::levelWidth, GameManager::levelHeight, GameManager::roomCount);
		std::cout << "time passed: " << std::fixed << std::setprecision(2) << FrameTimer::frameDuration.count(); //WTF


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


