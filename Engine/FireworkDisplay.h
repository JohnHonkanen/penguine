#pragma once
#include <vector>
#include "Particle.h"
#include "Firework.h"
#include "Clock.h"
class FireworkDisplay :
	public Particle
{
private:
	vector<Firework> fireworks;
	Clock spawnTimer;
public:
	FireworkDisplay(Entity *emitter);
	~FireworkDisplay();

	void init();
	void update(float ts);
	void render(Renderer *renderer);
	void destroy();
};

