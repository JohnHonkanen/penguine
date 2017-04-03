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
	void configureParticle(Entity &entity);
};

