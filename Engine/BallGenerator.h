#pragma once
#include <vector>
#include "StaticEntity.h"
#include "DynamicEntity.h"
#include "BaseParticle.h"
#include "ParticleDecorator.h"
#include "Sprite.h"
#include "SpriteRenderer.h"
#include "TextureManager.h"
#include "Spawn.h"
#include "Shader.h"
#include "SingleSpawn.h"
#include "Shoot.h"

using namespace std;
class BallGenerator :
	public ParticleDecorator
{
private:
	Entity *emitter;
	Entity *entity;
	Spawn *spawn;
public:
	BallGenerator(vec3 loc, vec3 force, TextureManager *textureManager, Shader *program);
	virtual ~BallGenerator();
	void init();
	void update(float ts);
	void render(Renderer *r);
	void destroy();

};

