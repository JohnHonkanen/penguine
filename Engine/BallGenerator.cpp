#include "BallGenerator.h"



BallGenerator::BallGenerator(vec3 loc, vec3 force, TextureManager *textureManager, Shader *program):ParticleDecorator(new BaseParticle(nullptr))
{
	BallGenerator::emitter = new StaticEntity();
	BallGenerator::emitter->transform.setPosition(loc);
	DynamicEntity *dynamicEntity = new DynamicEntity();
	dynamicEntity->setMovement(new Shoot(dynamicEntity, force));
	dynamicEntity->transform.scale(0.1f);
	SpriteRenderer *sprite = new SpriteRenderer("container.jpg", "container", textureManager, &dynamicEntity->transform, program); // Set-up Sprite Renderer
	sprite->init(); // Initialize Sprite Renderer
	
	dynamicEntity->setRenderingStrategy(sprite);
	this->entity = dynamicEntity;
	this->spawn = new SingleSpawn(emitter, entity);
}


BallGenerator::~BallGenerator()
{
}

void BallGenerator::init()
{
	ParticleDecorator::init();
	this->spawn->init();
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
