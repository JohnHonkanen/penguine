#pragma once
#include <vector>
#include <stack>
#include <stdlib.h>
#include "StaticEntity.h"
#include "DynamicEntity.h"
#include "BaseParticle.h"
#include "ParticleDecorator.h"
#include "Sprite.h"
#include "SpriteRenderer.h"
#include "TextureManager.h"
#include "Spawn.h"
#include "Shader.h"
#include "ConeSpawn.h"
#include "Shoot.h"
#include "Clock.h"

using namespace std;
class BallGenerator :
	public ParticleDecorator
{
private:
	Entity *emitter;
	Entity *entity;
	vector<Entity*> balls;
	Spawn *spawn;
	TextureManager *textureManager;
	Shader *program;
	vec3 force;
	Clock spawnClock;
public:
	BallGenerator(vec3 loc, vec3 force, TextureManager *textureManager, Shader *program);
	virtual ~BallGenerator();
	void init();
	void update(float ts);
	void render(GraphicsHandler *r);
	void destroy();

	void generateBall();

};

