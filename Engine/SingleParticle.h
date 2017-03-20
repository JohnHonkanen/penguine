#pragma once
#include "ParticleDecorator.h"
#include "Spawn.h"
#include "DynamicEntity.h"
#include "Shapes.h"
class SingleParticle :
	public ParticleDecorator
{
private:
	Entity *particle;
	Shapes *particleShape;
	Spawn *spawn;
	Movement *particleMovement;
public:
	SingleParticle(Particle *p, Entity *emitter, Shapes *shape, Spawn *spawn, Movement *movement);
	~SingleParticle();
	void init();
	void update(float ts);
	void render(Renderer *renderer);
	void destroy();
};

