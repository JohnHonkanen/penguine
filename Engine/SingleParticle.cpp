#include "SingleParticle.h"


SingleParticle::SingleParticle(Particle * p, Entity * emitter, Shapes *shape, Spawn *spawn, Movement *movement):ParticleDecorator(p, emitter)
{
	SingleParticle::particleShape = shape;
	SingleParticle::spawn = spawn;
	SingleParticle::particleMovement = movement;
	Particle::emitter = emitter;
}

SingleParticle::~SingleParticle()
{
	ParticleDecorator::destroy();
}

void SingleParticle::init()
{
	particle = new DynamicEntity(particleShape->instantiate(), 2000);
	SingleParticle::spawn->setEmitter(Particle::emitter);
	particle->setMovement(SingleParticle::particleMovement);
	particle->transform.translate(SingleParticle::spawn->init()[3]);
	particle->init();
	ParticleDecorator::init();
}

void SingleParticle::update(float ts)
{
	particle->update(ts);
	ParticleDecorator::update(ts);
}

void SingleParticle::render(Renderer * renderer)
{
	renderer->renderObject(particle->getShape());
	ParticleDecorator::render(renderer);
}

void SingleParticle::destroy()
{
	delete particle;
	delete spawn;
	delete particleMovement;
	delete this;
}
