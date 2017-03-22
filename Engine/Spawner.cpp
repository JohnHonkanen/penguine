#include "Spawner.h"



Spawner::Spawner()
{
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
	return spawnEntity->instantiate();
}

void Spawner::setSpawnStrategy(AbstractSpawnStrategy * strategy)
{
	Spawner::strategy = strategy;
}

void Spawner::setSpawnEntity(Entity * spawnEntity)
{
	Spawner::spawnEntity = spawnEntity;
}