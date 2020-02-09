#pragma once

namespace Hx { namespace ECS {

	class SystemBase
	{
	protected:
		static size_t IDCounter;
	};

	size_t SystemBase::IDCounter = 0;

	template<class T>
	class System : public SystemBase
	{
	public:
		System()
		{
		}

		virtual void Update() = 0;

		static size_t GetID()
		{
			return ID;
		}

	private:
		static size_t ID;
	};

	template<class T>
	size_t System<T>::ID = SystemBase::IDCounter++;

}}
