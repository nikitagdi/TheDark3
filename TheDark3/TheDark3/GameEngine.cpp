#include "GameEngine.h"
#include "GraphicsEngine.h"
#include "GameObject.h"
#include "PhysicalEssence.h"
#include "Logger.h"


namespace TDEngine
{
	GameEngine& GameEngine::instance()
	{
		static GameEngine inst;
		return inst;
	}

	void GameEngine::init()
	{

	}

	void GameEngine::gameLoop()
	{
		const float logicTime = 1000 / 100.f;
		sf::RenderTexture tex;
		tex.create(32, 32);
		tex.draw(sf::RectangleShape({ 32, 32 }));
		std::vector<std::shared_ptr<GameObject>> objs;

		for(int i = 0; i < 100000; i++)
		{
			auto obj = std::make_shared<GameObject>();
			auto phys = std::make_shared<PhysicalEssence>(*obj);
			phys->applyForce(sf::Vector2f(rand() % 10 - 5, rand() % 10 - 5 ), (rand() % 1000 + 2000) * 1000000LL);
			obj->addEssence(phys);
			obj->addEssence(std::make_shared<GraphicsEssence>
				(*obj, std::make_shared<sf::Sprite>(tex.getTexture())));
			objs.push_back(obj);
		}

		renderThread = std::make_shared<std::thread>
			(&GraphicsEngine::renderLoop, &GraphicsEngine::instance());

		threadpool.init();

		while(true)
		{
			for (auto& essence : essences) {
				if (dynamic_cast<PhysicalEssence*>(essence.get()))
					dynamic_cast<PhysicalEssence*>(essence.get())->applyForce(sf::Vector2f(rand() % 10 - 5, rand() % 10 - 5), (rand() % 1000 + 2000) * 1000000LL);
			}

			for(auto& essence : essences)
				threadpool.submit(std::bind(&Essence::update, essence));



			while(threadpool.getRemainedTasks() > 0)
			{
				sf::Event event;
				while(GraphicsEngine::instance().getWindow()->pollEvent(event))
				{
					switch(event.type)
					{
					default:
						break;
					}
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
						
			float elapsed = gameClock.getElapsed() / 1000000.0;
			Logger::instance().LogInfo(std::to_string(elapsed));
			if (logicTime > elapsed)
				std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long>(logicTime - elapsed)));
		}
	}

	void GameEngine::registerEssence(std::shared_ptr<Essence> essence)
	{
		std::lock_guard<std::mutex> lock(essencesMutex);
		essences.push_back(essence);
	}

	void GameEngine::deleteEssence(std::shared_ptr<Essence> essence)
	{
		//TODO: IMPLEMENT
	}

	GameEngine::GameEngine()
		: threadpool(THREADPOOL_THREAD_COUNT)
	{
	}


	GameEngine::~GameEngine()
	{
	}

}
