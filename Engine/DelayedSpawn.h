#pragma once
#include "SpawnStrategyDecorator.h"
class DelayedSpawn :
	public SpawnStrategyDecorator
{
private:
	int delayTime;
public:
	DelayedSpawn(AbstractSpawnStrategy *spawnStrategy, int delayTime);
	virtual ~DelayedSpawn();
	void configureParticle(Entity &entity);
};

