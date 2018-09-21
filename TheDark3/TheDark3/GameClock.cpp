#include "pch.h"
#include "GameClock.h"

namespace TDEngine
{
	GameClock::GameClock(float timeMul)
		: timeMultiplier(timeMul)
	{
		last = clock.elapsed().wall * timeMultiplier;
	}


	GameClock::~GameClock()
	{
	}

	boost::timer::nanosecond_type GameClock::getElapsed()
	{
		auto current = clock.elapsed().wall;
		auto elapsed = (current - last) * timeMultiplier;
		last = current;

		return elapsed;
	}

	boost::timer::nanosecond_type GameClock::getCurrentTime() const
	{
		static auto lastC = clock.elapsed().wall;
		auto correctedTime = lastC + (clock.elapsed().wall - lastC) * timeMultiplier;
		lastC = clock.elapsed().wall;

		return correctedTime;
	}

	void GameClock::setTimeMultiplier(float mul)
	{
		timeMultiplier = mul;
	}
}
