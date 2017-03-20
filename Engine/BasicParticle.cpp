#include "BasicParticle.h"


BasicParticle::BasicParticle(Particle * p, Entity * emitter, Shapes *shape, Spawn *spawn, Movement *movement, int minLifeTime, int maxLifeTime):ParticleDecorator(p, emitter)
{
	BasicParticle::particleShape = shape;
	BasicParticle::spawn = spawn;
	BasicParticle::particleMovement = movement;
	Particle::emitter = emitter;
	BasicParticle::minLife = minLifeTime;
	BasicParticle::maxLife = maxLifeTime;
}

BasicParticle::~BasicParticle()
{
	ParticleDecorator::destroy();
}

void BasicParticle::init()
{
	int particleLifeTime;
	if (BasicParticle::maxLife != 0) {
		particleLifeTime = rand() % BasicParticle::maxLife + BasicParticle::minLife;
	}
	else {
		particleLifeTime = 0;
	}

	particle = new DynamicEntity(particleShape->instantiate(), particleLifeTime);
	BasicParticle::spawn->setEmitter(Particle::emitter);
	particle->setMovement(BasicParticle::particleMovement);
	particle->transform.translate(BasicParticle::spawn->init()[3]);
	particle->init();
	ParticleDecorator::init();
}

void BasicParticle::update(float ts)
{
	if (BasicParticle::maxLife == 0) {
		particle->update(ts);
		ParticleDecorator::update(ts);
	}
	else {
		if (!BasicParticle::particle->expire()) {
			particle->update(ts);
			ParticleDecorator::update(ts);
		}
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
