#pragma once
#include <vector>
#include "Particle.h"

using namespace std;
class Firework :
	public Particle
{
private:
	vector<Entity*> explosion;
	Entity* rocket;
	bool exploded = false;
public:
	Firework(Entity *emitter);
	~Firework();
	void shootRocket();
	void explodeRocket();

	void init();
	void update(float ts);
	void render(Renderer *renderer);
	void destroy();
};

