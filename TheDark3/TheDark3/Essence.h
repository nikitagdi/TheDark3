#pragma once
#include <memory>
namespace TDEngine
{
	class GameObject;
	using std::shared_ptr;

	class Essence
	{
	public:
		Essence(GameObject&);
		virtual ~Essence();

		virtual void update() = 0;

		virtual void destroy() = 0;
	protected:
		const GameObject* parent;
	};
}