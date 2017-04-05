#include "ParticleDecorator.h"

ParticleDecorator::ParticleDecorator(Particle * p, Entity * emitter): Particle(emitter)
{
	ParticleDecorator::p = p;
}

ParticleDecorator::~ParticleDecorator()
{
	delete p;
}

void ParticleDecorator::init()
{
	if(p != nullptr)
		p->init();
}

void ParticleDecorator::update(float ts)
{
	if (p != nullptr)
		p->update(ts);
}

void ParticleDecorator::render(Renderer * renderer)
{
	if (p != nullptr)
		p->render(renderer);
}

void ParticleDecorator::destroy()
{
}
