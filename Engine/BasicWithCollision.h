#pragma once
#include "Particle.h"
#include "BasicParticle.h"
#include "OutputConsoleCollision.h"
#include "AABBCollider.h"
class BasicWithCollision :
	public Particle
{
private:
	BasicParticle particle;
public:
	BasicWithCollision(Entity *emitter);
	~BasicWithCollision();
	void createParticle();
	void init();
	void update(float ts);
	void render(Renderer *renderer);
	void destroy();
};

