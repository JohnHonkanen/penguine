#include "ParticleDecorator.h"

ParticleDecorator::ParticleDecorator(Particle * p)
{
	this->p = p;
}

ParticleDecorator::~ParticleDecorator()
{
}

void ParticleDecorator::init()
{
	p->init();
}

void ParticleDecorator::update(float ts)
{
	p->update(ts);
}

void ParticleDecorator::render(Renderer * r)
{
	p->render(r);
}

void ParticleDecorator::destroy()
{
	delete p;
	delete this;
}
