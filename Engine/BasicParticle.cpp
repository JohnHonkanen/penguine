#include "BasicParticle.h"


BasicParticle::BasicParticle():Particle(nullptr)
{
}

BasicParticle::BasicParticle(Particle * p, Entity * emitter, Shapes *shape, Spawner *spawn):Particle(emitter)
{
	BasicParticle::particleShape = shape;
	BasicParticle::spawn = spawn;
}

BasicParticle::~BasicParticle()
{
}

void BasicParticle::init()
{

	particle = spawn->createEntity();
}

void BasicParticle::update(float ts)
{
	if (!BasicParticle::particle->expire()) {
		particle->update(ts);
	}

}

void BasicParticle::render(Renderer * renderer)
{
	if (particle->start()) {
		renderer->renderObject(particle->getShape());
	}
	
}

void BasicParticle::destroy()
{
	delete spawn;
	delete particleMovement;
	delete this;
}
