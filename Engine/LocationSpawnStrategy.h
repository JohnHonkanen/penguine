#pragma once
#include "AbstractSpawnStrategy.h"
#include "Entity.h"
class LocationSpawnStrategy :
	public AbstractSpawnStrategy
{
public:
	LocationSpawnStrategy();
	virtual ~LocationSpawnStrategy();
	vec3 spawnLocation(vec3 location);
};

