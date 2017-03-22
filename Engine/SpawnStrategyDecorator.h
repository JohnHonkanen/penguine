#pragma once
#include "AbstractSpawnStrategy.h"
class SpawnStrategyDecorator :
	public AbstractSpawnStrategy
{
private:
	AbstractSpawnStrategy *spawnStratgy;
public:
	SpawnStrategyDecorator();
	virtual ~SpawnStrategyDecorator();
	virtual vec3 spawnLocation(vec3 location);
};

