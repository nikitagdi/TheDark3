#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GraphicsEssence.h"
#include <mutex>

namespace TDEngine
{
	class GraphicsEngine
	{
	public:
		GraphicsEngine();
		~GraphicsEngine();

		static GraphicsEngine& instance();

		void registerGraphicsEssence(std::shared_ptr<GraphicsEssence>);
		void removeGraphicsEssence(std::shared_ptr<GraphicsEssence>);

		void renderLoop();


		std::shared_ptr<sf::RenderWindow> getWindow() const
		{
			return window;
		}

		//TODO: Add recreation of window with new settings
	private:
		std::shared_ptr<sf::RenderWindow> window;
		std::vector<std::shared_ptr<GraphicsEssence>> graphicsEssences;

		std::mutex essencesMutex;
	};

}
