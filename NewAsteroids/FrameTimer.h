#pragma once
#include <chrono>

class FrameTimer
{
public:
	// Constructors //
	FrameTimer();

	// Public Functions //
	float Mark();
private:
	// Private Objects //
	std::chrono::steady_clock::time_point last;
};