#pragma once

#include <vector>
#include <deque>
#include <bitset>
#include "Entity.hpp"

namespace Hx { namespace ECS {

	class EntityManager // : Hx::Utils::Traits::NonCopyable
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
		}

		Entity Create()
		{
			uint32 index;

			if (this->FreeEntitySlots.size() > 1024)
			{
				index = this->FreeEntitySlots.front();
				this->FreeEntitySlots.pop_front();
			}
			else
			{
				this->EntityGeneration.push_back(0);
				index = (uint32)(this->EntityGeneration.size() - 1);
			}

			return Entity(this, EntityID(index, this->EntityGeneration[index]));
		}

		bool IsAlive(const Entity& e)
		{
			return this->EntityGeneration[e.ID.GetIndex()] == e.ID.GetGeneration();
		}

		void Destroy(const Entity& e)
		{
			uint32 index = e.ID.GetIndex();
			++this->EntityGeneration[index];
			this->FreeEntitySlots.push_back(index);
		}

	private:
		std::vector<std::bitset<MaxComponent>> ComponentMask;
		std::vector<uint32> EntityGeneration; // May replaced with Hx::Utils::Container::Vector
		std::deque<uint32> FreeEntitySlots; // May replaced with Hx::Utils::Container::Deque

		size_t MaxEntity;
	};

}}
