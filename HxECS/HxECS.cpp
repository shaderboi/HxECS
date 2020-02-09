// HxECS.cpp : Defines the entry point for the application.
//

#include "HxECS.h"

using namespace std;

using Hx::Utils::Memory::MemPool;
using Hx::ECS::System;
using Hx::ECS::EntityID;

struct MovementSystem : public System<MovementSystem>
{
};

struct PhysicsSystem : public System<PhysicsSystem>
{
};

int main()
{
	EntityID id;
	return 0;
}
