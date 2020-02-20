// HxECS.cpp : Defines the entry point for the application.
//

#include "HxECS.h"

using namespace std;

using Hx::Utils::Memory::MemPool;
using Hx::ECS::System;
using Hx::ECS::EntityID;
using Hx::ECS::EntityManager;
using Hx::ECS::Entity;

struct MovementSystem : public System<MovementSystem>
{
};

struct PhysicsSystem : public System<PhysicsSystem>
{
};

int main()
{
	EntityManager mgr;
	Entity ent;

	mgr.SetMaxEntity(1024);
	ent = mgr.Create();
	mgr.Destroy(ent);

	return 0;
}
