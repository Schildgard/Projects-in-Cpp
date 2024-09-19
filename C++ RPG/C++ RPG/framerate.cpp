#include "framerate.h"


std::chrono::high_resolution_clock::time_point FrameTimer:: frameStart = std::chrono::high_resolution_clock::now();
std::chrono::high_resolution_clock::time_point FrameTimer:: frameEnd = std::chrono::high_resolution_clock::now();

int FrameTimer::frameCounter = 0;


const std::chrono::duration<double> FrameTimer:: frameTime(0.033); // 0.1 = 10fps, 0.033 = 30 fps = 0.0167 = 60fps

std::chrono::duration<double> FrameTimer::CheckFrameDuration()
{
	frameEnd = std::chrono::high_resolution_clock::now();

	frameDuration = frameEnd - frameStart;

	return frameDuration;

}

std::chrono::duration<double> FrameTimer::frameDuration = FrameTimer::CheckFrameDuration();
