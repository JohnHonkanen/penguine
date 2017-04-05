#pragma once
#include "ParticleDecorator.h"
#include "Spawner.h"
#include "DynamicEntity.h"
#include "Shapes.h"
class BasicParticle :
	public ParticleDecorator
{
private:
	
	Shapes *particleShape;
	Spawner *spawn;
	Movement *particleMovement;
public:
	BasicParticle(Particle *p, Entity *emitter, Shapes *shape, Spawner *spawn);
	~BasicParticle();
	void init();
	void update(float ts);
	void render(Renderer *renderer);
	void destroy();

	Entity *particle;
};
