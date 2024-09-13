#include "framerate.h"


std::chrono::high_resolution_clock::time_point FrameTimer:: frameStart = std::chrono::high_resolution_clock::now();
std::chrono::high_resolution_clock::time_point FrameTimer:: frameEnd = std::chrono::high_resolution_clock::now();


const std::chrono::duration<double> FrameTimer:: frameTime(0.033);

std::chrono::duration<double> FrameTimer::CheckFrameDuration()
{
	frameEnd = std::chrono::high_resolution_clock::now();

	frameDuration = frameEnd - frameStart;

	return frameDuration;

}

std::chrono::duration<double> FrameTimer::frameDuration = FrameTimer::CheckFrameDuration();
