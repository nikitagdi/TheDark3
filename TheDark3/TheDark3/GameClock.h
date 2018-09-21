#pragma once
#include <boost/timer/timer.hpp>

namespace TDEngine
{
	class GameClock
	{
	public:
		GameClock(float timeMul = 1.f);
		~GameClock();

		boost::timer::nanosecond_type getElapsed();
		boost::timer::nanosecond_type getCurrentTime() const;

		void setTimeMultiplier(float mul);

	private:
		boost::timer::cpu_timer clock;
		boost::timer::nanosecond_type last;

		float timeMultiplier;

	};

}