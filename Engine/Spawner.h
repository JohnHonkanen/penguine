#pragma once
#include "AbstractSpawnStrategy.h"
#include "Entity.h"
class Spawner
{
protected:
	AbstractSpawnStrategy *strategy;
	Entity *spawnEntity;
public:
	Spawner();
	virtual ~Spawner();
	virtual vec3 spawnLocation(vec3 initialLoc);
	virtual Entity *createEntity();
	void setSpawnStrategy(AbstractSpawnStrategy *strategy);
	void setSpawnEntity(Entity *spawnEntity);
};

