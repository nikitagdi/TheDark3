#include "GraphicsEngine.h"

namespace TDEngine
{

	GraphicsEngine::GraphicsEngine()
	{
		//TODO: Make use of custom setting when creating window
		window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1440, 1050), "SFML window");

		window->setFramerateLimit(60);
		window->setActive(false);
	}


	GraphicsEngine::~GraphicsEngine()
	{
	}

	GraphicsEngine& GraphicsEngine::instance()
	{
		static GraphicsEngine inst;
		return inst;
	}

	void GraphicsEngine::registerGraphicsEssence(std::shared_ptr<GraphicsEssence> essence)
	{
		std::lock_guard<std::mutex> lock(essencesMutex);
		graphicsEssences.push_back(essence);
	}

	void GraphicsEngine::removeGraphicsEssence(std::shared_ptr<GraphicsEssence> essence)
	{
		//TODO: Implement
	}

	void GraphicsEngine::renderLoop()
	{
		window->setActive(true);
		while (true)
		{
			window->clear();

			essencesMutex.lock();
			for (auto& essence : graphicsEssences)
				window->draw(*essence->getSprite(), essence->getRenderStates());
			essencesMutex.unlock();

			window->display();
		}
	}
}
