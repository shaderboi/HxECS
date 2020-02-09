#pragma once

#include "../../Types.hpp"
#include <cstdlib>

namespace Hx { namespace Utils { namespace Memory {

	template<typename T>
	class MemPool
	{
	public:
		MemPool(size_t size);

		void* Allocate();
		void Free(void* block);

		size_t GetPoolSize();

	private:
		void Swap(size_t a, size_t b);
		void AddNode();
		void AllocatePool(size_t size);
		void DeallocatePool();

	private:
		uint8* Pool = nullptr;
		T** Marker = nullptr;
		size_t PoolSize;
		size_t Available;
		size_t Allocated = 0;
	};

	template<typename T>
	inline MemPool<T>::MemPool(size_t size)
		: PoolSize(size),
		Available(size)
	{
		this->AllocatePool(size);
	}

	template<typename T>
	inline void* MemPool<T>::Allocate()
	{
		if (Available <= 0)
			return nullptr;



		Allocated++;

		return nullptr;
	}

	template<typename T>
	inline void MemPool<T>::Free(void* block)
	{
	}

	template<typename T>
	inline size_t MemPool<T>::GetPoolSize()
	{
		return PoolSize;
	}

	template<typename T>
	inline void MemPool<T>::Swap(size_t a, size_t b)
	{
		uintptr_t temp = this->Marker[a];
		this->Marker[a] = this->Marker[b];
		this->Marker[b] = temp;
	}

	template<typename T>
	inline void MemPool<T>::AddNode()
	{

	}

	template<typename T>
	inline void MemPool<T>::AllocatePool(size_t size)
	{
		T* first;

		// Allocate memory for the pool and marker
		this->Pool = (uint8*)std::malloc(size * sizeof(T));
		this->Marker = (T**)std::malloc(size * sizeof(T*));

		// get the first address
		first = reinterpret_cast<T*>(&this->Pool[0]);

		// Initialize 
		for (int i = 0; i < this->PoolSize; i++)
		{
			this->Marker[i] = reinterpret_cast<T*>(first + i);
		}
	}
	
	template<typename T>
	inline void MemPool<T>::DeallocatePool()
	{
		std::free(this->Pool);
	}

}}}
