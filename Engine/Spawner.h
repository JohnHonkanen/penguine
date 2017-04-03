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
	Spawner(int minLifeTime = 0, int maxLifeTime = 0);
	virtual ~Spawner();
	virtual vec3 spawnLocation(vec3 initialLoc);
	virtual Entity *createEntity();
	void setSpawnStrategy(AbstractSpawnStrategy *strategy);
	void setSpawnEntity(Entity *spawnEntity);
	void setEmitterEntity(Entity *emitter);
	void setMovementStrategy(Movement *movement);
};

