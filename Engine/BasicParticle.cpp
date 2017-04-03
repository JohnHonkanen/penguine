#include "BasicParticle.h"


BasicParticle::BasicParticle(Particle * p, Entity * emitter, Shapes *shape, Spawner *spawn):ParticleDecorator(p, emitter)
{
	BasicParticle::particleShape = shape;
	BasicParticle::spawn = spawn;
}

BasicParticle::~BasicParticle()
{
	ParticleDecorator::destroy();
}

void BasicParticle::init()
{

	particle = spawn->createEntity();
	ParticleDecorator::init();
}

void BasicParticle::update(float ts)
{
	if (!BasicParticle::particle->expire()) {
		particle->update(ts);
		ParticleDecorator::update(ts);
	}
}

void BasicParticle::render(Renderer * renderer)
{
	renderer->renderObject(particle->getShape());
	ParticleDecorator::render(renderer);
}

void BasicParticle::destroy()
{
	delete particle;
	delete spawn;
	delete particleMovement;
	delete this;
}
