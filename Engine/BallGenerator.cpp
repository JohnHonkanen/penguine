#include "BallGenerator.h"



BallGenerator::BallGenerator(vec3 loc, vec3 force, TextureManager *textureManager, Shader *program):ParticleDecorator(new BaseParticle(nullptr))
{
	//this->emitter->transform.setPosition(loc);
	this->entity = new DynamicEntity();
	SpriteRenderer sprite("container.jpg", "container", textureManager, &this->entity->transform, program); // Set-up Sprite Renderer
	sprite.init(); // Initialize Sprite Renderer
	this->entity->setRenderingStrategy(&sprite);
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
	this->entity->render(r);
	ParticleDecorator::render(r);
	
}

void BallGenerator::destroy()
{
	ParticleDecorator::destroy();
	delete entity;
	delete emitter;
	delete spawn;
	delete this;
}
