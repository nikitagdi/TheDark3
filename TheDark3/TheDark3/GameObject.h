#pragma once
#include <vector>
#include <memory>
#include "Essence.h"
#include <mutex>

namespace TDEngine
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		template<typename T>
		auto getEssence() const
		{
			std::lock_guard<std::mutex> lock(essencesMutex);
			for (auto& essence : essences)
				if (dynamic_cast<T*>(essence.get()))
					return std::dynamic_pointer_cast<T>(essence);
		}

		void addEssence(const std::shared_ptr<Essence>&);
	private:
		std::vector<std::shared_ptr<Essence> > essences;
		mutable std::mutex essencesMutex;
	};

}
