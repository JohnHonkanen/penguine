#include "BallGenerator.h"



BallGenerator::BallGenerator(vec3 loc, vec3 force, TextureManager *textureManager, Shader *program):ParticleDecorator(new BaseParticle(nullptr))
{
	BallGenerator::emitter = new StaticEntity();
	BallGenerator::emitter->transform.setPosition(loc);
	BallGenerator::textureManager = textureManager;
	BallGenerator::program = program;
	BallGenerator::force = force;
	BallGenerator::spawn = new CircularSpawn(emitter, 1.0f, 15);
}


BallGenerator::~BallGenerator()
{
}

void BallGenerator::init()
{
	ParticleDecorator::init();
	for (int i = 0; i < 15; i++) {
		generateBall();
	}
	spawnClock.startClock();
	spawnClock.setDelay(1000);
}

void BallGenerator::update(float ts)
{
	spawnClock.updateClock();
	ParticleDecorator::update(ts);
	this->spawn->update(ts);
	for (int i = 0; i < BallGenerator::balls.size(); i++) {
		BallGenerator::balls[i]->update(ts);
	}
	if (spawnClock.alarm()) {
		for (int i = 0; i < 15; i++) {
			generateBall();
		}
		spawnClock.resetClock();
	}
}

void BallGenerator::render(Renderer * r)
{
	for (int i = 0; i < BallGenerator::balls.size(); i++) {
		BallGenerator::balls[i]->render(r);
	}
	ParticleDecorator::render(r);
	
}

void BallGenerator::destroy()
{
	ParticleDecorator::destroy();
	for (int i = 0; i < BallGenerator::balls.size(); i++) {
		delete BallGenerator::balls[i];
	}
	delete emitter;
	delete spawn;
	delete this;
}

void BallGenerator::generateBall()
{
	DynamicEntity *dynamicEntity = new DynamicEntity();
	BallGenerator::spawn->setEntity(dynamicEntity);
	BallGenerator::spawn->init();
	float randForce = rand() % 1500;
	vec2 circPoint = dynamic_cast<CircularSpawn*>(spawn)->circularPoint * randForce;
	vec3 shootForce = vec3(circPoint, 0.0f);
	dynamicEntity->setMovement(new Shoot(dynamicEntity, shootForce));
	SpriteRenderer *sprite = new SpriteRenderer("container.jpg", "container", textureManager, &dynamicEntity->transform, program); // Set-up Sprite Renderer
	sprite->init(); // Initialize Sprite Renderer

	dynamicEntity->setRenderingStrategy(sprite);
	dynamicEntity->init();
	BallGenerator::balls.push_back(dynamicEntity);
}
