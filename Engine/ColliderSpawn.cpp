#include "ColliderSpawn.h"



ColliderSpawn::ColliderSpawn(AbstractSpawnStrategy *spawnStrategy, Collider *in_collider, CollisionStrategy *in_strategy): SpawnStrategyDecorator(spawnStrategy)
{
	collider = in_collider;
	strategy = in_strategy;
}


ColliderSpawn::~ColliderSpawn()
{
}

void ColliderSpawn::configureParticle(Entity & entity)
{
	entity.setCollider(collider->instantiate());
	entity.setCollisionStrategy(strategy->instantiate());
	ParticleManager::getManager()->addCollisionEntities(&entity);
	SpawnStrategyDecorator::configureParticle(entity);
}
