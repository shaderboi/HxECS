#pragma once

#include "Common.hpp"
#include "EntityID.hpp"

namespace Hx { namespace ECS {

	class EntityManager;

	struct Entity
	{
		EntityManager* Manager;
		EntityID ID;

		Entity() = default;

		Entity(EntityManager* manager, const EntityID& id)
			: Manager(manager), ID(id)
		{
		}

		Entity(const Entity&) = default;

		Entity& operator=(const Entity&) = default;
	};

}}
