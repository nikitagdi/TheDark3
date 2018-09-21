#include "Essence.h"
#include "GameEngine.h"

namespace TDEngine
{
	Essence::Essence(GameObject& par)
		: parent(&par)
	{
		//Can possibly be a source of errors(use of the object before construction)
		//TODO: Place adding to game routines after creation of GameObject or inside GameObject constructor
		TDEngine::GameEngine::instance().registerEssence
			(std::shared_ptr<Essence>(this));
	}


	Essence::~Essence()
	{
	}
}
