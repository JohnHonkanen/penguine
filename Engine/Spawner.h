#pragma once
#include "AbstractSpawnStrategy.h"
#include "Entity.h"
class Spawner
{
protected:
	AbstractSpawnStrategy *strategy;
	Movement *movement;
	Entity *spawnEntity;
	Entity *emitter;
	int minLifeTime;
	int maxLifeTime;
public:
	Spawner();
	virtual ~Spawner();
	virtual Entity *createEntity();
	void setSpawnStrategy(AbstractSpawnStrategy *strategy);
	void setSpawnEntity(Entity *spawnEntity);
	void setEmitterEntity(Entity *emitter);
	void setMovementStrategy(Movement *movement);
};

