/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

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
