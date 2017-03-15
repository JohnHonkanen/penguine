#include "BallGenerator.h"



BallGenerator::BallGenerator(vec3 loc, vec3 force, TextureManager *textureManager, Shader *program):ParticleDecorator(new BaseParticle(nullptr))
{
	BallGenerator::emitter = new StaticEntity();
	BallGenerator::emitter->transform.setPosition(loc);
	BallGenerator::textureManager = textureManager;
	BallGenerator::program = program;
	BallGenerator::force = force;
	BallGenerator::spawn = new ConeSpawn(emitter, vec3(0,10,0), 1.0f);
}


BallGenerator::~BallGenerator()
{
}

void BallGenerator::init()
{
	ParticleDecorator::init();
	for (int i = 0; i < 30; i++) {
		generateBall();
	}
	spawnClock.startClock();
	spawnClock.setDelay(300);
}

void BallGenerator::update(float ts)
{
	stack<int> expiredParticles;
	spawnClock.updateClock();
	ParticleDecorator::update(ts);
	this->spawn->update(ts);
	for (int i = 0; i < BallGenerator::balls.size(); i++) {
		if (BallGenerator::balls[i]->clock.alarm()) {
			float alpha = BallGenerator::balls[i]->strategy->getAlpha();
			alpha -= 0.01f;
			BallGenerator::balls[i]->transform.scale(0.99f);
			BallGenerator::balls[i]->strategy->setAlpha(alpha);
			if(BallGenerator::balls[i]->strategy->getAlpha() <= 0.0f)
				expiredParticles.push(i);
			else {
				BallGenerator::balls[i]->update(ts);
			}
		}else{
			BallGenerator::balls[i]->update(ts);
		}
		
	}
	while (!expiredParticles.empty()) {
		if (expiredParticles.top() < BallGenerator::balls.size()) {
			delete BallGenerator::balls[expiredParticles.top()];
			BallGenerator::balls[expiredParticles.top()] = BallGenerator::balls.back();
			BallGenerator::balls.pop_back();
		}
		expiredParticles.pop();
		
	}
	if (spawnClock.alarm()) {
		for (int i = 0; i < 30; i++) {
			generateBall();
		}
		spawnClock.resetClock();
	}
}

void BallGenerator::render()
{
	for (int i = 0; i < BallGenerator::balls.size(); i++) {
		BallGenerator::balls[i]->render();
	}
	ParticleDecorator::render();
	
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
	DynamicEntity *dynamicEntity = new DynamicEntity(1500);
	BallGenerator::spawn->setEntity(dynamicEntity);
	BallGenerator::spawn->init();
	vec3 at = vec3(0,10.0f,-10.0f);
	vec3 shootForce = at - dynamicEntity->transform.getPosition();
	shootForce *= (rand() % 100) * 0.1f + 10.0f;
	dynamicEntity->setMovement(new Shoot(dynamicEntity, shootForce));
	dynamicEntity->transform.scale((rand() % 100) *0.01f + 0.3f);
	dynamicEntity->alpha = 0.5f;
	
	string type = "smoke";
	
	SpriteRenderer *sprite = new SpriteRenderer("smoke.png", type, textureManager, &dynamicEntity->transform, program); // Set-up Sprite GraphicsHandler
	sprite->init(); // Initialize Sprite GraphicsHandler

	dynamicEntity->setRenderingStrategy(sprite);
	dynamicEntity->init();
	dynamicEntity->strategy->setAlpha((rand() % 50) *0.01f);
	BallGenerator::balls.push_back(dynamicEntity);
}
