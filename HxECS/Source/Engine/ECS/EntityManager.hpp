#pragma once

#include <vector>
#include <deque>
#include <bitset>
#include "Entity.hpp"

namespace Hx { namespace ECS {

	class EntityManager
	{
	public:
		EntityManager()
		{

		}

		~EntityManager()
		{

		}

		void SetMaxEntity(size_t maxEntity)
		{
			this->MaxEntity = maxEntity;
			this->EntityGeneration.reserve(maxEntity);
			this->FreeEntitySlots.reserve(maxEntity);
		}

		Entity Create()
		{
			uint32 index, generation;

		}

	private:
		std::vector<std::bitset<MaxComponent>> ComponentMask;
		std::vector<uint32> EntityGeneration; // May replaced with Hx::Utils::Container::Vector
		std::vector<uint32> FreeEntitySlots; // May replaced with Hx::Utils::Container::Deque

		size_t MaxEntity;
	};

}}
