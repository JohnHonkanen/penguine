#include "ParticleManager.h"

ParticleManager *ParticleManager::inst = nullptr;

ParticleManager::ParticleManager()
{
}

ParticleManager *ParticleManager::getManager()
{
	if (inst == nullptr)
		inst = new ParticleManager();

	return inst;
}

void ParticleManager::addParticle(Particle * p)
{
	particles.push_back(p);
}

vector<Particle*> ParticleManager::getParticles()
{
	return particles;
}

void ParticleManager::update(double dt)
{
	//Update
	for (int i = 0; i < particles.size(); i++) {
		particles[i]->update(dt);
	}
}

void ParticleManager::render(Renderer *renderer)
{
	//Render
	for (int i = 0; i < particles.size(); i++) {
		particles[i]->render(renderer);
	}
}


ParticleManager::~ParticleManager()
{
}
