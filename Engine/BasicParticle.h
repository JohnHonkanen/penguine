#pragma once
#include "ParticleDecorator.h"
#include "Spawner.h"
#include "DynamicEntity.h"
#include "Shapes.h"
class BasicParticle :
	public ParticleDecorator
{
private:
	Entity *particle;
	Shapes *particleShape;
	Spawner *spawn;
	Movement *particleMovement;
	int minLife;
	int maxLife;
public:
	BasicParticle(Particle *p, Entity *emitter, Shapes *shape, Spawner *spawn);
	~BasicParticle();
	void init();
	void update(float ts);
	void render(Renderer *renderer);
	void destroy();
};
