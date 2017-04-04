#include "ParticleFactory.h"

ParticleFactory::ParticleFactory()
{
}

Particle * ParticleFactory::makeParticle(int choice)
{
	if (choice == 1) {
		return createSingle(); //choice 1 particle;
	}
	
	if (choice == 2) {
		return 0; //choice 2particle;
	}
}

Particle * ParticleFactory::createSingle()
{
	cout << "particle 1 selected" << endl;

	Sprite *sprite = new Sprite("particle", textureManager);

	SingleParticle *particle = new SingleParticle(nullptr, new StaticEntity(), sprite, new SingleSpawn(), new Shoot(vec3(0, 0, 0)));
	particle->init();

	return particle;
}

void ParticleFactory::setTextureManager(TextureManager * textureManager)
{
	ParticleFactory::textureManager = textureManager;
}
