#pragma once
#include "AbstractSpawner.h"
class SpawnerDecorator :
	public AbstractSpawner
{
private:
	AbstractSpawner *spawner;
public:
	SpawnerDecorator();
	virtual ~SpawnerDecorator();
	mat4 init();
	mat4 update(float ts);
	bool spawn();
	Entity *createEntity();
};

