#pragma once
#include "Renderer.h"
#include "Entity.h"
class Particle
{
protected:
	Entity *emitter;
public:
	Particle();
	Particle(Entity *emitter);
	virtual ~Particle();
	virtual void init() = 0;
	virtual void update(float ts) = 0;
	virtual void render(Renderer *renderer) = 0;
	virtual void destroy() = 0;
};

