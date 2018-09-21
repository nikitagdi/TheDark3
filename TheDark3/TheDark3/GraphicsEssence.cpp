#include "GraphicsEssence.h"
#include <utility>
#include "GameObject.h"
#include "PhysicalEssence.h"
#include "Logger.h"
#include "GraphicsEngine.h"

namespace TDEngine
{
	GraphicsEssence::GraphicsEssence(GameObject& par, std::shared_ptr<sf::Sprite> spr)
		: Essence(par), sprite(std::move(spr))
	{
		//TODO: Can be source of errors (see Essence::Essence() comment)
		TDEngine::GraphicsEngine::instance().registerGraphicsEssence
			(std::shared_ptr<GraphicsEssence>(this));
	}


	GraphicsEssence::~GraphicsEssence()
	{
		Logger::instance().LogInfo("Destructor ge is called");
	}

	void GraphicsEssence::update()
	{
		/*const auto physicsEssence = parent->getEssence<PhysicalEssence>();
		if(physicsEssence == nullptr)
		{
			Logger::instance().LogError("Cannot locate physical essence for rendering information.", "Graphics essence handler");
			return;
		}

		renderStates = sf::RenderStates::Default;
		renderStates.transform.translate(physicsEssence->getPosition());*/
	}

	void GraphicsEssence::destroy()
	{
		//TODO: Add implementation
	}
}
