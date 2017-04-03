#pragma once
#include "AbstractSpawnStrategy.h"
#include "Entity.h"
class LocationSpawnStrategy :
	public AbstractSpawnStrategy
{
private:
	vec3 location;
public:
	LocationSpawnStrategy(vec3 location = vec3(0));
	virtual ~LocationSpawnStrategy();
	void configureParticle(Entity &entity);
};

