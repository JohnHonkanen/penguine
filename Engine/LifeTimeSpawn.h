#pragma once
#include "SpawnStrategyDecorator.h"
class LifeTimeSpawn :
	public SpawnStrategyDecorator
{
private:
	int min;
	int max;
public:
	LifeTimeSpawn(AbstractSpawnStrategy *spawnStrategy, int min, int max = 0);
	~LifeTimeSpawn();
	void configureParticle(Entity &entity);
};

