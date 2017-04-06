/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include "SpawnStrategyDecorator.h"
#include "Collider.h"
#include "CollisionStrategy.h"
#include "ParticleManager.h"
class ColliderSpawn :
	public SpawnStrategyDecorator
{
private:
	Collider *collider;
	CollisionStrategy *strategy;
public:
	ColliderSpawn(AbstractSpawnStrategy *spawnStrategy, Collider *collider, CollisionStrategy *strategy);
	~ColliderSpawn();
	void configureParticle(Entity &entity);
};

