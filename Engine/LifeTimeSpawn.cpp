#include "LifeTimeSpawn.h"


LifeTimeSpawn::LifeTimeSpawn(AbstractSpawnStrategy * spawnStrategy, int in_min, int in_max): SpawnStrategyDecorator(spawnStrategy)
{
	min = in_min;
	max = in_max;
}

LifeTimeSpawn::~LifeTimeSpawn()
{
}

void LifeTimeSpawn::configureParticle(Entity & entity)
{
	int lifeTime;

	if (max <= 0) {
		lifeTime = min;
	}
	else {
		lifeTime = rand() % max + min;
	}

	entity.setLifeTime(lifeTime);

	SpawnStrategyDecorator::configureParticle(entity);
}
