/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

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
