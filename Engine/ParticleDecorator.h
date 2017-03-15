#pragma once
#include "Particle.h"
class ParticleDecorator :
	public Particle
{
private:
	Particle* p;
public:
	ParticleDecorator(Particle *p);
	virtual ~ParticleDecorator();
	void init();
	void update(float ts);
	void render(GraphicsHandler *r);
	void destroy();
};

