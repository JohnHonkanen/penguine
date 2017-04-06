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

