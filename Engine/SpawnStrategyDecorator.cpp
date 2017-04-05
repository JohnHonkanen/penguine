#include "SpawnStrategyDecorator.h"


SpawnStrategyDecorator::SpawnStrategyDecorator(AbstractSpawnStrategy * in_spawnStrategy)
{
	spawnStratgy = in_spawnStrategy;
}

SpawnStrategyDecorator::~SpawnStrategyDecorator()
{
	delete spawnStratgy;
}

void SpawnStrategyDecorator::configureParticle(Entity & entity)
{
	spawnStratgy->configureParticle(entity);
}
