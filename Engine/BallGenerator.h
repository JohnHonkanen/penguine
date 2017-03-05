#pragma once
#include <vector>
#include "StaticEntity.h"
#include "DynamicEntity.h"
#include "BaseParticle.h"
#include "ParticleDecorator.h"
#include "Sprite.h"
#include "EmptyRenderable.h"
#include "Spawn.h"
#include "SingleSpawn.h"
#include "Shoot.h"

using namespace std;
class BallGenerator :
	public ParticleDecorator
{
private:
	StaticEntity *emitter;
	DynamicEntity *entity;
	Spawn *spawn;
public:
	BallGenerator(vec3 loc, vec3 force);
	virtual ~BallGenerator();
	void init();
	void update(float ts);
	void render(Renderer *r);
	void destroy();
};

