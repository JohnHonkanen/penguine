#include "Spawner.h"



Spawner::Spawner(int in_minLifeTime, int in_maxLifeTime)
{
	minLifeTime = in_minLifeTime;
	maxLifeTime = in_maxLifeTime;
}


Spawner::~Spawner()
{
}

Entity * Spawner::createEntity()
{
	Entity* entity = spawnEntity->instantiate();
	strategy->configureParticle(*entity);
	int particleLifeTime;
	if (maxLifeTime != 0) {
		particleLifeTime = rand() % maxLifeTime + minLifeTime;
	}
	else {
		particleLifeTime = minLifeTime;
	}
	entity->setLifeTime(particleLifeTime);
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
