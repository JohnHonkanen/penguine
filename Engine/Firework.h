#pragma once
#include <vector>
#include "Particle.h"
#include "BasicParticle.h"

using namespace std;
class Firework :
	public Particle
{
private:
	BasicParticle rocket;
	vector<BasicParticle> explosion;
	bool exploded = false;
	vec3 rocketForce;
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

