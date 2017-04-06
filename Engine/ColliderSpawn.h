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

