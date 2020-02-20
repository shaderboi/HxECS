#pragma once

#include "../Types.hpp"

namespace Hx { namespace ECS {

	union EntityID
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

		uint32 GetIndex() const
		{
			return this->Index;
		}

		uint32 GetGeneration() const
		{
			return this->Generation;
		}

		uint64 GetID() const
		{
			return this->ID;
		}

	private:
		struct
		{
			uint32 Index;
			uint32 Generation;
		};

		uint64 ID = 0;
	};

}}
