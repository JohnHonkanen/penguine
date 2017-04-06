/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

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

