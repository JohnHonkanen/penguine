#pragma once
#include "Particle.h"
class ParticleDecorator :
	public Particle
{
private:
	Particle* p;
public:
	ParticleDecorator(Particle *p, Entity *emitter);
	virtual ~ParticleDecorator();
	virtual void init();
	virtual void update(float ts);
	virtual void render(Renderer *renderer);
	virtual void destroy();
};

