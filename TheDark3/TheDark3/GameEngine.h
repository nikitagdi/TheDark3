#pragma once
#include <thread>
#include "GameClock.h"
#include "Essence.h"
#include <vector>
#include "Essence.h"
#include "ThreadPool.h"
#include <mutex>

namespace TDEngine
{
	class GameEngine
	{
	public:
		static constexpr const int THREADPOOL_THREAD_COUNT = 12;

		static GameEngine& instance();

		void init();
		void gameLoop();

		void registerEssence(std::shared_ptr<Essence> essence);
		void deleteEssence(std::shared_ptr<Essence> essence);
	private:
		GameEngine& operator=(const GameEngine&) = default;
		GameEngine(const GameEngine&) = default;
		GameEngine();
		~GameEngine();

		GameClock gameClock;

		//Rendering thread
		std::shared_ptr<std::thread> renderThread;
		//Essence handling Threadpool
		ThreadPool threadpool;
		std::vector<std::shared_ptr<Essence>> essences;
		std::mutex essencesMutex;
	};

}
