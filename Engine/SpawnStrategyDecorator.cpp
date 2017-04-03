#include "SpawnStrategyDecorator.h"



SpawnStrategyDecorator::SpawnStrategyDecorator()
{
}


SpawnStrategyDecorator::~SpawnStrategyDecorator()
{
}

void SpawnStrategyDecorator::configureParticle(Entity & entity)
{
	spawnStratgy->configureParticle(entity);
}
