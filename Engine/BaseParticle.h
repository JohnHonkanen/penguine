#pragma once
#include "Particle.h"
#include "Entity.h"
#include "Spawner.h"
class BaseParticle :
	public Particle
{
public:
	BaseParticle(Entity*);
	virtual ~BaseParticle();
	void init();
	void render();
	void update(float ts);
	void destroy();
	Entity *entity;
	Spawner *spawn;
};

