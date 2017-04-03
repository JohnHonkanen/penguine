#include "SpawnStrategyDecorator.h"


SpawnStrategyDecorator::SpawnStrategyDecorator(AbstractSpawnStrategy * in_spawnStrategy)
{
	spawnStratgy = in_spawnStrategy;
}

SpawnStrategyDecorator::~SpawnStrategyDecorator()
{
}

void SpawnStrategyDecorator::configureParticle(Entity & entity)
{
	spawnStratgy->configureParticle(entity);
}
