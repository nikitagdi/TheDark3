#include "GameObject.h"

namespace TDEngine
{

	GameObject::GameObject()
	{
	}


	GameObject::~GameObject()
	{
	}

	void GameObject::addEssence(const std::shared_ptr<Essence>& essence)
	{
		std::lock_guard<std::mutex> lock(essencesMutex);
		essences.push_back(essence);
	}
}
