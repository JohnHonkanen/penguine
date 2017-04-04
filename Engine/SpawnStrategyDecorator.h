#pragma once
#include "AbstractSpawnStrategy.h"
class SpawnStrategyDecorator :
	public AbstractSpawnStrategy
{
private:
	AbstractSpawnStrategy *spawnStratgy;
public:
	SpawnStrategyDecorator(AbstractSpawnStrategy *spawnStrategy);
	virtual ~SpawnStrategyDecorator();
	virtual void configureParticle(Entity &entity);
};

