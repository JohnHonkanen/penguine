#include "Spawner.h"



Spawner::Spawner(int in_minLifeTime, int in_maxLifeTime)
{
	minLifeTime = in_minLifeTime;
	maxLifeTime = in_maxLifeTime;
}


Spawner::~Spawner()
{
}

vec3 Spawner::spawnLocation(vec3 initialLoc)
{
	return strategy->spawnLocation(initialLoc);
}

Entity * Spawner::createEntity()
{
	Entity* entity = spawnEntity->instantiate();
	int particleLifeTime;
	if (maxLifeTime != 0) {
		particleLifeTime = rand() % maxLifeTime + minLifeTime;
	}
	else {
		particleLifeTime = minLifeTime;
	}
	entity->setLifeTime(particleLifeTime);
	entity->transform.translate(spawnLocation(emitter->transform.getPosition()));
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
