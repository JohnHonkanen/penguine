/*

Name: Lars Anthony Palm

Student ID: B00294272

I declare that the following code was produced by Lars Anthony Palm, John Christopher Arnon Honkanen as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include <vector>
#include "Renderer.h"
#include "Particle.h"

using namespace std;
class ParticleManager
{
private:
	bool run = true;
	static ParticleManager *inst;
	vector<Particle*> particles;
	vector<Entity*> entityWithColliders;
	ParticleManager();
	~ParticleManager();
public:
	static ParticleManager *getManager();
	void addParticle(Particle *p);
	void addCollisionEntities(Entity *entity);
	vector<Particle*> getParticles();
	void update(double dt);
	void render(Renderer *renderer);
	void toggleRun();
};

