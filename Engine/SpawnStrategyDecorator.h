#pragma once
#include "AbstractSpawnStrategy.h"
class SpawnStrategyDecorator :
	public AbstractSpawnStrategy
{
protected:
	AbstractSpawnStrategy *spawnStratgy;
public:
	SpawnStrategyDecorator(AbstractSpawnStrategy *spawnStrategy);
	virtual ~SpawnStrategyDecorator();
	virtual void configureParticle(Entity &entity);
};

