#pragma once

#include "../Types.hpp"

namespace Hx { namespace ECS {

	class EntityID
	{
	public:
		EntityID()
		{
		}

		EntityID(uint64 id)
			: ID(id)
		{
		}

		EntityID(uint32 index, uint32 gen)
			: Index(index), Generation(gen)
		{
		}

		EntityID(const EntityID& other)
			: ID(other.ID)
		{
		}

		EntityID& operator=(const EntityID& other)
		{
			this->ID = other.ID;
			return *this;
		}

		uint32 GetIndex()
		{
			return this->Index;
		}

		uint32 GetGeneration()
		{
			return this->Generation;
		}

		uint64 GetID()
		{
			return this->ID;
		}

	private:
		union
		{
			struct
			{
				uint32 Index = 0;
				uint32 Generation = 0;
			};

			uint64 ID = 0;
		};
	};

}}
