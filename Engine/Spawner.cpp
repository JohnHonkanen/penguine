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
