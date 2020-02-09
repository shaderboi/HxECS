#pragma once

#include "Common.hpp"

namespace Hx { namespace ECS {

	class EntityManager;

	class Entity
	{
	public:
		Entity() = default;

		Entity(EntityManager* manager, const EntityID& id)
			: Manager(manager), ID(id)
		{
		}

		Entity(const Entity&) = default;

		Entity& operator=(const Entity&) = default;
		
	private:
		EntityManager* Manager;
		EntityID ID;
	};

}}
