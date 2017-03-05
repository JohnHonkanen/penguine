#include "BallGenerator.h"



BallGenerator::BallGenerator(vec3 loc, vec3 force):ParticleDecorator(new BaseParticle(nullptr))
{
	//this->emitter->transform.setPosition(loc);
	this->entity = new DynamicEntity();
	this->entity->setRenderable(new Sprite(new EmptyRenderable(), &this->entity->transform));
	this->entity->setMovement(new Shoot(this->entity, force));
	this->spawn = new SingleSpawn(emitter, entity);
}


BallGenerator::~BallGenerator()
{
}

void BallGenerator::init()
{
	ParticleDecorator::init();
	//this->spawn->init();
	this->entity->init();
}

void BallGenerator::update(float ts)
{
	ParticleDecorator::update(ts);
	this->spawn->update(ts);
	this->entity->update(ts);
}

void BallGenerator::render(Renderer * r)
{
	ParticleDecorator::render(r);
	this->entity->render(r);
}

void BallGenerator::destroy()
{
	ParticleDecorator::destroy();
	delete entity;
	delete emitter;
	delete spawn;
	delete this;
}
