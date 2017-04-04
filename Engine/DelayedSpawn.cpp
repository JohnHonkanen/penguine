#include "DelayedSpawn.h"



DelayedSpawn::DelayedSpawn(AbstractSpawnStrategy *spawnStrategy, int in_delayTime) : SpawnStrategyDecorator(spawnStrategy)
{
	delayTime = in_delayTime;
}


DelayedSpawn::~DelayedSpawn()
{
}

void DelayedSpawn::configureParticle(Entity & entity)
{
	entity.setDelayTime(delayTime);
	SpawnStrategyDecorator::configureParticle(entity);
}
