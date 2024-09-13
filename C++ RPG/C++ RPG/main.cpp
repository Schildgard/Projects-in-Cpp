#include <iostream>
#include "main.h"

#include <chrono>

#include "conio.h"
#include <WinUser.h>
#include <iomanip>

#include "gameworld.h"
#include "gameManager.h"
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

	std::chrono::high_resolution_clock::time_point startFrame;
	std::chrono::high_resolution_clock::time_point endFrame;
	std::chrono::duration <double> diff;

	const std::chrono::duration<double> frameTime(0.033);


	while (gameIsRunning)
	{

		startFrame = std::chrono::high_resolution_clock::now();
		
		input = _getch();
		//input = GetAsyncKeyState(VK_DOWN);
		if (input == 224) // if Arrow Key was pressed
		{
			input = _getch();
			MoveCharacter(_player, _level, input);
		
		}

		_level = CreateLevel(GameManager::levelWidth, GameManager::levelHeight, _player);
		DrawLevel(_level, GameManager::levelWidth, GameManager::levelHeight, GameManager::roomCount);
		std::cout << "time passed: " << std::fixed << std::setprecision(2) << diff.count(); //WTF


		endFrame = std::chrono::high_resolution_clock::now();
		diff = endFrame - startFrame; //


		while (diff < frameTime)  // Compare if singleFrameTime has passed
		{
			endFrame = std::chrono::high_resolution_clock::now();
			diff = endFrame - startFrame; //

		}


	}
}



void Exit()
{

}


