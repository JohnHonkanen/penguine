#pragma once
#include "Particle.h"
#include "Entity.h"
#include "Spawn.h"
class BaseParticle :
	public Particle
{
public:
	BaseParticle(Entity*);
	virtual ~BaseParticle();
	void init();
	void render(Renderer *r);
	void update(float ts);
	void destroy();
	Entity *entity;
	Spawn *spawn;
};

