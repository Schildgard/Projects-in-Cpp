#pragma once
#include <chrono>

static class FrameTimer
{
public:

	static std::chrono::high_resolution_clock::time_point frameStart;
	static std::chrono::high_resolution_clock::time_point frameEnd;
	static std::chrono::duration<double> frameDuration;
	static const std::chrono::duration<double> frameTime;


	static std::chrono::duration<double> CheckFrameDuration();

	static int frameCounter; //counts how many frames have passed to control enemy AI

};