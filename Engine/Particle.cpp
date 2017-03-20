#include "Particle.h"



Particle::Particle()
{
}


Particle::Particle(Entity * emitter)
{
	Particle::emitter = emitter;
}

Particle::~Particle()
{
}
