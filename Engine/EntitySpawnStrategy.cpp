#include "EntitySpawnStrategy.h"



EntitySpawnStrategy::EntitySpawnStrategy(AbstractSpawnStrategy *strategy, Entity *in_entity): SpawnStrategyDecorator(strategy)
{
	entity = in_entity;
}


EntitySpawnStrategy::~EntitySpawnStrategy()
{
}

void EntitySpawnStrategy::configureParticle(Entity & in_entity)
{
	in_entity.transform.translate(entity->transform.getPosition());
	SpawnStrategyDecorator::configureParticle(in_entity);
}
