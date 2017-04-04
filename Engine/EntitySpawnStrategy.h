#pragma once
#include "Entity.h"
#include "SpawnStrategyDecorator.h"
class EntitySpawnStrategy :
	public SpawnStrategyDecorator
{
private:
	Entity *entity;
public:
	EntitySpawnStrategy(AbstractSpawnStrategy *strategy, Entity *entity);
	virtual ~EntitySpawnStrategy();
	void configureParticle(Entity &entity);
};

