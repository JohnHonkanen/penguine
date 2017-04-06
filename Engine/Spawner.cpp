/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "Spawner.h"



Spawner::Spawner()
{
}


Spawner::~Spawner()
{
}

Entity * Spawner::createEntity()
{
	Entity* entity = spawnEntity->instantiate();
	strategy->configureParticle(*entity);

	entity->setMovement(movement);
	entity->init();
	return entity;
}

void Spawner::setSpawnStrategy(AbstractSpawnStrategy * strategy)
{
	Spawner::strategy = strategy;
}

void Spawner::setSpawnEntity(Entity * spawnEntity)
{
	Spawner::spawnEntity = spawnEntity;
}

void Spawner::setEmitterEntity(Entity * in_emitter)
{
	emitter = in_emitter;
}

void Spawner::setMovementStrategy(Movement * in_movement)
{
	movement = in_movement;
}
