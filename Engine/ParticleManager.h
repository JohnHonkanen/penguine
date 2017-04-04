#pragma once
#include <vector>
#include "Renderer.h"
#include "Particle.h"

using namespace std;
class ParticleManager
{
private:
	static ParticleManager *inst;
	vector<Particle*> particles;
	ParticleManager();
	~ParticleManager();
public:
	static ParticleManager *getManager();
	void addParticle(Particle *p);
	vector<Particle*> getParticles();
	void update(double dt);
	void render(Renderer *renderer);
};

