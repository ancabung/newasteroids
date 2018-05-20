#include "FrameTimer.h"
using namespace std::chrono;

// Constructors //

FrameTimer::FrameTimer()
{
	last = steady_clock::now();
}

// Public Functions //

float FrameTimer::Mark()
{
	auto const old = last;
	last = steady_clock::now();
	const duration<float> Time = last - old;
	return Time.count();
}
