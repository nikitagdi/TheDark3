#include "PhysicalEssence.h"
#include <algorithm>
#include "Logger.h"

namespace TDEngine
{
	PhysicalEssence::PhysicalEssence(GameObject& par)
		: Essence(par)
	{
		//TODO: Add initialization from property
		clock.setTimeMultiplier(1.f);

		velocity = {0.f, 0.f};
		mass = 1;
	}


	PhysicalEssence::~PhysicalEssence()
	{
		Logger::instance().LogInfo("Destructor pe is called");
	}

	void PhysicalEssence::update()
	{
		/*std::lock_guard<std::mutex> lock(forcesMutex);	
		auto elapsed = clock.getElapsed();

		for(auto& force : forces)
		{
			float impactPeriod = force.second < elapsed ? force.second : force.second - elapsed;
			impactPeriod /= 1000000000LL;
			force.second -= elapsed;

			//acceleration += force.first / mass;
			velocity += force.first / mass * impactPeriod;

		}

		//TODO: Add a collision check
		position += velocity * static_cast<float>(elapsed / 1000000000.0);

		forces.erase(std::remove_if(forces.begin(), forces.end(), 
			[](std::pair<sf::Vector2f, boost::timer::nanosecond_type> elem) 
		{return elem.second < 0LL; }),
			forces.end());*/
	}

	void PhysicalEssence::destroy()
	{
		//TODO: Implement
	}

	void PhysicalEssence::applyForce(sf::Vector2f force, boost::timer::nanosecond_type period)
	{
		std::lock_guard<std::mutex> lock(forcesMutex);
		forces.push_back({force, period});
	}
}
