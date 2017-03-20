#pragma once
#include "ParticleDecorator.h"
#include "Spawn.h"
#include "DynamicEntity.h"
#include "Shapes.h"
class BasicParticle :
	public ParticleDecorator
{
private:
	Entity *particle;
	Shapes *particleShape;
	Spawn *spawn;
	Movement *particleMovement;
	int minLife;
	int maxLife;
public:
	BasicParticle(Particle *p, Entity *emitter, Shapes *shape, Spawn *spawn, Movement *movement, int minParticleLifeTimeMS = 0, int maxParticleLifeTimeMS = 0);
	~BasicParticle();
	void init();
	void update(float ts);
	void render(Renderer *renderer);
	void destroy();
};
