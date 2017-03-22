#include "SpawnStrategyDecorator.h"



SpawnStrategyDecorator::SpawnStrategyDecorator()
{
}


SpawnStrategyDecorator::~SpawnStrategyDecorator()
{
}

vec3 SpawnStrategyDecorator::spawnLocation(vec3 location)
{
	return spawnStratgy->spawnLocation(location);
}
