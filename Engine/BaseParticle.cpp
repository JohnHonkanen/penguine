#include "BaseParticle.h"

BaseParticle::BaseParticle(Entity *e)
{
	this->entity = entity;
}

BaseParticle::~BaseParticle()
{
}

void BaseParticle::init()
{
}

void BaseParticle::render(Renderer * r)
{
}

void BaseParticle::update(float ts)
{
}

void BaseParticle::destroy()
{
	delete spawn;
	delete entity;
}
