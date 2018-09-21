#pragma once
#include "Essence.h"
#include "GameClock.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <vector>
#include <mutex>

namespace TDEngine
{

	class PhysicalEssence :
		public Essence
	{
	public:
		PhysicalEssence(GameObject&);
		virtual ~PhysicalEssence();

		void update() override;
		void destroy() override;
		
		void applyForce(sf::Vector2f, boost::timer::nanosecond_type);
		
		sf::Vector2f getPosition() const
		{
			return position;
		}

		//sf::Vector2f getAcceleration() const
		//{
		//	return acceleration;
		//}

		sf::Vector2f getVelocity() const
		{
			return velocity;
		}

		sf::FloatRect getCBox() const
		{
			return cBox;
		}
	private:
		GameClock clock;

		//Current x, y coordinates
		sf::Vector2f position;
		//Current x, y acceleration components
		//sf::Vector2f acceleration;
		//Current x, y velocity components
		sf::Vector2f velocity;
		sf::Vector2f maxVelocity;
		//Mass
		float mass;
		//Collision box
		sf::FloatRect cBox;


		//Forces applied to the object. Each force has the lifetime
		std::vector<std::pair<sf::Vector2f, boost::timer::nanosecond_type>> forces;
	
		mutable std::mutex forcesMutex;
	};

}