#pragma once
#include "Essence.h"
#include <SFML/Graphics.hpp>

namespace TDEngine
{
	class GraphicsEssence :
		public Essence
	{
	public:
		GraphicsEssence(GameObject&, std::shared_ptr<sf::Sprite>);
		virtual ~GraphicsEssence();

		void update() override;
		void destroy() override;

		auto getSprite() const
		{
			return sprite;
		}

		sf::RenderStates getRenderStates() const
		{
			return renderStates;
		}

	private:
		std::shared_ptr<sf::Sprite> sprite;
		sf::RenderStates renderStates;
	};

}