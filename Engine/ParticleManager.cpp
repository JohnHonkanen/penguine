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

void ParticleManager::addCollisionEntities(Entity * entity)
{
	entityWithColliders.push_back(entity);
}

vector<Particle*> ParticleManager::getParticles()
{
	return particles;
}

void ParticleManager::update(double dt)
{
	//Update
	if (run) {
		//Check Collision
		for (int i = 0; i < entityWithColliders.size(); i++) {
			for (int j = 0; j < entityWithColliders.size(); j++) {
				if (entityWithColliders.at(i)->getCollider()->checkCollision(entityWithColliders.at(j)->getCollider())) {
					entityWithColliders.at(i)->getCollider()->collided = true;
					entityWithColliders.at(j)->getCollider()->collided = true;
					entityWithColliders.at(i)->getCollider()->other = entityWithColliders.at(j)->getCollider();
					entityWithColliders.at(j)->getCollider()->other = entityWithColliders.at(i)->getCollider();

				}
			}
		}
		for (int i = 0; i < particles.size(); i++) {
			particles[i]->update(dt);
		}
	}
	
}

void ParticleManager::render(Renderer *renderer)
{
	//Render
	for (int i = 0; i < particles.size(); i++) {
		particles[i]->render(renderer);
	}
}

void ParticleManager::toggleRun()
{
	run = !run;
}


ParticleManager::~ParticleManager()
{
}
